//20170214

class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        int l = ceil(sqrt(area));
        int w;
        vector<int> answer (2,0);
        for (w=l;l<area+1;)
        {
            if(l*w==area)
            {
                answer[0]=l;
                answer[1]=w;
                break;
            }
            else if(l*w>area)
            {
                if(w>1)
                    w--;
                else
                    l++;
            }
            else
                l++;
            
        }

        return answer;
    }
};