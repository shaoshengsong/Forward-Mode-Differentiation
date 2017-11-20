# Forward-Mode-Differentiation

shao shengsong

Automatic differentiation using dual numbers

"real" is value of the variable
"epsilon" is the derivative of a variable


Usage



```
//test 1
	double x = 10;
	DualNumber t = SetVariable(x);
	DualNumber d1 = Power(t, 2);
	std::cout << "value:"<<d1.real << " derivative:" << d1.epsilon << std::endl;

	//test 2
	std::vector<DualNumber> vec;

	vec.emplace_back(Dual(20, 0));// like SetConstant
	vec.emplace_back(Dual(10, 1));// like SetVariable


	DualNumber x1 = Exp(vec[0]);
	DualNumber x2 = Power(vec[1], 2);
	DualNumber x3 = Mul(x1,x2);

	std::cout << "value:" << x3.real << " derivative:" << x3.epsilon << std::endl;
```
