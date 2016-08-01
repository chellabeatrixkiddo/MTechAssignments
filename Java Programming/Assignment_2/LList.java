/*****************************************************************************************

Implementation of a Linked List in java

*****************************************************************************************/

import java.lang.Object.*;

public class LList {
    
    /* LNode is a helper class which creates a single node of the linked list.
       Each node has a String data and a reference to an object of LNode class */
       
    private class LNode<T> {
        private T data;
        private LNode next;
        
        public LNode(T data, LNode next) {
            this.data = data;
            this.next = next;
        }
        public String toString() {
            return (this.data).toString();
        }
    }
   
    private LNode headOfList;
    private LNode tailOfList;
    private static int listSize;
    
    public LList() {
        headOfList = null;
        tailOfList = null;
        listSize = 0;
    }
    
    public void insert(int pos, Object obj) {
        int iter = 0;
        LNode <Object> node = new LNode <Object>(obj, null);
        if(pos == 0) {
            node.next = headOfList;
            headOfList = node;
        }
        else {
            LNode current = headOfList;
            LNode previous = null;
            while(iter < pos && current.next != null) {
                previous = current;
                current = current.next;
                iter++;
            }
            previous.next = node;
            node.next = current;
        }
        listSize = listSize + 1;
    }
    public Object remove(int pos) {
        int iter = 0;
        LNode current = headOfList;
        LNode previous = null;
        if(pos == 0) {
            current = headOfList;
            headOfList = headOfList.next;
        }
        else {
            
            while(iter < pos && current.next != null) {
                previous = current;
                current = current.next;
                iter++;
            }
            previous.next = current.next;
            if(pos == listSize - 1)
                tailOfList = previous;
        }
        listSize = listSize - 1;
        return current;
    }
    public Object get(int pos) {
        int iter = 0;
        LNode temp = headOfList;
        while(iter <= pos && temp != null) {
            temp = temp.next;
            iter++;
        }
        return temp;
    }
    public int find(Object obj) {
        LNode temp = headOfList;
        int position = 0;
        while(!(((temp.data).toString()).equals(obj.toString())) && (temp != null)) {
            temp = temp.next;
            position++;
        }
        if(((temp.data).toString()).equals(obj.toString())){
            return position;
        }
        else
            return -1;
    }
    public int size() {
        /*int counter = 0;
        LNode temp = headOfList;
        while(temp != null)
            counter++;
        return counter;*/
        return listSize;
    }
    public void clear() {
        headOfList = null;
        tailOfList = null;
        listSize = 0;
    }
    public void append(Object obj) {
        LNode <Object> node = new LNode <Object>(obj.toString(), null);
        if (headOfList == null) {
            headOfList = node;
            tailOfList = node;
            listSize = 1;
        }
        else {
            // traverse till the end of the list
            /*LNode temp = headOfList;
            while (temp.next != null)
                temp = temp.next;
            temp.next = node;
            */
            tailOfList.next = node;
            tailOfList = node;
            listSize = listSize + 1;
        }
    }
    public String toString() {
        String description = "";
        //traverse the linked list
        LNode temp = headOfList;
        while(temp != null) {
            description = description + temp.data + "\n";
            temp = temp.next;
        }
        return description;
    }
   /* public static void main(String[] args) {
        
        LList bookList = new LList();
        System.out.println(bookList);
        
        bookList.append("Harry Potter I");
        System.out.println(bookList);
        
        bookList.insert(0, "Hamlet");
        System.out.println(bookList);
        
        bookList.insert(0, "Cosmos");
        System.out.println(bookList);
        
        bookList.insert(1, "Java");
        System.out.println(bookList);
        
        bookList.remove(1);
        System.out.println(bookList);
        
        bookList.insert(1, "C++");
        bookList.insert(2, "LISP");
        bookList.insert(2, "Calvin & Hobbes");
        System.out.println(bookList);
        
        int pos = bookList.find("LISP");
        bookList.remove(pos);
        System.out.println(bookList);
        
        System.out.println("Size: " + bookList.size());
        // autoboxing and unboxing
        bookList.clear();
        bookList.append(1);
        bookList.append(1);
        bookList.append(2);
        bookList.append(3);
        System.out.println(bookList);
        pos = bookList.find(2);
        bookList.remove(pos);
        System.out.println(bookList);
    }*/
    
}