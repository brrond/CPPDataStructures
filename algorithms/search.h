#pragma once

template<typename _It_Ty, typename _Ty>
int linear_search(_It_Ty b, _It_Ty e, _Ty el)
{
	size_t c = 0;
	for (size_t i = 0; i < (e - b); i++)
	{
		c++;
		if (*(b + i) == el)
		{
			return i;
			c++;
		}
	}
	return -1;
}

template<typename _It_Ty, typename _Ty>
int linear_search_with_barrier(_It_Ty b, _It_Ty e, _Ty el)
{
	size_t c = 0;
	_Ty last = *(e - 1);
	*(e - 1) = el;
	size_t i = 0;
	for (; *(b + i) != el; i++) c++;
	*(e - 1) = last;
	return (*(b + i) == el) ? i : -1;
}

template<typename _It_Ty, typename _Ty>
int binary_search_(_It_Ty b, _It_Ty e, _Ty el)
{
	size_t c = 0;
	size_t left = 0;
	size_t right = (e - b);
	size_t mid;
	while (left < right)
	{
		c++;
		mid = (right + left) / 2; //left + (right - left) / 2; 
		//(right + left) / 2; //l + (r - l) / 2;
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

