public class Solution {

    public String countAndSay(int n) {
        String str = "1";
        
        while (n > 1) {
            
            String temp = str;
            str = "";
            
            char prev = temp.charAt(0);;
            int freq = 1;
        
            for (int i = 1; i < temp.length(); i++) {
                char c = temp.charAt(i);
                if (c == prev) {
                    freq ++;
                }
                else {
                    str += Integer.toString(freq);
                    str += prev;
                    prev = c;
                    freq = 1;
                }
            }
            str += Integer.toString(freq);
            str += prev;
            
            n--;
        }
        
        return str;
    }
}