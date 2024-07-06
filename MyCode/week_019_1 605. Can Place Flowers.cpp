// https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (flowerbed.size() == 0 && n>=1)
			return false;
        else if (flowerbed.size()==0 && n==0)
            return true;
		else if (flowerbed.size() == 1 && flowerbed.at(0) == 0 && n <= 1)
			return true;
		else if (flowerbed.size() == 1 && flowerbed.at(0) == 1 && n!=0)
			return false;
        else if (n == 0)
			return true;

		auto left = false;
		auto middle = false;
		auto right = false;

		int count = 0;

		for (int pos = 0;pos < flowerbed.size();++pos)
		{
			if (flowerbed.at(pos) == 1)
				continue;

			left = false;
			right = false;
			middle = flowerbed.at(pos) == 0 ? true : false;

			if (pos - 1 < 0 || flowerbed.at(pos - 1) == 0)
				left = true;

			if (pos + 1 >= flowerbed.size() || flowerbed.at(pos + 1) == 0)
				right = true;

			if (left && middle && right)
			{
				flowerbed.at(pos) = 1;
				++count;
			}

		}

		if (count >= n)
			return true;

		return false;
	}
};