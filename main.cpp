
#include "stdafx.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <assert.h>

typedef struct
{
	double real;
	double epsilon;
} DualNumber;

DualNumber Dual(double r, double e)
{
	DualNumber epsilon = { r, e };
	return epsilon;
}

DualNumber SetConstant(double r)
{
	return Dual(r, 0);
}

DualNumber SetVariable(double d)
{
	return Dual(d, 1);
}

DualNumber Add(DualNumber U, DualNumber V) //Sum Rule
{
	return Dual(U.real + V.real, U.epsilon + V.epsilon);
}

DualNumber Sub(DualNumber U, DualNumber V) //Sum Rule
{
	return Dual(U.real - V.real, U.epsilon - V.epsilon);
}

DualNumber Mul(DualNumber U, DualNumber V) // Product Rule "Left d(Right)+Right d(Left)""左乘右导，右乘左导"
{
	return Dual(U.real * V.real, U.real * V.epsilon + U.epsilon * V.real);
}

DualNumber Div(DualNumber U, DualNumber V)// Product Rule "Left d(Right)+Right d(Left)"
{
	if (V.real == 0) return{ 0, 0 };

	return Dual(U.real / V.real, (U.epsilon - (U.real / V.real) * V.epsilon) / V.real);
}

DualNumber Sin(DualNumber U)// chain rule
{
	return Dual(sin(U.real), U.epsilon * cos(U.real));
}

DualNumber Cos(DualNumber U)
{
	return Dual(cos(U.real), -U.epsilon * sin(U.real));
}

DualNumber Exp(DualNumber U)
{
	return Dual(exp(U.real), U.epsilon * exp(U.real));
}

DualNumber Log(DualNumber U)
{
	assert(U.real > 0);
	return Dual(log(U.real), U.epsilon / U.real);
}
DualNumber Power(DualNumber U, double e)
{
	return Dual(pow(U.real, e), U.epsilon * e * pow(U.real, e - 1));
}

DualNumber Abs(DualNumber U)
{
	assert(U.real != 0);
	return Dual(abs(U.real), U.epsilon * ((U.real > 0) ? 1 : -1));
}

int main(void)
{
	//"real" is function value
	//"epsilon" is the derivative of a function

	//test 1
	double x = 10;
	DualNumber t = SetVariable(x);
	DualNumber d1 = Power(t, 2);
	std::cout << "value:" << d1.real << " derivative:" << d1.epsilon << std::endl;

	//test 2
	std::vector<DualNumber> vec;

	vec.emplace_back(Dual(20, 0));// like SetConstant
	vec.emplace_back(Dual(10, 1));// like SetVariable


	DualNumber x1 = Exp(vec[0]);
	DualNumber x2 = Power(vec[1], 2);
	DualNumber x3 = Mul(x1, x2);

	std::cout << "value:" << x3.real << " derivative:" << x3.epsilon << std::endl;
	system("pause");

	return 0;
}
