#include "FuncObj1.h"

FuncObj1::FuncObj1(size_t N, int32_t* arr)
{
	for (int i = 0; i < N; i++) {
		data[i].setFirst(arr[i]);
	}

	for (int i = N; i < 2*N; i++) {
		data[i - N].setSecond(arr[i]);
	}

	count = N;
}

Pair<bool, int32_t> FuncObj1::operator()(int32_t num) const
{
	for (int i = 0; i < count; i++) {
		if (data[i].getFirst() == num) {
			return Pair<bool, int32_t>(true,data[i].getSecond());
		}
	}
	return Pair<bool, int32_t>(false, -1);
}
