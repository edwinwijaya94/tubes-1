make :
	g++ -o a CommandHistory.cc ExpressionConverter.cpp ExpressionEvaluator.cc LogicNumber.cpp OperandConverter.cc RomanNumber.cpp Calculator.cpp mCalculator.cpp 
run :
	a