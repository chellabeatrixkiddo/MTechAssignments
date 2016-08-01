import java.util.Scanner;

class PrintHello {
    public static void main(String[] args) {
        int i = 0;
        int no_of_greetings = 0;
        Scanner in = new Scanner(System.in);
        
        System.out.println("We are saying Hello to this World!");
        System.out.println("How many times do you want to greet? : ");
        no_of_greetings = in.nextInt();
        
        while(no_of_greetings != 0) {
            System.out.println("Hello World!");
            no_of_greetings = no_of_greetings - 1;
        }   
    }
}