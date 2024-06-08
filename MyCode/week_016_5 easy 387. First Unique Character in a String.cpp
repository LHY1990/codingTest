// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1276112739/

class Solution {
public:
	int firstUniqChar(string s) {
		auto indexMap = map<int, char>(); // 위치, char

		auto deleteChecker = set<char>();
		auto checker = set<char>();

		for (int i = 0;i < s.size();++i)
		{
			//최초 등록시
			if (checker.find(s.at(i)) == checker.end())
			{
				indexMap[i] = s.at(i);
			}
			else
			{
				//중복 등록시
				deleteChecker.insert(s.at(i));
			}

			// 중복 등록
			checker.insert(s.at(i));
		}

		int result = -1;
		for (auto iter : indexMap)
		{
			//중복이면 패스
			if (deleteChecker.find(iter.second) != deleteChecker.end())
				continue;

			if (checker.find(iter.second) != checker.end())
				return iter.first;
		}


		return result;
	}
};