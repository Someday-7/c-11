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
	std::cout << __FUNCTION__ << std::endl;
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
	std::cout << "val:" << test<float>(f) << std::endl;
}
void GrammarToImprove::initialUsing()
{
	std::cout << __FUNCTION__ << std::endl;
	//使用初始化列表初始化对象时，只能作用于“聚合体”
	//聚合体定义：
	//1、普通数组	
	//2、一个类且
	//	1)无自定义构造函数
	//	2)无私有或保护的非静态数据成员
	//	3)无基类
	//	4)无虚函数
	//	5)不能有{}和=直接初始化非静态数据成员
	class foo
	{
	private:
		int m_A;
		int m_B;
	public:
		foo(int _A = 0,int _B = 0) 
		{
			m_A = _A;
			m_B = _B;
			std::cout << "m_A:" << m_A << std::endl;
			std::cout << "m_B:" << m_B << std::endl;
		};
	};
	//对象中私数据的初始化使用初始化列表进行初始化
	foo fooObj_1 = { 1};
	foo fooObj_2 = { 1,2 };
	foo fooObj_3{ 3,4 };

	//new的时候初始化，动态申请的内存空间，堆上动态分配的数组空间使用初始化列表初始化
	int* testArr = new int[4]{ 1,2,3,4 };
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "testArr["<<i<<"]:" << testArr[i] << std::endl;
	}
	//返回值，使用初始化列表返回一个临时对象
	auto lambdaFunc_1  = [=]()->foo
	{
		return { 5,6 };
	};
	lambdaFunc_1();
}