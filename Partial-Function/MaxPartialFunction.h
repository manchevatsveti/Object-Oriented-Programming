#include "PartialFunctionCollection.h"
#pragma once

class MaxPartialFunction : public PartialFunctionCollection
{

public:
	MaxPartialFunction(PartialFunction** data, size_t size);
	int32_t operator()(int32_t num) const override;
	PartialFunction* clone() const override;
};

