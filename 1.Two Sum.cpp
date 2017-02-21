//Solution 1:
//[Brute force]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool isDone = false;
        vector<int> answer(2,0);
        for(int i = 0; i < nums.size()-1; i++)
        {
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i]+nums[j] == target)
            {
                isDone = true;
                answer[0] = i;
                answer[1] = j;
                break;
            }
        }
        if(isDone == true)
            break;
        }
        
        return answer;
        }
};

//Solution 2:
//[1-pass hash table]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2,0);
        map<int,int> lut;
        map<int,int>::iterator it;
        int complement;
        //search each element in the array
        for(int i=0; i<nums.size();i++)
        {
            complement = target - nums[i];
            it = lut.find(complement);
            if(it!=lut.end())
            {
                answer[0] = lut[complement];
                answer[1] = i;
                break;
            }
            lut[nums[i]] = i;
        }
        
        return answer;
        }
};