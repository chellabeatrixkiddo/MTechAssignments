#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

char* infix_to_postfix(char*);
int postfix_expr_evaluation(char*, int);
int precedence(char);

int precedence(char operator) {
    int prec = 0;
    if(operator == '^')
        prec = 3;
    else if(operator == '*' || operator == '/')
        prec = 2;
    else if(operator == '+' || operator == '-')
        prec = 1;
    return prec;
}

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
                    if(operator_tos == 0 || operator_stack[operator_tos] == '(')
                        operator_stack[++operator_tos] = expr[expr_iterator];
                    else if(expr[expr_iterator] == '(')
                        operator_stack[++operator_tos] = expr[expr_iterator];
                    else if(precedence(expr[expr_iterator]) > precedence(operator_stack[operator_tos]))
                        operator_stack[++operator_tos] = expr[expr_iterator];
                    else if(precedence(expr[expr_iterator]) == precedence(operator_stack[operator_tos])) {
                        // Left Association by default
                        postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                        postfix_iterator++;
                        operator_stack[++operator_tos] = expr[expr_iterator];
                    }
                    else {
                        while(precedence(expr[expr_iterator]) < precedence(operator_stack[operator_tos])) {
                            postfix_expr[postfix_iterator] = operator_stack[operator_tos--];
                            postfix_iterator++;
                        }
                        operator_stack[++operator_tos] = expr[expr_iterator];
                    }
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

int postfix_expr_evaluation(char* postfix_expr, int variable_value) {
    int operand_stack[30];
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
    //char temp[100];
    char* postfix_expr;
    int expr_iterator, evaluated_value, variable_value, prev_symbol = 0, j = 0;
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
    
    //printf("%s\n", postfix_expr);
    for(scanf("%d", &variable_value); variable_value != 1000; scanf("%d", &variable_value)) {
        evaluated_value = postfix_expr_evaluation(postfix_expr, variable_value);
        printf("P(%d) = %d\n", variable_value, evaluated_value);
    }
    return 0;
}