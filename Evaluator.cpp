#include "Evaluator.h"

evaluator::evaluator() {}

string evaluator::read_expression() {
    string expression;
    /* Input the infix expression include the blank space. */
    getline(std::cin, expression);
    return expression;
}

string evaluator::convert_to_postfix(string s) {
    deque<char> my_deque;
    // This deque is used to store the operators. The deque is used like stack.
    string postfix;
    // The result string of postpix expression that is converted by s.
    char letter;
    size_t num_of_digit = 0; // The number of digit in double include '.'

    for (int i = 0; i < s.length(); i++) {
        letter = s[i];

        if (letter == ' ') { // The letter is blank space.
            if (num_of_digit != 0)
                /* Because the operands and operators are separated by blank
                   space, if later letter is digit, that number is new operands.
                   So that num_of_digit is zero means that later digit is new
                   operands. */
                num_of_digit = 0;
        } else if (isdigit(letter) || letter == '.') { // The letter is digit.
            if (!postfix.empty() && num_of_digit == 0)
                /* If postfix is not empty, that num_of_digit is zero and letter
                   is digit means this number is new operands. Because the
                   operands and operators should be separated by blank space,
                   add the blank space. */
                postfix.push_back(' ');

            postfix.push_back(letter);
            num_of_digit++;
        } else if (isalpha(letter)) { // The letter is variables.
            if (!postfix.empty())
                /* This variable is new operands, so add the blank space. */
                postfix.push_back(' ');
            postfix.push_back(letter);
        } else if (strchr("+-*/", letter) != NULL) { // The letter is operator.
            while ((!my_deque.empty()) && (my_deque.front() != '(') &&
                   (!lower_precedence(my_deque.front(), letter))) {
                /* The operator that is popped at deque is new operands, so add
                   the blank space. */
                postfix.push_back(' ');
                postfix.push_back(my_deque.front());
                my_deque.pop_front();
            }
            my_deque.push_front(letter); // Push the operator to deque.
        } else if (letter == '(') {      // The letter is left parenthesis.
            my_deque.push_front(letter);
        } else if (letter == ')') { // The letter is right parenthesis.
            while (my_deque.front() != '(') {
                postfix.push_back(' ');
                postfix.push_back(my_deque.front());
                my_deque.pop_front();
            }
            my_deque.pop_front();
        }
    }

    while (!my_deque.empty()) { // All operators in deque is popped.
        /* The operator that is popped at deque is new operands, so add
           the blank space. */
        postfix.push_back(' ');
        postfix.push_back(my_deque.front());
        my_deque.pop_front();
    }

    return postfix;
}

double evaluator::evaluate_postfix(string s) {
    double answer; // The result.
    char letter;
    string double_operand;
    deque<double> my_deque; // The deque is used to store the double numbers.
                            // The deque is used like stack.

    size_t string_size = s.length();

    size_t variables_num = 0; // The number of variables in s.

    char *variables = new char[string_size];
    // The dynamic array that store each variables.
    // This checks for that variables are duplicate.

    double *variables_value = new double[string_size];
    // The dynamic array that store the value of variables that user enters.
    // The index is same with variables array.

    double input_num;
    // The temporary variable that store the value of variable that user enters.

    int i, j;

    for (i = 0; i < string_size; i++) {
        letter = s[i];
        if (letter == ' ') { // The letter is blank space.
            if (!double_operand.empty()) {
                /* If double_operand is not empty, then earlier letter is
                   digit. This means double_operand is complete double number,
                   because the operands and operators are separated by blank
                   space. So push the double_operand to deque using type
                   casting. */
                my_deque.push_front(stod(double_operand));
                double_operand.clear(); // Then clear the double_operand.
            }
        } else if (isdigit(letter) || letter == '.') { // The letter is digit.
            if (double_operand.empty() && letter == '.') {
                // If the double operand starts with '.', first push the zero to
                // double_operand. ex) .4 -> 0.4
                double_operand.push_back('0');
            }
            double_operand.push_back(letter);

            if (i == string_size - 1) {
                /* If postfix expression is the one number, the postfix
                   expression ends with the digit. (other case, the postfix
                   expression ends with the operator.) This for-loop pushes the
                   double_operand to deque when the letter is blank space. But
                   in this case, double_operand doesn't have blank space. So
                   when the 'i' is the end of index, the double_operand should
                   be pushed to deque. */
                my_deque.push_front(stod(double_operand));
            }
        } else if (isalpha(letter)) { // The letter is variable.
            j = 0;
            while (j < variables_num && variables[j] != letter) {
                /* Check for that variable is duplicate. */
                j++;
            }

            if (j < variables_num) { // The variable is duplicate.
                /* So push the variables value that user entered to deque. */
                my_deque.push_front(variables_value[j]);
            } else { // The variable is not duplicate.
                /* So ask the user to enter its value from standard input. */
                std::cout << "Enter the value of " << letter << " : "
                          << std::endl;
                std::cin >> input_num;

                /* Because cin leave the '\n' at buffer, getline() in
                   read_expression() read '\n'. So remove the '\n' in buffer
                   using cin.ingnore(). */
                std::cin.ignore();

                my_deque.push_front(input_num);
                variables[j] = letter;
                variables_value[j] = input_num;
                variables_num++;
            }
        } else if (strchr("+-*/", letter) != NULL) { // The letter is operator.
            double rval = my_deque.front();
            my_deque.pop_front();
            double lval = my_deque.front();
            my_deque.pop_front();

            // calculate using operator.
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

    /* Free the memory of dynamic array. */
    delete[] variables;
    delete[] variables_value;

    answer = my_deque.front();
    return answer;
}

bool evaluator::lower_precedence(char c1, char c2) {
    bool is_lower = false;

    if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/')) {
        /* Only this case, the precedence of operator c1 is lower than
           precedence of operator c2. */
        is_lower = true;
    }

    return is_lower;
}
