import java.io.*;
import java.util.Scanner;

class Stack {
    
    private int tos;
    private LList stackList;
    
    public Stack() {
        tos = -1;
        stackList = new LList();
    }
    
    void push(Object obj) {
        tos = tos + 1;
        stackList.append(obj);
    }
    
    Object pop() {
        if(!isEmpty()) {
            Object obj = stackList.remove(tos);
            tos = tos - 1;
            return obj;
        }
        else
            return null;
    }
    
    boolean isEmpty() {
        if(tos == -1)
            return true;
        else
            return false;
    }
    
    String printStack() {
        String description = stackList.toString();
        return description;
    }
}

public class BalancedParenthesis {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a String of Parenthesis: ");
        String inputLine = input.next();
        int inputLength = inputLine.length();
        int iterator;
        char temp;
        String temp1;
        
        System.out.println("Creating a Stack");
        Stack stackOfBraces = new Stack();
        
        for(iterator = 0; iterator < inputLength; iterator++) {
            temp = inputLine.charAt(iterator);
            if(temp == '(' || temp == '{' || temp == '[') {
                stackOfBraces.push(String.valueOf(temp));
            }
            else {
                if(temp == ')') {
                    temp1 = (stackOfBraces.pop()).toString();
                    if(!temp1.equals("(")) {
                        System.out.println("Not Balanced!");
                        break;
                    }
                }
                else if(temp == '}') {
                    temp1 = (stackOfBraces.pop()).toString();
                    if(!temp1.equals("{")) {
                        System.out.println("Not Balanced!");
                        break;
                    }
                }
                else if(temp == ']') {
                    temp1 = (stackOfBraces.pop()).toString();
                    if(!temp1.equals("[")) {
                        System.out.println("Not Balanced!");
                        break;
                    }
                }
            }
            
        }
        
        /*Add names to the Name Stack:
        stackOfNames.push(1);
        stackOfNames.push(2);*/
        if(stackOfBraces.isEmpty())
            System.out.println("Balanced!");
        else
            System.out.println(stackOfBraces.printStack());
        
    }
}