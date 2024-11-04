#include "PartialFunction.h"
#pragma once

class PartialFunctionCollection : public PartialFunction//abstract class that wraps the functionality of the container, 
{                                                        //the operator() function is virtual because the logic is unique for the derived classes
protected:
	PartialFunction** data = nullptr;
	size_t size = 0;

	void free();
	void copyFrom(const PartialFunctionCollection& other);
	void moveFrom(PartialFunctionCollection&& other);
public:
	PartialFunctionCollection(PartialFunction** data, size_t size);//takes ownership

	PartialFunctionCollection() = default;
	PartialFunctionCollection(const PartialFunctionCollection& other);
	PartialFunctionCollection(PartialFunctionCollection&& other) noexcept;

	PartialFunctionCollection& operator=(const PartialFunctionCollection& other);
	PartialFunctionCollection& operator= (PartialFunctionCollection&& other) noexcept;

	bool isDefined(int32_t num) const override;

	~PartialFunctionCollection() override;//no clone function because the class is abstract and we can not make instances from this class
};

