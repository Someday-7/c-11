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
		std::vector<int> m_IntVector;
	public:
		foo(int _A = 0,int _B = 0) 
		{
			m_A = _A;
			m_B = _B;
			std::cout << "m_A:" << m_A << std::endl;
			std::cout << "m_B:" << m_B << std::endl;
		};
		foo(std::initializer_list<int> list)
		{
			std::cout << "[initializer_list] list.size:" << list.size() << std::endl;

			auto it = list.begin();
			for (it; it != list.end(); ++it)
			{
				m_IntVector.push_back(*it);
			}
			std::cout << "[initializer_list] m_IntVector.size:"<< m_IntVector .size()<<std::endl;
		}
	};
	//对象中私数据的初始化使用初始化列表进行初始化
	foo fooObj_1 = foo(10);
	foo fooObj_2 = { 1,2 };
	foo fooObj_3{ 3,4 };
	//利用inlitializer_list轻量级类模板初始化
	//@1 内部定义了iterator等容器必须的概念
	//@2 接受的数据类型必须一致，可接受任意长度数据
	//@3 3各成员接口 size() begin() end()
	//@4 只能整体被初始化
	//@5 存储传入参数的引用，非拷贝
	foo fooObj_4 = {1,2,3,4};
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
	//类型收窄，导致精度丢失或者数据变化的隐式类型转换
	int a = 1.1;
}
//基于范围的for循环
//@1 只是一种语法糖
//@2 在迭代时不要对容器进行修改，可能会引起迭代器失效
//@3 在迭代之前，调用.begin()和.end(),所有整个迭代过程只访问一次迭代器
//@4 自定义类型，需要实现.begin()和.end()
#include <algorithm>
void GrammarToImprove::forLoop()
{
	//利用算法库中for_each算法实现迭代器的循环
	std::vector<int> intVector = {1,2,3,4,5,6,7};
	auto coutVectorFun = [=](int n)->void {std::cout << "[for_each] n:" << n << std::endl; };
	std::for_each(intVector.begin(), intVector.end(), coutVectorFun);
	//c++11新的for语句
	//*1 拷贝遍历
	for (auto n : intVector)
	{
		std::cout << "[*1 c++1 for] n:" << n << std::endl;
	}
	//*2 引用遍历，可修改原值
	for (auto& n : intVector)
	{
		++n;
	}
	for (auto n : intVector)
	{
		std::cout << "[*2 c++1 for] n:" << n << std::endl;
	}
	//*2 引用且不可修改原值遍历
	for (const auto& n : intVector)
	{
		std::cout << "[*3 c++1 for] n:" << n << std::endl;
	}

	//关联性容器推导出来的auto类型使用成员作用符取键值
	std::map<std::string, int> _tempMap = { {"1",1}, {"2",2}, {"3",3} };
	for (auto& val : _tempMap)
	{		
		std::cout << "[c++1 for] map " << val.first.c_str() << ":" << ++val.second << std::endl;
	}
	for (auto& val : _tempMap)
	{
		std::cout << "[c++1 for] map " << val.first.c_str() << ":" << val.second << std::endl;
	}
	//在对迭代引用值进行修改时，主义容器本身的特性（约束）
	//set容器
	std::set<int> _setContainer;
	for (auto& val : _setContainer)
	{
		//set中成员不可被修改。只读形式
		//std::cout << "[c++1 for] set " << ++val<< std::endl;
	}
}