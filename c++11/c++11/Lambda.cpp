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
	//1} 1���������ⲿ���� 2������Ϊ����a 3��ָ������ֵ����Ϊint
	auto lambdaFunc1 = [](int a) -> int 
	{
		return a + 1;
	};
	std::cout << "[1] lambdaFunc1:" << lambdaFunc1(1)<< std::endl;
	//2} 1�����������ⲿ��������ֵ���񣬲����޸Ĳ����ֵ  2������Ϊ����a 3��ָ������ֵ����Ϊint
	std::cout << "[2] tempValue:" << tempValue << std::endl;
	auto lambdaFunc2 = [=](int a) -> int
	{
		return m_Value + a + tempValue;
	};
	++tempValue;
	std::cout << "[2] lambdaFunc2:" << lambdaFunc2(1) << std::endl;
	std::cout << "[2] tempValue:" << tempValue << std::endl;
	//3} 1�����������ⲿ��������ֵ���� mutable �����޸Ĳ����ֵ 2������Ϊ����a 3��ָ������ֵ����Ϊint
	
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
	//4} 1�����������ⲿ�����������ò��� 2������Ϊ����a 3��ָ������ֵ����Ϊint
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc4 = [&](int a) -> int
	{
		tempValue++;
		return m_Value + a + tempValue;
	};
	std::cout << "[4] lambdaFunc4:" << lambdaFunc4(1) << std::endl;
	std::cout << "[4] tempValue:" << tempValue << std::endl;
	//5} 1�����������ⲿ�����������ò��񣬲����޸Ĳ���ı�����ֵ 2������Ϊ����a 3��ָ������ֵ����Ϊint
	tempValue = 0;
	m_Value = 0;
	auto lambdaFunc5= [&](int a) -> int
	{
		tempValue++;
		return m_Value + a + tempValue;
	};
	std::cout << "[5] lambdaFunc5:" << lambdaFunc5(1) << std::endl;
	std::cout << "[5] tempValue:" << tempValue << std::endl;
	//6} 1������ǰthisָ�� 2������Ϊ����a 3��ָ������ֵ����Ϊint
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
	//7} 1������ǰthisָ�룬tempValue�����ò���  2������Ϊ����a 3��ָ������ֵ����Ϊint
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