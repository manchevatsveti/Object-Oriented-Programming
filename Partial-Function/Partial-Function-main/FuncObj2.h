#include "FunctionObject.h"
#pragma once

class FuncObj2 : public FunctionObject
{
public:
	FuncObj2(size_t N, int32_t* arr);
	Pair<bool, int32_t> operator()(int32_t num) const override;
};

