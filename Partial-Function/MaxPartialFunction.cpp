#include "MaxPartialFunction.h"

MaxPartialFunction::MaxPartialFunction(PartialFunction** data, size_t size) : PartialFunctionCollection(data,size)
{}

int32_t MaxPartialFunction::operator()(int32_t num) const
{
    int32_t max = INT32_MIN;

    for (int i = 0; i < size; i++) {
        if (!data[i]->isDefined(num)) {

            if (!isDefined(num)) {
                throw std::logic_error("Number is not defined.");
            }
        }
        int32_t res = data[i]->operator()(num);
        if ( res > max) {
            max = res;
        }
    }
    return max;
}

PartialFunction* MaxPartialFunction::clone() const
{
    return new MaxPartialFunction(*this);
}
