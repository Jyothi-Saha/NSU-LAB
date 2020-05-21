/* using c++ 14 */
#include <iostream>
#include "StackType.h"

using namespace std;

bool priorityChecker(char op1, char op2) {

    {
        /*
         * Operands priority:
         *
         *          ^ = 3
         *          * , / = 2
         *          + , - = 1
         *          other characters = 0
         *
         * */

    }

    int p1 = 0, p2 = 0;

    switch (op1) {
        case '^':
            p1 = 3;
            break;
        case '*':
        case '/':
            p1 = 2;
            break;
        case '+':
        case '-':
            p1 = 1;
            break;
        default:
            p1 = 0;

    }

    switch (op2) {
        case '^':
            p2 = 3;
            break;
        case '*':
        case '/':
            p2 = 2;
            break;
        case '+':
        case '-':
            p2 = 1;
            break;
        default:
            p2 = 0;
    }

    return p1 >= p2;

}

int main() {

    string expression;
    getline(cin, expression);

    // Converting infix to postfix

    StackType<char> opStack;
    string postfix;
    int parenthesisCount=0;
    for (int i = 0; i < expression.size(); i++) {

        if (expression[i] == ' ' || expression[i] == '\t')
            continue;
        if (expression[i] >= '0' && expression[i] <= '9') {
            postfix += expression[i];

        } else {

            if (expression[i] == '('){
                opStack.Push(expression[i]);
                parenthesisCount++;
            }

            else if (expression[i] == ')') {
                if (opStack.IsEmpty()) {
                    cout << "Invalid expression" << endl;
                    return 1;
                }
                while (opStack.Top() != '(') {

                    postfix += opStack.Top();
                    opStack.Pop();

                    if (opStack.IsEmpty()) {
                        cout << "Invalid expression" << endl;
                        return 2;
                    }
                }
                opStack.Pop();
                parenthesisCount--;

            } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                if(i==0 || i==expression.size()-1){
                    cout<<"Invalid expression"<<endl;
                    return 5;
                }
                else if(!priorityChecker(' ',expression[i-1])){
                    cout<<"Invalid expression"<<endl;
                    return 6;
                }
                while (!opStack.IsEmpty() && priorityChecker(opStack.Top(), expression[i])) {
                    postfix += opStack.Top();
                    opStack.Pop();
                }
                opStack.Push(expression[i]);
            } else {
                cout << "Invalid expression" << endl;
                return 3;
            }

        }
    }

    if(parenthesisCount>0){     // To make sure no opening parenthesis left
        cout<<"Invalid expression"<<endl;
        return 4;
    }

    while (!opStack.IsEmpty()) {
        postfix += opStack.Top();
        opStack.Pop();
    }

    // Evaluation of postfix

    StackType<double> calculation;
    for(int i=0; i<postfix.size();i++){         //"range-based loop" can be used as well, search the term if you are interested
        if(postfix[i]>='0' && postfix[i]<='9'){
            double x = postfix[i]-'0';  // if a character is a decimal digit, this is how you can convert it to numerical value
            calculation.Push(x);
        } else{

            double a = calculation.Top();
            calculation.Pop();
            double b = calculation.Top();
            calculation.Pop();
            double result = 0;
            switch (postfix[i]){
                case '+':
                    result = b+a;
                    break;
                case '-':
                    result = b-a;
                    break;
                case '*':
                    result = b*a;
                    break;
                case '/':
                    result = b/a;
                    break;
            }
            calculation.Push(result);
        }
    }

    //cout << postfix<<endl;
    cout << calculation.Top();


    return 0;
}