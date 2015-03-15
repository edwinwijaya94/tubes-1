#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ExpressionEvaluator.h"

using namespace std;
	
int ExpressionEvaluator::isOperator(char in)
{
		if (in == '+') return 1;
		if (in == '-') return 1;
		if (in == '/') return 1;
		if (in == '*') return 1;
		if (in == '%') return 1;
		return 0;
	}
	
ExpressionEvaluator::ExpressionEvaluator(string input)
{
	expression = input;
}
	
int ExpressionEvaluator::calculate()
{
	opFlag = 0;
	for (int i=0;i<expression.length();i++)
	{
		if (isOperator(expression[i]))
		{
			printf("1\n");
			opFlag = 1;
			int a,b;
			st.pop(a);
			st.pop(b);
			
			if (expression[i] == '+') st.push(a+b);
			else if (expression[i] == '-') st.push(a-b);
			else if (expression[i] == '/') st.push(a/b);
			else if (expression[i] == '*') st.push(a*b);
			else if (expression[i] == '%') st.push(a%b);
				
		}else if (expression[i] == ' ')
		{
			if (opFlag == 0){
				int xx = atoi(temp.c_str());
				st.push(xx);
				temp = "";
			}
		}else
		{
			temp.append(string(1,expression[i]));
		}
	}
	int tt;
	st.pop(tt);
	return tt;
}