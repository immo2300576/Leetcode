class Solution {
public:
	bool isPalindrome(int x) {
		int length = 0;
		int x_wk = x;
		int firstDigit;
		int lastDigit;
		int temp;

		if (x<0)
			return false;

		while (x_wk != 0)
		{
			x_wk = (x_wk - x_wk % 10) / 10;
			length++;
		}
		x_wk = x;
		temp = 1;
		for (int i = 1; i<length; i++)
			temp *= 10;

		while (length>1)
		{

			firstDigit = floor((double)x_wk / temp);
			lastDigit = x_wk % 10;

			if (firstDigit != lastDigit)
				return false;

			x_wk = x_wk - firstDigit*temp;
			x_wk = (x_wk - lastDigit) / 10;
			length = length - 2;
			temp = temp / 100;
		}
		return true;

	}
};