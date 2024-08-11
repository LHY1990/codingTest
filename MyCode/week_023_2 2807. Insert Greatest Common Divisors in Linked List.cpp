// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/submissions/1309179826/

class Solution {
public:
	int getMax(const int& _left, const int& _right)
	{
		int min = _left > _right ? _right : _left;

		for (int i = min; i > 0;--i)
		{
			if (_left % i == 0 && _right % i == 0)
				return i;
		}

		return 1;
	}

	void dfs(ListNode* _node)
	{
		if (_node == nullptr)
			return;

		if (_node->next == nullptr)
			return;

		int max = getMax(_node->val, _node->next->val);
		ListNode* nextPtr = _node->next;
		auto newNode = new ListNode(max);
		_node->next = newNode;
		newNode->next = nextPtr;

		dfs(nextPtr);
	}

	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		if (head == nullptr)
			return head;

		dfs(head);


		return head;
	}
};