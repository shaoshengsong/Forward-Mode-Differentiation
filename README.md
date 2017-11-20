# Forward-Mode-Differentiation

shao shengsong

Automatic differentiation using dual numbers

"real" is value of the variable
"epsilon" is the derivative of a variable



<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>
$$
{\begin{aligned}\left\langle u,u'\right\rangle +\left\langle v,v'\right\rangle =\left\langle u+v,u'+v'\right\rangle \\\\\left\langle u,u'\right\rangle -\left\langle v,v'\right\rangle =\left\langle u-v,u'-v'\right\rangle \\\\\left\langle u,u'\right\rangle *\left\langle v,v'\right\rangle =\left\langle uv,u'v+uv'\right\rangle \\\\\left\langle u,u'\right\rangle /\left\langle v,v'\right\rangle =\left\langle {\frac  {u}{v}},{\frac  {u'v-uv'}{v^{2}}}\right\rangle \quad (v\neq 0)\\\\\sin \left\langle u,u'\right\rangle =\left\langle \sin(u),u'\cos(u)\right\rangle \\\\\cos \left\langle u,u'\right\rangle =\left\langle \cos(u),-u'\sin(u)\right\rangle \\\\\exp \left\langle u,u'\right\rangle =\left\langle \exp u,u'\exp u\right\rangle \\\\\log \left\langle u,u'\right\rangle =\left\langle \log(u),u'/u\right\rangle \quad (u>0)\\\\\left\langle u,u'\right\rangle ^{k}=\left\langle u^{k},ku^{{k-1}}u'\right\rangle \quad (u\neq 0)\\\\\left|\left\langle u,u'\right\rangle \right|=\left\langle \left|u\right|,u'{ {sign}}u\right\rangle \quad (u\neq 0)\end{aligned}}"
$$


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
