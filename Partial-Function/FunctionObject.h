#include "Pair.hpp"
#include <iostream>
#pragma once

namespace FunctionConstants{
	const int MAX_DATA_LEN = 32;
}

class FunctionObject
{
protected:
	Pair<int32_t, int32_t> data[FunctionConstants::MAX_DATA_LEN];
	size_t count = 0;

public:
	virtual Pair<bool, int32_t> operator()(int32_t num) const = 0;
};

