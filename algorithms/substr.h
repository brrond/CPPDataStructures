#pragma once

#include <string>
using std::string;

template <typename string>
int substr_search_linear(string str, string substr)
{
	size_t c = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		c++;
		size_t j = 0;
		size_t tmp = i;
		while (j < substr.size() && tmp < str.size())
		{
			c++;
			if (str[tmp++] != substr[j++])
			{
				c++;
				break;
			}
		}

		if (j == substr.size() && str[tmp - 1] == substr[j - 1])
			return i;
	}
	return -1;
}

template <typename string>
int substr_search_kpm(string str, string substr)
{
	size_t c = 0;
	vector<int> pf(substr.length());

	pf[0] = 0;

	for (int k = 0, i = 1; i < substr.length(); ++i)
	{
		while ((k > 0) && (substr[i] != substr[k]))
			k = pf[k - 1];

		if (substr[i] == substr[k])
			k++;

		pf[i] = k;
	}

	for (int k = 0, i = 0; i < str.length(); ++i)
	{
		c++;
		while ((k > 0) && (substr[k] != str[i]))
		{
			c++;
			k = pf[k - 1];
		}

		if (substr[k] == str[i])
			k++;

		if (k == substr.length())
			return (i - substr.length() + 1);
	}

	return -1;
}

template <typename string>
int substr_search_bm(string str, string substr)
{
	size_t c = 0;
	vector<int> d(256, substr.size());

	for (int i = 1; i < substr.size(); i++)
	{
		int from_last = substr.size() - i - 1;
		d[substr[from_last]] = std::min(d[substr[from_last]], i);
	}

	for (int i = 0; i < str.size(); i++)
	{
		c++;
		int k = i + substr.size() - 1;	// end of substr (by str)
		int l = substr.size() - 1;		// end of substr
		bool first = true;
		while (l)
		{
			c++;
			if (str[k--] != substr[l--])
			{
				if (first)
					i += d[str[k + 1]] - 1;
				else
					i += d[*substr.end()] - 1;
				break;
			}
			first = false;
		}

		if (l == 0 && str[i] == substr[0])
			return i;
	}

	return -1;
}


template <typename string>
int substr_search_rk(string str, string substr) 
{
	size_t c = 0;
	int p = 2;
	vector<long long> p_pow(str.size());
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); i++)
		p_pow[i] = p_pow[i - 1] * p;
	
	vector<int> h(str.size());

	for (int i = 0; i < str.size(); i++)
	{
		h[i] = (str[i]) * p_pow[i];
		if (i)
			h[i] += h[i - 1];
	}

	long long h_s = 0;

	for (int i = 0; i < substr.size(); ++i)
		h_s += (substr[i]) * p_pow[i];

	for (int i = 0; i + substr.size() - 1 < str.size(); ++i)
	{
		c++;
		long long cur_h = h[i + substr.size() - 1];
		if (i)  cur_h -= h[i - 1];
		if (cur_h == h_s * p_pow[i])
			return i;
	}

	return -1;
}