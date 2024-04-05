// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
	int getArea(const vector<int>& inputList, const int& leftIndex, const int& rightIndex)
	{
		int maxHeight = inputList.at(leftIndex) > inputList.at(rightIndex) ? inputList.at(rightIndex) : inputList.at(leftIndex);
		return maxHeight * (rightIndex - leftIndex);
	}

	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max = 0;
		int temp = 0;

		while (left != right)
		{
			temp = getArea(height, left, right);
			if (max < temp)
				max = temp;

			height.at(left) < height.at(right) ? ++left : --right;
		}

		return max;
	}
};