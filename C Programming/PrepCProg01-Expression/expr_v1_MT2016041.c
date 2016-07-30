/** Expression Evaluator:

This version will evaluate simple expression.Simple expression expressions do not use parentheses to alter the precedence of operators.

Assumptions:
1. There will be only one variable represented by a single character
2. Assume all operators (+, -, *, /, ^) have equal precedence and evaluated left to right
3. Any of the five operators may appear in any order
4. No parentheses
5. Input will come from standard input and output to the screen. No need for file I/O

*****/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char* infix_to_postfix(char*);
int postfix_expr_evaluation(char*, int);

char* infix_to_postfix(char* expr) {
    int expr_iterator, postfix_iterator, operator_tos;
    char* postfix_expr;
    char operator_stack[30];
    postfix_expr = (char*) malloc(sizeof(char) * 30);
    expr_iterator = postfix_iterator = operator_tos = 0;
   
    while(expr[expr_iterator] != '\0') {
        // Convert Infix to Postfix:
        // If it is a variable replace store the operand in the postfix expression
        if(isalpha(expr[expr_iterator])) {
            postfix_expr[postfix_iterator] = expr[expr_iterator];
            postfix_iterator++;      
        }
        // If if it is a digit store the operand in the postfix expression
        else if(isdigit(expr[expr_iterator])) {
            postfix_expr[postfix_iterator] = expr[expr_iterator] ;
            postfix_iterator++;
        }
        // If it is an operator store it in the operator stack
        else {
            if(operator_tos != 0) {
                postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                postfix_iterator++;
            }
            operator_stack[++operator_tos] = expr[expr_iterator];
        }
        expr_iterator++;
    }
    if(operator_tos != 0)
        postfix_expr[postfix_iterator++] = operator_stack[operator_tos--];   
    postfix_expr[postfix_iterator++] = '\0';
    return(postfix_expr);
}

int postfix_expr_evaluation(char* postfix_expr, int variable_value) {
    int operand_stack[30];
    int postfix_iterator, operand_tos, value1, value2;
    // Evaluate the Postfix Expression
        postfix_iterator = 0;
        operand_tos = 0;
        
        while(postfix_expr[postfix_iterator] != '\0') {
            if(isalpha(postfix_expr[postfix_iterator])) {
                // If it is a variable push the variable value into the operand stack
                operand_stack[++operand_tos] = variable_value;
            }
            else if(isdigit(postfix_expr[postfix_iterator])) {
                // push it into the operand stack
                operand_stack[++operand_tos] = postfix_expr[postfix_iterator] - '0';
            }
            else {
                // it is an operator, pop the top two operands from the operand stack, compute the operation and push the result back
                value1 = operand_stack[operand_tos--];
                value2 = operand_stack[operand_tos--];
                if(postfix_expr[postfix_iterator] == '+')
                    operand_stack[++operand_tos] = value2 + value1;
                else if(postfix_expr[postfix_iterator] == '-')
                    operand_stack[++operand_tos] = value2 - value1;
                else if(postfix_expr[postfix_iterator] == '*')
                    operand_stack[++operand_tos] = value2 * value1;
                else if(postfix_expr[postfix_iterator] == '/')
                    operand_stack[++operand_tos] = value2 / value1;
                else if(postfix_expr[postfix_iterator] == '^')
                    operand_stack[++operand_tos] = pow(value2,value1);
    
            } 
            postfix_iterator++;
        }
        return (operand_stack[operand_tos]);
}

int main() {
    char expr[30];
    char* postfix_expr;
    int expr_iterator, evaluated_value, variable_value;
    // Reading the expression from the user:
    printf("P(X) = ");
    scanf("%s", expr);
    for(scanf("%d", &variable_value); variable_value != 1000; scanf("%d", &variable_value)) {
        postfix_expr = infix_to_postfix(expr);
        evaluated_value = postfix_expr_evaluation(postfix_expr, variable_value);
        printf("P(%d) = %d\n", variable_value, evaluated_value);
    }
    return 0;
}