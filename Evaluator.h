#include "Deque.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

using std::string;

class evaluator {
  public:
    evaluator();
    string read_expression();
    string convert_to_postfix(string s);
    double evaluate_postfix(string s);

  private:
    bool lower_precedence(char c1, char c2);
};
