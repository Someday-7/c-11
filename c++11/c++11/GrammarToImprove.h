#pragma once
#include "header.h"
#include <vector>
template<class T>
class FOO
{
	decltype(T().begin()) it_;
public:
	void func(T& container)
	{
		it_ = container.begin();
	}

};

extern int &func1(int & val1);
extern float &func1(float & val2);
template<typename T>
auto test(T& t1)->decltype(func1(t1))
{
	return func1(t1);
}

class GrammarToImprove
{
public:
	GrammarToImprove();
	~GrammarToImprove();
	void decltypeUsing();
private:

};

