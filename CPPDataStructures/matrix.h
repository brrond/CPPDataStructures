#pragma once
#include <vector>
#include <iostream>


template <typename Ty>
class matrix
{
private:
	using m_type = std::vector<std::vector<Ty>>;
	m_type m;
protected:

public:
	matrix();
	matrix(size_t size_n, size_t size_m);
	matrix(size_t size_n, size_t size_m, const Ty& val);
	
	matrix operator*(const Ty& val);
	matrix& operator*=(const Ty& val);

	matrix operator+(const matrix& mat);
	matrix operator*(const matrix& mat);
	matrix& operator=(const matrix& mat);
	matrix& operator+=(const matrix& mat);
	matrix& operator*=(const matrix& mat);

	matrix& operator-();

	bool operator==(const matrix& mat);
	bool operator!=(const matrix& mat);

	template <typename func_template>
	matrix f(func_template func);

	template <typename func_template>
	matrix ebe(Ty val, func_template func);
	// func(x, y) => z

	template <typename func_template>
	matrix ebe(const matrix& mat, func_template func);
	// func(Aij, Bij) => Cij

	// rank
	// transpose
	// determinant

	m_type& data();

public:

	static matrix getIdentityMatrix(size_t size_n, size_t size_m);
	// diagonal matrix(vec) => matrix
	// null matrix(n, m) => matrix

	friend std::ostream& operator<<(std::ostream& out, matrix& mat); 

};

#include "matrix.cpp"

