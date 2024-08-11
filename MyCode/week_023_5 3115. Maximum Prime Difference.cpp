// https://leetcode.com/problems/maximum-prime-difference/description/

class Solution {
public:
	bool isPrime(const int _input)
	{
		if (_input <= 0)
			return false;
		else if (_input == 1)
			return false;
		else if (_input == 2 || _input == 3)
			return true;

		if (_input % 2 == 0)
			return false;

		for (int i = 3; i < _input;++i)
		{
			if (_input % i == 0)
				return false;
		}

		return true;
	}
	int maximumPrimeDifference(vector<int>& nums) {
		if (nums.size() == 1)
		{
			if (isPrime(nums.at(0)))
			{
				return 0;
			}
		}
			

		int left = 0;
		int right = nums.size() - 1;

		for (;left < nums.size();++left)
		{
			if (isPrime(nums.at(left)))
				break;
		}

		for (;right >= left;--right)
		{
			if (isPrime(nums.at(right)))
				break;
		}

		if (right == left)
		{
			return 0;
		}

		return right - left;
	}
};