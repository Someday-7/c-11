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
	std::cout << "val:" << test<float>(f);
}