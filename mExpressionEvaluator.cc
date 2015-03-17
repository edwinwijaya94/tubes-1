#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ExpressionEvaluator.h"

using namespace std;

int main()
{
	ExpressionEvaluator ee;
	ee.setExpression("5 3 32 4 + * /");
	int res = ee.calculateArith();
	printf("arith=%d\n",res);
	ee.setExpression("1 0 & ! 0 1 | ^");
	res= ee.calculateLogic();
	printf("logic=%d\n",res);
	return 0;
}
