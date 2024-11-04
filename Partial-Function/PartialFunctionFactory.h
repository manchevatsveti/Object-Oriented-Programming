#include "PartialFunction.h"
#include "PartialFunctionByCriteria.hpp"
#include "MaxPartialFunction.h"
#include "MinPartialFunction.h"
#include "FuncObj1.h"
#include "FuncObj2.h"
#include "FuncObj3.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#pragma once


class PartialFunctionFactory
{
	static bool isNValid(uint16_t num);

	static int* readArrayfromFile(std::ifstream& ifs,size_t size) ;
	static MyString* readArrayOfStrings(std::ifstream& ifs, size_t size) ;
	static PartialFunction** readFunctionsFromFiles(const MyString* data,size_t size) ;

	static PartialFunction* readFromFile(std::ifstream& ifs) ;
	static PartialFunction* factory(uint16_t N, uint16_t T, std::ifstream& ifs);

public:
	static PartialFunction* readFromFile(const char* file) ;
};

