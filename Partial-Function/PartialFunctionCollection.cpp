#include "PartialFunctionCollection.h"

bool PartialFunctionCollection::isDefined(int32_t num) const
{
	for (int i = 0; i < size; i++) {
		if (!data[i]->isDefined(num)) {
			return false;
		}
	}
	return true;
}

PartialFunctionCollection::~PartialFunctionCollection()
{
	free();
}

void PartialFunctionCollection::free()
{
	for (int i = 0; i < size; i++) {
		delete data[i];
	}
	delete[] data;
}

void PartialFunctionCollection::copyFrom(const PartialFunctionCollection& other)
{
	size = other.size;

	data = new PartialFunction * [size];

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i]->clone();
	}
}

void PartialFunctionCollection::moveFrom(PartialFunctionCollection&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
}

PartialFunctionCollection::PartialFunctionCollection(PartialFunction** data, size_t size)
{
	this->data = data;
	this->size = size;
}

PartialFunctionCollection::PartialFunctionCollection(const PartialFunctionCollection& other)
{
	copyFrom(other);
}

PartialFunctionCollection::PartialFunctionCollection(PartialFunctionCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

PartialFunctionCollection& PartialFunctionCollection::operator=(const PartialFunctionCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PartialFunctionCollection& PartialFunctionCollection::operator=(PartialFunctionCollection&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
