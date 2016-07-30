/** Expression Evaluator:

This version is for evaluating an expression in which parenthesis may be used for altering the order of evaluation of arguments.

Assumptions:
1. There will be only one variable represented by a single character
2. Except when parenthesis are present, assume all operators have equal precedence and evaluated left to right
3. Parentheses alters the order of evaluation of expressions like in normal programming
4. No nesting of parentheses will be there
5. Any of the five operators (+, -, *, /, ^) may appear in any order
6. Input will come from standard input and output to the screen. No need for file I/O
7. An input line with the number 1000 signals the end of the input. No need to evaluate further.

******/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char* infix_to_postfix(char*);
long int postfix_expr_evaluation(char*, long int);

char* infix_to_postfix(char* expr) {
    int expr_iterator, postfix_iterator, operator_tos, open_brace;
    char* postfix_expr;
    char operator_stack[30];
    
    postfix_expr = (char*) malloc(sizeof(char) * 30);
    expr_iterator = postfix_iterator = operator_tos = 0;
    open_brace = 0;
    
    while(expr[expr_iterator] != '\0') {
        // Convert Infix to Postfix:
        // If it is a variable store the operand in the postfix expression
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
            
            if(expr[expr_iterator] == ')') {
                // Pop all the operators untill the '(' is found and append all the popped operators to the postfix expression
                while(operator_stack[operator_tos] != '(') {    
                    postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                    postfix_iterator++;
                }
                operator_tos--;
                open_brace = 0;
            }
            
            else {
                    if(operator_tos != 0 && !open_brace && expr[expr_iterator] != '(') {
                        postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                        postfix_iterator++;
                    }
                    else if(open_brace) {
                        if(operator_tos != 0) {
                            while(operator_stack[operator_tos] != '(') {
                                postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                                postfix_iterator++;
                            }
                        }
                    }
                    operator_stack[++operator_tos] = expr[expr_iterator];
                    if(expr[expr_iterator] == '(')
                        open_brace = 1;
                }
        }
        expr_iterator++;
    }
    while(operator_tos > 0) {
        postfix_expr[postfix_iterator] = operator_stack[operator_tos];
        operator_tos--;    
    }
    return(postfix_expr);
}

long int postfix_expr_evaluation(char* postfix_expr, long int variable_value) {
    long int operand_stack[50];
    int postfix_iterator, operand_tos, value1, value2;
    // Evaluate the Postfix Expression
        postfix_iterator = 0;
        operand_tos = 0;
        
        while(postfix_iterator < strlen(postfix_expr)) {
            if(isalpha(postfix_expr[postfix_iterator])) {
                // If it is a variable push the variable value into the operand stack
                operand_stack[++operand_tos] = variable_value;
            }
            else if(isdigit(postfix_expr[postfix_iterator])) {
                // push it into the operand stack
                // if it is a 3 digit no.
                if(isdigit(postfix_expr[postfix_iterator+1]) && isdigit(postfix_expr[postfix_iterator+2]) && isdigit(postfix_expr[postfix_iterator+3])) {
                    operand_stack[++operand_tos] = (postfix_expr[postfix_iterator] - '0')*1000 + (postfix_expr[postfix_iterator+1] - '0')*100 + (postfix_expr[postfix_iterator+2] - '0')*10 + (postfix_expr[postfix_iterator+3] - '0');
                    postfix_iterator += 3;
                }
                // if it is a 3 digit no.
                else if(isdigit(postfix_expr[postfix_iterator+1]) && isdigit(postfix_expr[postfix_iterator+2])) {
                    operand_stack[++operand_tos] = (postfix_expr[postfix_iterator] - '0')*100 + (postfix_expr[postfix_iterator+1] - '0')*10 + (postfix_expr[postfix_iterator+2] - '0');
                    postfix_iterator += 2;
                }
                // if it is a 2 digit no.
                else if(isdigit(postfix_expr[postfix_iterator+1])) {
                    operand_stack[++operand_tos] = (postfix_expr[postfix_iterator] - '0')*10 + (postfix_expr[postfix_iterator+1] - '0');
                    postfix_iterator++;
                }
                else
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
    char expr[100];
    char temp[100];
    char* postfix_expr;
    int expr_iterator,  prev_symbol = 0, j = 0;
    long int variable_value, evaluated_value;
    // Reading the expression from the user:
    printf("P(X) = ");
    scanf("%s", expr);
   /* for(int i = 0; i < strlen(expr); i++) {
        if(isdigit(expr[i]) && isalpha(expr[i+1]))
            prev_symbol = 1;
        if(isalpha(expr[i]) && prev_symbol == 1)
            temp[j++] = '*';
        temp[j++] = expr[i];
    }*/
    //printf("%s\n", temp);
    postfix_expr = infix_to_postfix(expr);
    
    printf("%s\n", postfix_expr);
    for(scanf("%ld", &variable_value); variable_value != 1000; scanf("%ld", &variable_value)) {
        evaluated_value = postfix_expr_evaluation(postfix_expr, variable_value);
        printf("P(%ld) = %ld\n", variable_value, evaluated_value);
    }
    return 0;
}