import java.lang.*;

class PrintPatternSingleLoop {
    public static void main(String[] args) {
        String pattern = new String("0123456789");
        //String spaces = new String("          ");
        int str_len = pattern.length();
        int i;
        for(i = 0; i < str_len; i++) {
            System.out.println(pattern.substring(0,i+1) + (new StringBuilder(pattern.substring(0,i))).reverse().toString());
        }
        System.out.println();
        for(i = 0; i < str_len; i++) {
            String result = new String(pattern.substring(0,i+1) + (new StringBuilder(pattern.substring(0,i))).reverse().toString());
            System.out.println(String.format("%" + ((str_len-i)+result.length()) + "s", result));
            //System.out.println(spaces.substring(0,(spaces.length())-i) + new String(pattern.substring(0,i+1) + (new StringBuilder(pattern.substring(0,i))).reverse().toString()));
        }
    }
}
         
      