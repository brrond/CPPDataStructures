#include "matrix.h"

template<typename Ty>
matrix<Ty>::matrix()
{

}

template<typename Ty>
matrix<Ty>::matrix(size_t size_n, size_t size_m)
{
	m.resize(size_n);
	for (auto i = m.begin(); i < m.end(); i++) 
	{
		i.resize(size_m);
	}
}

template<typename Ty>
matrix<Ty>::matrix(size_t size_n, size_t size_m, const Ty& val)
{
	m.resize(size_n);
	for (auto i = m.begin(); i < m.end(); i++)
	{
		i->resize(size_m);
		for (auto j = i->begin(); j < i->end(); j++)
		{
			*j = val;
		}
	}
}

template<typename Ty>
matrix<Ty> matrix<Ty>::operator*(const Ty& val)
{
	matrix ret = *this;
	for (auto f = ret.m.begin(); f < ret.m.end(); f++) 
	{
		for (auto el = f->begin(); el < f->end(); el++)
		{
			try
			{
				*el *= val;
			}
			catch (...)
			{
				throw "Incorrect operation. Make sure u use right data type";
			}
		}
	}
	return ret;
}

template<typename Ty>
matrix<Ty>& matrix<Ty>::operator*=(const Ty& val)
{
	for (auto f = m.begin(); f < m.end(); f++)
	{
		for (auto el = f->begin(); el < f->end(); el++)
		{
			try
			{
				*el *= val;
			}
			catch (...)
			{
				throw "Incorrect operation. Make sure u use right data type";
			}
		}
	}
	return *this;
}

template<typename Ty>
std::ostream& operator<<(std::ostream& out, matrix<Ty>& mat)
{
	for (auto f = mat.m.begin(); f < mat.m.end(); f++)
	{
		for (auto el = f->begin(); el < f->end(); el++)
		{
			try
			{
				out << *el << ",";
			}
			catch (...)
			{
				throw "Incorrect operation. Make sure that data type have overriden operator<<";
			}
		}
		out << std::endl;
	}
	return out;
}
