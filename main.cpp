#include "Evaluator.h"

int main() {
    string infix, postfix;
    double result;
    evaluator e;

    while (1) {
        std::cout << "Enter the well-formed infix arithmetic expression"
                  << "(If you want to quit, enter 'q/Q') : " << std::endl;

        infix = e.read_expression();
        if (infix == "q" || infix == "Q") {
            exit(0); // If user enter the 'q' or 'Q', exit the program.
        }
        std::cout << "The infix expression : " << infix << std::endl;

        postfix = e.convert_to_postfix(infix);
        std::cout << "The postfix expression : " << postfix << std::endl;

        result = e.evaluate_postfix(postfix);
        std::cout << "The evaluation result : " << result << std::endl;
    }

    return 0;
}
