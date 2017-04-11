public class Solution {
    public boolean isValid(String s) {
        Stack p = new Stack();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '(')
                p.push(c);
            else if (c == ')') {
                if (p.empty())
                    return false;
                char item = (char) p.pop();
                if (item != '(')
                    return false;
            }
            else if (c == '[')
                p.push(c);
            else if (c == ']') {
                if (p.empty())
                    return false;
                char item = (char) p.pop();
                if (item != '[')
                    return false;
            }
            else if (c == '{')
                p.push(c);
            else if (c == '}') {
                if (p.empty())
                    return false;
                char item = (char) p.pop();
                if (item != '{')
                    return false;
            }
        }
        if (p.empty())
            return true;
        else
            return false;
    }
}