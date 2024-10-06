// Author: Michael Zarkov
//
// Focus of the excercise is to use the stack data structure in an algorithm.
//
// Task: Parse the given postfix math expression (return the answer).
//       Expression is for example AB+CD-* which in infix is (A + B) * (C - D).
//
// 
// |--- Postfix notation ---|
// 
// In postfix notation the two operands come before the operator.
//
// Ex:
//     1) Infix ("normal") expression: A+B
//        Postfix expression: AB+
//     2) Infix:   3 + 5 = 8
//        Postfix: 3 5 + = 8
//     3) Inf:  3 * (2 - 2) = 0
//        Post: 3 2 2 - *   = 0
//     4) Inf:  5 + (3 * (-2)) = -1
//        Post: 5 3 -2 * +     = -1
//
// The good thing about postfix (and prefix) notation is that brackets and/or operator priority
// are not needed because the order of operations is always well defined.
// 

#include <iostream>
#include <stack>
#include <string>

bool isOperation(std::string& s)
{
	return s == "+" || s == "-" || s == "*";
}

// Operations + - *
// 'expression' has to be valid postfix expression!
int parse_expression(std::stack<std::string>& expression) {

	std::stack<int> numbers;

	while (!expression.empty()) {
		// Push numbers in 'numbers'.
		while (!isOperation(expression.top()))
		{
			numbers.push(atoi(expression.top().c_str()));   // Convert string to number and push.
			expression.pop();
		}

		// Execute arithmetic operations.
		while (!expression.empty() && isOperation(expression.top()))
		{
			int temp = numbers.top();
			numbers.pop();
			if (expression.top() == "+") 
				numbers.top() += temp;
			else if (expression.top() == "-")
				numbers.top() -= temp;
			else if (expression.top() == "*")
				numbers.top() *= temp;

			expression.pop();  // Remove executed operation.
		}
	}

	return numbers.top();
}

int main()
{
	std::stack<std::string> expression;
	expression.push("*");
	expression.push("+");
	expression.push("6");
	expression.push("5");
	expression.push("4");
	// Ans. 44

	/*expression.push("+");
	expression.push("*");
	expression.push("-2");
	expression.push("3");
	expression.push("5");*/
	// Ans. -1

	std::cout << parse_expression(expression);
}