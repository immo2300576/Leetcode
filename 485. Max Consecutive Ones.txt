// 20170214

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count_one = 0;
        int max_count = 0;
        for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it)
        {
            if(*it==1)
                count_one++;
            if(*it==0)
            {
                if(count_one>max_count)
                    max_count = count_one;
                count_one = 0;
            }
        }
        if(count_one>max_count)
                    max_count = count_one;
        count_one = 0;
        
        return max_count;
        
    }
};