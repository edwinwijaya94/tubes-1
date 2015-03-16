#include "OperandConverter.h"
using namespace std;

OperandConverter::OperandConverter(string in)
{
	romawiExpression = in;
}
	
int OperandConverter::isOperator(char in)
{
	if (in == '+') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	return 0;
}
	
string OperandConverter::toArabicExpression()
{
	string res="";
	string temp="";
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if (isOperator(romawiExpression[i]))
		{
			//printf("temp : %s\n",temp.c_str());
			RomanNumber n(temp);
			int xx = n.toArabicNumber();
			//int xx = romawiToInteger((char*)temp.c_str());
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
			//printf("op : %s\n",string(1,romawiExpression[i]).c_str());
			res.append(string(1,romawiExpression[i]));
			temp = "";
		}else
		{
			temp.append(string(1,romawiExpression[i]));
		}
	}
	if (temp!="")
	{
		//printf("temp : %s\n",temp.c_str());
		RomanNumber n(temp);
		int xx = n.toArabicNumber();
		//int xx = romawiToInteger((char*)temp.c_str());
		ostringstream convert;
		convert << xx;
		res.append(convert.str());
	}
	return res;
}
