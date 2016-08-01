/*****************************************************************************************

Implementation of a Doubly Linked List in java

*****************************************************************************************/

import java.lang.Object.*;

public class DLList {
    
    /* LNode is a helper class which creates a single node of the linked list.
       Each node has a String data and a reference to an object of LNode class */
       
    private class DLNode {
        private String data;
        private DLNode prev;
        private DLNode next;
        
        public DLNode(String data, DLNode prev, DLNode next) {
            this.data = data;
            this.prev = prev;
            this.next = next;
        }
    }
   
    private DLNode headOfList;
    private DLNode tailOfList;
    private static int listSize;
    
    public DLList() {
        headOfList = null;
        tailOfList = null;
        listSize = 0;
    }
    
    public void insert(int pos, Object obj) {
        int iter = 0;
        DLNode node = new DLNode(obj.toString(), null, null);
        if(pos == 0) {
            node.next = headOfList;
            headOfList.prev = node;
            headOfList = node;
        }
        else {
            DLNode current = headOfList;
            DLNode previous = null;
            while(iter < pos && current.next != null) {
                current = current.next;
                iter++;
            }
            (current.prev).next = node;
            node.next = current;
            node.prev = current.prev;
            current.prev = node;
        }
        listSize = listSize + 1;
    }
    public void remove(int pos) {
        int iter = 0;
        if(pos == 0) {
            headOfList = headOfList.next;
            headOfList.prev = null;
        }
        else {
            DLNode current = headOfList;
            while(iter < pos && current.next != null) {
                current = current.next;
                iter++;
            }
            (current.prev).next = current.next;
            (current.next).prev = current.prev;
            if(pos == listSize - 1)
                tailOfList = current.prev;
        }
        listSize = listSize - 1;
    }
    public Object get(int pos) {
        int iter = 0;
        DLNode temp = headOfList;
        while(iter <= pos && temp != null) {
            temp = temp.next;
            iter++;
        }
        return temp;
    }
    public int find(Object obj) {
        DLNode temp = headOfList;
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
        DLNode node = new DLNode(obj.toString(), null, null);
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
            node.prev = tailOfList;
            tailOfList = node;
            listSize = listSize + 1;
        }
    }
    public String toString() {
        String description = "";
        //traverse the linked list
        DLNode temp = headOfList;
        while(temp != null) {
            description = description + temp.data + "\n";
            temp = temp.next;
        }
        return description;
    }
    public static void main(String[] args) {
        
        DLList bookList = new DLList();
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
    }
    
}