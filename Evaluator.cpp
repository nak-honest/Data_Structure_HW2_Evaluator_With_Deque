#include "Evaluator.h"

evaluator::evaluator() {}

string evaluator::read_expression() {
    string expression;
    getline(std::cin, expression);
    return expression;
}

string evaluator::convert_to_postfix(string s) {
    deque<char> my_deque;
    string postfix;
    char letter;
    size_t num_of_digit = 0;

    for (int i = 0; i < s.length(); i++) {
        letter = s[i];

        if (letter == ' ') {
            if (num_of_digit != 0)
                num_of_digit = 0;
        } else if (isdigit(letter) || letter == '.') {
            if (!postfix.empty() && num_of_digit == 0)
                postfix.push_back(' ');

            postfix.push_back(letter);
            num_of_digit++;
        } else if (isalpha(letter)) {
            if (!postfix.empty())
                postfix.push_back(' ');

            postfix.push_back(letter);
        } else if (strchr("+-*/", letter) != NULL) {
            while ((!my_deque.empty()) && (my_deque.front() != '(') &&
                   (!lower_precedence(my_deque.front(), letter))) {
                postfix.push_back(' ');
                postfix.push_back(my_deque.front());
                my_deque.pop_front();
            }
            my_deque.push_front(letter);
        } else if (letter == '(') {
            my_deque.push_front(letter);
        } else if (letter == ')') {
            while (my_deque.front() != '(') {
                postfix.push_back(' ');
                postfix.push_back(my_deque.front());
                my_deque.pop_front();
            }
            my_deque.pop_front();
        }
    }

    while (!my_deque.empty()) {
        postfix.push_back(' ');
        postfix.push_back(my_deque.front());
        my_deque.pop_front();
    }

    return postfix;
}

double evaluator::evaluate_postfix(string s) {
    double answer;
    char letter;
    string digit;
    deque<double> my_deque;
    size_t string_size = s.length();
    size_t variables_num = 0;
    char *variables = new char[string_size];
    double *variables_value = new double[string_size];
    double input_num;
    int i, j;

    for (i = 0; i < string_size; i++) {
        letter = s[i];
        if (letter == ' ') {
            if (!digit.empty()) {
                my_deque.push_front(stod(digit));
                digit.clear();
            }
        } else if (isdigit(letter) || letter == '.') {
            if (digit.empty() && letter == '.') {
                digit.push_back('0');
            }
            digit.push_back(letter);
        } else if (isalpha(letter)) {
            j = 0;
            while (j < variables_num && variables[j] != letter) {
                j++;
            }

            if (j < variables_num) {
                my_deque.push_front(variables_value[j]);
            } else {
                std::cout << "Enter the value of " << letter << " : "
                          << std::endl;
                std::cin >> input_num;
                my_deque.push_front(input_num);
                variables[j] = letter;
                variables_value[j] = input_num;
                variables_num++;
            }
        } else if (strchr("+-*/", letter) != NULL) {
            double rval = my_deque.front();
            my_deque.pop_front();
            double lval = my_deque.front();
            my_deque.pop_front();

            switch (letter) {
            case '+':
                my_deque.push_front(lval + rval);
                break;
            case '-':
                my_deque.push_front(lval - rval);
                break;
            case '*':
                my_deque.push_front(lval * rval);
                break;
            case '/':
                my_deque.push_front(lval / rval);
                break;
            }
        }
    }

    delete[] variables;
    delete[] variables_value;

    answer = my_deque.front();
    return answer;
}

bool evaluator::lower_precedence(char c1, char c2) {
    bool is_lower;
    if (c1 == '*' || c1 == '/') {
        return false;
    } else if (c1 == '+' || c1 == '-') {
        if (c2 == '+' || c2 == '-') {
            return false;
        } else if (c2 == '*' || c2 == '/') {
            return true;
        }
    }
    return false;
}
