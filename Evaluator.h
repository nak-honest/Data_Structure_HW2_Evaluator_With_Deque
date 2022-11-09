#include "Deque.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

using std::string;

class evaluator {
  public:
    // Default Constructor
    evaluator();

    // The read_expression() function reads in the expression from the standard
    // input and returns the string representing the user-provided expression.
    // Pre : None.
    // Post : A string for the infix expression has been returned.
    //        (Example: “(1.03 * x + .4) / y” )
    string read_expression();

    // The convert_to_postfix() converts s (an infix arithmetic expression)
    // into a postfix notation and returns the result string.
    // Pre : s is a well-formed infix arithmetic expression.
    //       So, all operators(+,-,*,and /) are binary,
    //       operands are numbers or variables,
    //       and parentheses are allowed in the expression, but not every
    //       operation needs to be fully parenthesized.
    // Post : a string for well-formed postfix expression converted from s has
    //        been returned. (the operands and operators need to be separated by
    //        least one blank space in a string for well-formed postfix
    //        expression.)
    //        (Example: “1.03 x * .4 + y /” )
    string convert_to_postfix(string s);

    // The evaluate_postfix() evaluates string s which is a postfix arithmetic
    // expression and then returns the result. If a variable in the expression
    // has to be evaluated, but no value is known for it yet, then this asks the
    // user to enter its value from the standard input.
    // Pre : string s is a well-formed postfix arithmetic expression
    //       (i.e., no error-checking required) in which variables are allowed.
    // Post : the evaluation result for s has been returned.
    double evaluate_postfix(string s);

  private:
    // The lower_precedence() returns whether the precedence of operator c1 is
    // lower than the precedence of operator c2.
    // Pre : None.
    // Post : If the precedence of operator c1 is lower than precedence of
    // operator c2, true is returned. The false is returned in opposition case.
    bool lower_precedence(char c1, char c2);
};
