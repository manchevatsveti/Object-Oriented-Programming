#include "FunctionObject.h"
#pragma once

class FuncObj3 : public FunctionObject
{
public:
	FuncObj3(size_t N, int32_t* arr);
	Pair<bool, int32_t> operator()(int32_t num) const override;
};

