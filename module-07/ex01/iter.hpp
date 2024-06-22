#pragma once

template <typename T, typename R>
void iter(T *arr, int length, R f)
{
	for (int i = 0; i < length; i++) {
		f(arr[i]);
	}
}
