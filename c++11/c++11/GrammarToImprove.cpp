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
	public:
		foo(int _A = 0,int _B = 0) 
		{
			m_A = _A;
			m_B = _B;
			std::cout << "m_A:" << m_A << std::endl;
			std::cout << "m_B:" << m_B << std::endl;
		};
	};
	//������˽���ݵĳ�ʼ��ʹ�ó�ʼ���б���г�ʼ��
	foo fooObj_1 = { 1};
	foo fooObj_2 = { 1,2 };
	foo fooObj_3{ 3,4 };

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
}