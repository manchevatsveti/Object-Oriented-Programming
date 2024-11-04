#include "FuncObj2.h"

FuncObj2::FuncObj2(size_t N, int32_t* arr)
{
	for (int i = 0; i < N; i++) {
		data[i].setFirst(arr[i]);
		data[i].setSecond(-1);
	}
	count = N;
}

Pair<bool, int32_t> FuncObj2::operator()(int32_t num) const
{
	for (int i = 0; i < count; i++) {
		if (data[i].getFirst() == num) {
			return Pair<bool, int32_t>(false, -1);
		}
	}
	return Pair<bool, int32_t>(true,num);
}
