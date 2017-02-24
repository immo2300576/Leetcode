class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

		vector<int> ans(findNums);

		int index;
		for (int i = 0; i<findNums.size(); i++)
		{
			index = find(nums, findNums[i]);

			ans[i] = findNext(nums, index);
		}


		return ans;
	}
	int find(vector<int>& nums, int n)
	{
		for (int i = 0; i<nums.size(); i++)
		{
			if (n == nums[i])
				return i;
		}
		return -1;
	}
	int findNext(vector<int>& nums, int index)
	{
		for (int i = index + 1; i<nums.size(); i++)
		{
			if (nums[index]<nums[i])
				return nums[i];
		}
		return -1;
	}
};