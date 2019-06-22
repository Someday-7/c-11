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
	decltype(b) c = a;//�Ƶ�������bΪ����
	std::cout << "decltype c:"<< c << std::endl;

	//�����÷�,ʵ��ģ��ʱ������ʹ�������Ƶ��������const�ͷ�const������
	std::vector<int> intVector1;
	FOO<std::vector<int>> FooTemplate1;
	FooTemplate1.func(intVector1);

	const std::vector<int> intVector2;
	FOO<const std::vector<int>> FooTemplate2;
	FooTemplate2.func(intVector2);

	//�����Ƶ�
	struct A
	{
		int a;
	};
	using valueA = decltype((*(A*)nullptr).a);
	valueA d = 0.1;
	std::cout << "d:" << d << std::endl;

	//����ֵ���ͺ����﷨��ԭʼc++�Ƿ���ֵǰ���﷨���ڶ���ʱ��Ҫ֪������ֵ���ͣ�
	int e = 1;
	float f = 0.1;
	std::cout << "val:" << test<float>(f) << std::endl;
}
void GrammarToImprove::initialUsing()
{
	std::cout << __FUNCTION__ << std::endl;
	//ʹ�ó�ʼ���б��ʼ������ʱ��ֻ�������ڡ��ۺ��塱
	//�ۺ��嶨�壺
	//1����ͨ����	
	//2��һ������
	//	1)���Զ��幹�캯��
	//	2)��˽�л򱣻��ķǾ�̬���ݳ�Ա
	//	3)�޻���
	//	4)���麯��
	//	5)������{}��=ֱ�ӳ�ʼ���Ǿ�̬���ݳ�Ա
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
	//������˽���ݵĳ�ʼ��ʹ�ó�ʼ���б���г�ʼ��
	foo fooObj_1 = foo(10);
	foo fooObj_2 = { 1,2 };
	foo fooObj_3{ 3,4 };
	//����inlitializer_list��������ģ���ʼ��
	//@1 �ڲ�������iterator����������ĸ���
	//@2 ���ܵ��������ͱ���һ�£��ɽ������ⳤ������
	//@3 3����Ա�ӿ� size() begin() end()
	//@4 ֻ�����屻��ʼ��
	//@5 �洢������������ã��ǿ���
	foo fooObj_4 = {1,2,3,4};
	//new��ʱ���ʼ������̬������ڴ�ռ䣬���϶�̬���������ռ�ʹ�ó�ʼ���б��ʼ��
	int* testArr = new int[4]{ 1,2,3,4 };
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "testArr["<<i<<"]:" << testArr[i] << std::endl;
	}
	//����ֵ��ʹ�ó�ʼ���б���һ����ʱ����
	auto lambdaFunc_1  = [=]()->foo
	{
		return { 5,6 };
	};
	lambdaFunc_1();
	//������խ�����¾��ȶ�ʧ�������ݱ仯����ʽ����ת��
	int a = 1.1;
}
//���ڷ�Χ��forѭ��
//@1 ֻ��һ���﷨��
//@2 �ڵ���ʱ��Ҫ�����������޸ģ����ܻ����������ʧЧ
//@3 �ڵ���֮ǰ������.begin()��.end(),����������������ֻ����һ�ε�����
//@4 �Զ������ͣ���Ҫʵ��.begin()��.end()
#include <algorithm>
void GrammarToImprove::forLoop()
{
	//�����㷨����for_each�㷨ʵ�ֵ�������ѭ��
	std::vector<int> intVector = {1,2,3,4,5,6,7};
	auto coutVectorFun = [=](int n)->void {std::cout << "[for_each] n:" << n << std::endl; };
	std::for_each(intVector.begin(), intVector.end(), coutVectorFun);
	//c++11�µ�for���
	//*1 ��������
	for (auto n : intVector)
	{
		std::cout << "[*1 c++1 for] n:" << n << std::endl;
	}
	//*2 ���ñ��������޸�ԭֵ
	for (auto& n : intVector)
	{
		++n;
	}
	for (auto n : intVector)
	{
		std::cout << "[*2 c++1 for] n:" << n << std::endl;
	}
	//*2 �����Ҳ����޸�ԭֵ����
	for (const auto& n : intVector)
	{
		std::cout << "[*3 c++1 for] n:" << n << std::endl;
	}

	//�����������Ƶ�������auto����ʹ�ó�Ա���÷�ȡ��ֵ
	std::map<std::string, int> _tempMap = { {"1",1}, {"2",2}, {"3",3} };
	for (auto& val : _tempMap)
	{		
		std::cout << "[c++1 for] map " << val.first.c_str() << ":" << ++val.second << std::endl;
	}
	for (auto& val : _tempMap)
	{
		std::cout << "[c++1 for] map " << val.first.c_str() << ":" << val.second << std::endl;
	}
	//�ڶԵ�������ֵ�����޸�ʱ������������������ԣ�Լ����
	//set����
	std::set<int> _setContainer;
	for (auto& val : _setContainer)
	{
		//set�г�Ա���ɱ��޸ġ�ֻ����ʽ
		//std::cout << "[c++1 for] set " << ++val<< std::endl;
	}
}