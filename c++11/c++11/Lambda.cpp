#include "Lambda.h"



Lambda::Lambda()
{
	m_Value = 0;
}


Lambda::~Lambda()
{
}
void Lambda::LambdaFunctionTest()
{
	std::cout << __FUNCTION__ << std::endl;
	int para1 = 0, para2 = 2,tempValue = 0;
	//1} 1）不捕获外部变量 2）参数为整形a 3）指定返回值类型为int
	auto lambdaFunc1 = [](int a) -> int 
	{
		return a + 1;
	};
	std::cout << "[1] lambdaFunc1:" << lambdaFunc1(1)<< std::endl;
	//2} 1）捕获所有外部变量，按值捕获，不可修改捕获的值  2）参数为整形a 3）指定返回值类型为int
	std::cout << "[2] tempValue:" << tempValue << std::endl;
	auto lambdaFunc2 = [=](int a) -> int
	{
		return m_Value + a + tempValue;
	};
	++tempValue;
	std::cout << "[2] lambdaFunc2:" << lambdaFunc2(1) << std::endl;
	std::cout << "[2] tempValue:" << tempValue << std::endl;
	//3} 1）捕获所有外部变量，按值捕获 mutable 可以修改捕获的值 2）参数为整形a 3）指定返回值类型为int
	
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc3 = [=](int a)mutable -> int
	{
		++tempValue;
		return m_Value + a + tempValue;
	};
	++tempValue;
	std::cout << "[3] lambdaFunc3:" << lambdaFunc3(1) << std::endl;
	std::cout << "[3] tempValue:" << tempValue << std::endl;
	//4} 1）捕获所有外部变量，按引用捕获 2）参数为整形a 3）指定返回值类型为int
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc4 = [&](int a) -> int
	{
		tempValue++;
		return m_Value + a + tempValue;
	};
	std::cout << "[4] lambdaFunc4:" << lambdaFunc4(1) << std::endl;
	std::cout << "[4] tempValue:" << tempValue << std::endl;
	//5} 1）捕获所有外部变量，按引用捕获，不可修改捕获的变量的值 2）参数为整形a 3）指定返回值类型为int
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc5= [&](int a) -> int
	{
		tempValue++;
		return m_Value + a + tempValue;
	};
	std::cout << "[5] lambdaFunc5:" << lambdaFunc5(1) << std::endl;
	std::cout << "[5] tempValue:" << tempValue << std::endl;
	//6} 1）捕获当前this指针 2）参数为整形a 3）指定返回值类型为int
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc6 = [this](int a) -> int
	{
		this->m_Value++;
		return m_Value + a;
	};
	std::cout << "[6] lambdaFunc6:" << lambdaFunc6(1) << std::endl;
	std::cout << "[6] tempValue:" << tempValue << std::endl;
	std::cout << "[6] m_Value:" << m_Value << std::endl;
	//7} 1）捕获当前this指针，tempValue按引用捕获  2）参数为整形a 3）指定返回值类型为int
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc7 = [this,&tempValue](int a) -> int
	{
		this->m_Value++;
		++tempValue;
		return m_Value + a+ tempValue;
	};
	std::cout << "[6] lambdaFunc7:" << lambdaFunc7(1) << std::endl;
	std::cout << "[6] tempValue:" << tempValue << std::endl;
	std::cout << "[6] m_Value:" << m_Value << std::endl;
}