#include "PartialFunction.h"
#pragma once

template <typename T>
class PartialFunctionByCriteria : public PartialFunction {

	T function;

public:
	PartialFunctionByCriteria(const T& func);
	bool isDefined(int32_t num) const override;
	int32_t operator()(int32_t num) const override;
	PartialFunction* clone() const override;
};


template <typename T>
PartialFunctionByCriteria<T>::PartialFunctionByCriteria(const T& func) : function(func) {}

template <typename T>
bool PartialFunctionByCriteria<T>::isDefined(int32_t num) const {
	
	return function(num).getFirst();
}

template <typename T>
int32_t PartialFunctionByCriteria<T>::operator()(int32_t num) const {

	if (!isDefined(num)) {
		throw std::logic_error("Number is not defined.");
	}

	return function(num).getSecond();
}

template <typename T>
PartialFunction* PartialFunctionByCriteria<T>::clone() const{
	return new PartialFunctionByCriteria(*this);
}
