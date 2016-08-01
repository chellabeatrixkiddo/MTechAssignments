class PrintPattern {
    public static void main(String[] args) {
        int[] numbers = {0,1,2,3,4,5,6,7,8,9};
        int i, j, k;
        for(i = 0; i < numbers.length; i++) {
            for(j = 0; j <= i; j++) {
                System.out.print(numbers[j]);
            }
            for(k = i-1; k >=0; k--) {
                System.out.print(numbers[k]);
            }
            System.out.println();
        }
    }
}