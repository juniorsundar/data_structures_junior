#include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator() {
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator() {
    while (stackHead != NULL) {
        pop();
    }
}

bool RPNCalculator::isEmpty() {
    if (stackHead == NULL) {
        return true;
    } else {
        return false;
    }
    
}

void RPNCalculator::push(float num) {
    Operand* newNum = new(Operand);
    newNum->number = num;
    newNum->next = stackHead;
    stackHead = newNum;
}

void RPNCalculator::pop() {
    if (isEmpty()) {
        cout << "Stack empty, cannot pop an item." << endl;
    } else {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
}

Operand* RPNCalculator::peek() {
    if (isEmpty()) {
        cout << "Stack empty, cannot peek." << endl;
        return stackHead;
    } else {
        return stackHead;
    }
}

bool RPNCalculator::compute(std::string symbol) {
    if (stackHead != NULL && stackHead->next != NULL) {
        if (symbol == "+") {
            float num1 = stackHead->number;
            float num2 = stackHead->next->number;
            pop();
            pop();
            push(num1 + num2);
            return true;
        } else if (symbol == "*") {
            float num1 = stackHead->number;
            float num2 = stackHead->next->number;
            pop();
            pop();
            push(num1 * num2);
            return true;
        } else {
            cout << "err: invalid operation" << endl;
            return false;
        }
    } else {
        cout << "err: not enough operands" << endl;
        return false;
    }
    
}
