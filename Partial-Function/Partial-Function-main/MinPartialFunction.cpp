#include "MinPartialFunction.h"

MinPartialFunction::MinPartialFunction(PartialFunction** data, size_t size) : PartialFunctionCollection(data, size)
{}

int32_t MinPartialFunction::operator()(int32_t num) const
{
    {
        int32_t min = INT32_MAX;

        for (int i = 0; i < size; i++) {
            if (!data[i]->isDefined(num)) {

                if (!isDefined(num)) {
                    throw std::logic_error("Number is not defined.");
                }
            }
            int32_t res = data[i]->operator()(num);
            if (res < min) {
                min = res;
            }
        }
        return min;
    }
}

PartialFunction* MinPartialFunction::clone() const
{
    return new MinPartialFunction(*this);
}
