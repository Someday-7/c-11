#pragma once
#include <iostream>
#include "Lambda.h"
#include "GrammarToImprove.h"
int main(int argc, char** argv)
{
	//Lambda表达式
	Lambda LambdaObj;
	LambdaObj.LambdaFunctionTest();
	//C++11一些语法改进
	GrammarToImprove GrammarToImproveObj;
	GrammarToImproveObj.decltypeUsing();
	char in;
	std::cin >> in;
	return 0;
}