#include "PartialFunctionCollection.h"
#pragma once

class MinPartialFunction : public PartialFunctionCollection
{

public:
	MinPartialFunction(PartialFunction** data, size_t size);
	int32_t operator()(int32_t num) const override;
	PartialFunction* clone() const override;
};

