#pragma once

template<typename _It_Ty, typename _Ty>
size_t linear_search(_It_Ty b, _It_Ty e, _Ty el)
{
	for (size_t i = 0; i < (e - b); i++)
		if (*(b + i) == el)
			return i;
	return -1;
}

template<typename _It_Ty, typename _Ty>
size_t linear_search_with_barrier(_It_Ty b, _It_Ty e, _Ty el)
{
	_Ty last = *(e - 1);
	*(e - 1) = el;
	size_t i = 0;
	for (; *(b + i) != el; i++);
	*(e - 1) = last;
	return (*(b + i) == el) ? i : -1;
}

template<typename _It_Ty, typename _Ty>
size_t binary_search_(_It_Ty b, _It_Ty e, _Ty el)
{
	size_t left = 0;
	size_t right = (e - b);
	size_t mid;
	while (left != right)
	{
		mid = (right + left) / 2;
		if (*(b + mid) > el)
		{
			right = mid;
		}
		else if (*(b + mid) < el)
		{
			left = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

