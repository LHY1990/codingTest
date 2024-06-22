// https://leetcode.com/problems/construct-the-rectangle/description/

class Solution {
public:
	vector<int> constructRectangle(int area) {
        if (area==1)
            return vector<int>({1,1});

		int width;
		int length;

		const int half = area / 2;

		int rLength;
		int rWidth;
		int diff = INT_MAX;


		for (int i = 1; i <= half;++i)
		{
			if (area % i == 0)
			{
				width = i;
				length = area / width;

				if (diff > abs(width - length))
				{
					rWidth = width;
					rLength = length;
                    diff = abs(width - length);
				}
			}
		}

		return vector<int>({ rLength, rWidth });
	}
};