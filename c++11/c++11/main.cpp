#pragma once
#include <iostream>
#include "Lambda.h"
#include "GrammarToImprove.h"
int main(int argc, char** argv)
{
	//Lambda���ʽ
	Lambda LambdaObj;
	LambdaObj.LambdaFunctionTest();
	//C++11һЩ�﷨�Ľ�
	GrammarToImprove GrammarToImproveObj;
	GrammarToImproveObj.decltypeUsing();
	GrammarToImproveObj.initialUsing();
	GrammarToImproveObj.forLoop();
	char in;
	std::cin >> in;
	return 0;
}