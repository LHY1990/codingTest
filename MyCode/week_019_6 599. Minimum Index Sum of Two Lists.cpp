// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		auto outList = vector<string>(0);

		auto filter = map<string, int>();
		int min = 100000;

		for (int i=0;i<list1.size();++i)
		{
			for (int j=0;j<list2.size();++j)
			{
				if ((list1.at(i).size() == list2.at(j).size()) && list1.at(i).compare(list2.at(j)) == 0)
				{
					filter[list1.at(i)] = i + j;
					if (min > i + j)
						min = i + j;

					break;//안에 반복문 탈출
				}
			}
		}

		for (auto single : filter)
		{
			if (single.second == min)
				outList.push_back(single.first);
		}

		return outList;
	}
};