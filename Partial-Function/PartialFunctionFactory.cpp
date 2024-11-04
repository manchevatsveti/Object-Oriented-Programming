#include "PartialFunctionFactory.h"


PartialFunction* PartialFunctionFactory::readFromFile(const char* file) 
{
    std::ifstream ifs(file, std::ios::binary);

    if (!ifs.is_open()) {
        throw std::invalid_argument("Invalid filename.");
    }

    return readFromFile(ifs);
}

PartialFunction* PartialFunctionFactory::readFromFile(std::ifstream& ifs) 
{
    uint16_t N;
    uint16_t T;

    ifs.read((char*)&N, sizeof(uint16_t));
    ifs.read((char*)&T, sizeof(uint16_t));

    if(!isNValid(N)){
        throw std::invalid_argument("Invalid N. Must be less than 32.");
    }

    return factory(N, T,ifs);
}

bool PartialFunctionFactory::isNValid(uint16_t num) 
{
    return num <= FunctionConstants::MAX_DATA_LEN;
}

int32_t* PartialFunctionFactory::readArrayfromFile(std::ifstream& ifs, size_t size) 
{
    int32_t* arr = new int32_t[size];
    ifs.read((char*)arr, size * sizeof(int32_t));

    return arr;
}

static unsigned fileSize(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        return 0;
    }

    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::end);

    unsigned int count = ifs.tellg();

    ifs.clear();
    ifs.seekg(currentPosition);
    return count;
}

MyString* PartialFunctionFactory::readArrayOfStrings(std::ifstream& ifs, size_t size) {
    unsigned charsCount = fileSize(ifs);

    char* charDump = new char[charsCount];
    ifs.read(charDump, charsCount);

    MyString* result = new MyString[size];
    unsigned offsetFromBeginning = 0;
    for (int i = 0; i < size; i++) {
        result[i] = MyString(charDump + offsetFromBeginning); // reads the characters up to the first \0
        offsetFromBeginning += result[i].getSize() + 1; // then we offset for the next string, accounting for the \0
    }
    return result;
}


PartialFunction** PartialFunctionFactory::readFunctionsFromFiles(const MyString* data, size_t size) 
{
    PartialFunction** arr = new PartialFunction * [size];

    for (size_t i = 0; i < size; i++) {
        arr[i] = readFromFile(data[i].c_str());
    }
    return arr;
}

PartialFunction* PartialFunctionFactory::factory(uint16_t N, uint16_t T, std::ifstream& ifs) 
{
    switch (T) {
        case 0: {
            int32_t* arr = readArrayfromFile(ifs, 2*N);
            FuncObj1 func(N, arr);
            delete[] arr;//we took the data and delete it
            return new PartialFunctionByCriteria<FuncObj1>(func);
        }
        case 1: {

            int32_t* arr = readArrayfromFile(ifs, N);
            FuncObj2 func(N, arr);
            delete[] arr;//we took the data and delete it
            return new PartialFunctionByCriteria<FuncObj2>(func);
        }
        case 2: {

            int32_t* arr = readArrayfromFile(ifs, N);
            FuncObj3 func(N, arr);
            delete[] arr;//we took the data and delete it
            return new PartialFunctionByCriteria<FuncObj3>(func);
        }
        case 3: {
            MyString* data = readArrayOfStrings(ifs, N);
            PartialFunction** arr = readFunctionsFromFiles(data, N);
            delete[] data;
            return new MaxPartialFunction(arr, N);//we don't delete arr here because the collection takes the ownership and handles it
        }
        case 4: {

            MyString* data = readArrayOfStrings(ifs, N);
            PartialFunction** arr = readFunctionsFromFiles(data, N);
            delete[] data;
            return new MinPartialFunction(arr, N);//we don't delete arr here because the collection takes the ownership and handles it
        }
   }
}
