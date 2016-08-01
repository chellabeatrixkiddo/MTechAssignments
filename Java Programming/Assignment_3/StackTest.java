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

public class StackTest {
    public static void main(String[] args) {
        System.out.println("Creating a Stack");
        Stack stackOfNames = new Stack();
        //Add names to the Name Stack:
        stackOfNames.push("Bruce Wayne");
        stackOfNames.push("Clark Kent");
        stackOfNames.push("Barry Allen");
    	System.out.println(stackOfNames.printStack());
    }
}