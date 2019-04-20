#include "GrammarToImprove.h"
int &func1(int & val1) { return val1; };
float &func1(float & val2) { return val2; };


GrammarToImprove::GrammarToImprove()
{
}


GrammarToImprove::~GrammarToImprove()
{
}
void GrammarToImprove::decltypeUsing()
{
	float a = 0.1;
	int b = 1;
	decltype(b) c = a;//推导出来的b为整形
	std::cout << "decltype c:"<< c << std::endl;

	//具体用法,实现模板时，可以使用类型推导来解决，const和非const型容器
	std::vector<int> intVector1;
	FOO<std::vector<int>> FooTemplate1;
	FooTemplate1.func(intVector1);

	const std::vector<int> intVector2;
	FOO<const std::vector<int>> FooTemplate2;
	FooTemplate2.func(intVector2);

	//类型推导
	struct A
	{
		int a;
	};
	using valueA = decltype((*(A*)nullptr).a);
	valueA d = 0.1;
	std::cout << "d:" << d << std::endl;

	//返回值类型后置语法（原始c++是返回值前置语法：在定义时需要知道返回值类型）
	int e = 1;
	float f = 0.1;
	std::cout << "val:" << test<float>(f);
}