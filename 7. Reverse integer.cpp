class Solution {
public:
    int reverse(int x) {
        int x_reverved=0;
        int x_wk;
        int singleDigit;
        bool isNeg = false;
        
        if(x==INT_MIN)
        {
            x = -(x+1);
            isNeg = true;
        }
        else if(x<0)
        {
            x = -x;
            isNeg = true;
        }
        
        x_wk = x;
        while(x_wk!=0)
        {
            singleDigit = x_wk%10;
            x_wk = (x_wk-singleDigit)/10;
            if(x_reverved<((double)INT_MAX)/10)
                x_reverved = x_reverved*10+singleDigit;
            else //overflow case
                {
                    x_reverved = 0;
                    break;
                }
        }
        if(isNeg)
            x_reverved = -x_reverved;
        
        return x_reverved;
        
    }
};