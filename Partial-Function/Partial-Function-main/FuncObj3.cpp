#include "FuncObj3.h"

FuncObj3::FuncObj3(size_t N, int32_t* arr)
{
	for (int i = 0; i < N; i++) {
		data[i].setFirst(arr[i]);
		data[i].setSecond(1);
	}
	count = N;
}

Pair<bool, int32_t> FuncObj3::operator()(int32_t num) const
{
	for (int i = 0; i < count; i++) {
		if (data[i].getFirst() == num) {
			return Pair<bool, int32_t>(true, 1);
		}
	}
	return Pair<bool, int32_t>(true, 0);
}
