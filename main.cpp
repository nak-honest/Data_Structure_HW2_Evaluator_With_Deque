#include "Evaluator.h"

int main() {
    string infix, postfix;
    double result;
    evaluator e;

    while (1) {
        std::cout << "Enter the well-formed infix arithmetic expression"
                  << "(If you want to quit, enter 'q') : " << std::endl;
        infix = e.read_expression();
        if (infix == "q" || infix == "Q") {
            exit(0);
        }
        postfix = e.convert_to_postfix(infix);
        result = e.evaluate_postfix(postfix);
        std::cout << "The infix expression : " << infix << std::endl
                  << "The postfix expression : " << postfix << std::endl
                  << "The evaluation result : " << result << std::endl;
    }

    return 0;
}
