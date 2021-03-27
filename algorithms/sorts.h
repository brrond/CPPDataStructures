#include <algorithm>
#include <vector>

using std::vector;
using std::swap;

template <typename _It_Ty, typename _Cmp_Func>
void insertion_sort(_It_Ty b, _It_Ty e, _Cmp_Func _func)
{
	for (int i = 1; i < (e - b); i++)
	{
		int curr = i;
		while (curr && _func(*(b + curr), *(b + curr - 1)))
		{
			swap(*(b + curr), *(b + curr - 1));
			curr--;
		}
	}
}

template <typename _It_Ty>
void insertion_sort(_It_Ty b, _It_Ty e)
{
	insertion_sort(b, e, [](auto a, auto b) {return a < b; });
}

template <typename _Ty>
void insertion_sort(vector<_Ty> &arr)
{
	auto b = arr.begin();
	auto e = arr.end();
	for (int i = 1; i < (e - b); i++)
	{
		int curr = i;
		while (curr && (*(b + curr) < *(b + curr - 1)))
		{
			swap(*(b + curr), *(b + curr - 1));
			curr--;
		}
	}
}

template <typename _It_Ty, typename _Cmp_Func>
void shell_sort(_It_Ty b, _It_Ty e, _Cmp_Func _func)
{
	for (int d = (e - b) / 2; d != 0; d /= 2)
	{
		for (int i = d; i != (e - b); i++)
		{
			for (int j = i; (b + j) - b >= d; j -= d)
			{
				if(_func (*(b + j), *(b + j - d)))
					std::swap(*(b + j), *(b + j - d));
			}
		}
	}
}

template <typename _It_Ty>
void shell_sort(_It_Ty b, _It_Ty e)
{
	shell_sort(b, e, [](auto a, auto b) {return a < b; });
}


template <typename _Ty>
void shell_sort(vector<_Ty>& arr)
{
	auto b = arr.begin();
	auto e = arr.end();
	for (int d = (e - b) / 2; d != 0; d /= 2)
	{
		for (int i = d; i != (e - b); i++)
		{
			for (int j = i; (b + j) - b >= d; j -= d)
			{
				if (*(b + j) < *(b + j - d))
					std::swap(*(b + j), *(b + j - d));
			}
		}
	}
}

template <typename _It_Ty, typename _Cmp_Func>
void selection_sort(_It_Ty b, _It_Ty e, _Cmp_Func _func)
{
	int sorted = 0;
	while (sorted < (e - b))
	{
		int min_i = sorted;
		for (int i = sorted + 1; i < (e - b); i++)
		{
			if (_func (*(b + i), *(b + min_i)))
				min_i = i;
		}
		swap(*(b + sorted), *(b + min_i));
		sorted++;
	}
}

template <typename _It_Ty>
void selection_sort(_It_Ty b, _It_Ty e)
{
	selection_sort(b, e, [](auto a, auto b) {return a < b; });
}

template <typename _Ty>
void selection_sort(vector<_Ty>& arr)
{
	auto b = arr.begin();
	auto e = arr.end();
	int sorted = 0;
	while (sorted < (e - b))
	{
		int min_i = sorted;
		for (int i = sorted + 1; i < (e - b); i++)
		{
			if (*(b + i) < *(b + min_i))
				min_i = i;
		}
		swap(*(b + sorted), *(b + min_i));
		sorted++;
	}
}
