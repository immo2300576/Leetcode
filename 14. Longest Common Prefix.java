public class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        if (strs == null)
            return "";
            
        if (strs.length == 0)
            return "";
        
        String str = "";
        boolean isStop = false;
        int idx = 0;
        char c1, c2;
        while (!isStop) {
            if (idx < strs[0].length())
                c1 = strs[0].charAt(idx);
            else
                break;
            for (int i = 1; i < strs.length; i++) {
                if (idx < strs[i].length())
                    c2 = strs[i].charAt(idx);
                else {
                    isStop = true;
                    break;
                }
                    
                if (c1 != c2) {
                    isStop = true;
                    break;
                }
            }
            if (!isStop) {
                str += c1;
                idx++;
            }
        }
        return str;
    }
}