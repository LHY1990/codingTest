// https://leetcode.com/problems/range-sum-query-immutable/submissions/1275899427/

class NumArray {
public:
	vector<int>* __list;
	NumArray(vector<int>& nums) {
		__list = &nums;
	}

	int sumRange(int left, int right) {
		int result = 0;
		for (int i = left;i <= right;++i)
			result += __list->at(i);

		return result;
	}
};