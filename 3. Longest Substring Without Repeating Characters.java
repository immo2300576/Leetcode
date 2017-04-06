public class Solution {
    private char[] currentArray = null;
    private int length = 0;
    private int currentLength = 0;
    private int capacity = 0;
    private boolean isRepeated = false;
    public int lengthOfLongestSubstring(String s) {

        for (int i = 0; i < s.length(); i++) {
            int k = 0;
            isRepeated = false;
            while (!isRepeated && i+k < s.length()) {
                searchForArray(s.charAt(i+k));
                k ++;
            }
        }
        if (length < currentLength)
            length = currentLength;
            
        return length;
    }
    private void searchForArray(char c) {
        if (currentLength == 0) {
            iniArray(c);
        }
        else { // scan the current array: if no repetition, append it. Otherwise reset current array
            for (int i = 0; i < currentLength; i++) {
                if (currentArray[i] == c) {
                    isRepeated = true;
                    break;
                }
            }
            if (isRepeated) {
                if (length < currentLength)
                    length = currentLength;
                resetArray();
            }
            else {
                currentArray[currentLength] = c;
                currentLength ++;
                if (currentLength == capacity)
                    resize(2*capacity);
            }
        }
    }
    private void resetArray() {
        currentLength = 0;
        currentArray = null;
        capacity = 0;
    }
    private void iniArray(char c) {
        currentArray = new char[2];
        currentArray[0] = c;
        currentLength = 1;
        capacity = 2;
    }
    private void resize(int size) {
        char[] copy = new char[size];
        for (int i = 0; i < currentLength; i++)
            copy[i] = currentArray[i];
        
        capacity = size;
        currentArray = copy;
    }
    
    
}
