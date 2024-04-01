// https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == nullptr)
			return false;

		ListNode* current=head->next;
		if (current == nullptr)
			return false;

		set<ListNode*> dupSet = set<ListNode*>();

		while (current != nullptr)
		{
			if (dupSet.find(current) != dupSet.end())
				return true;

			dupSet.insert(current);

			current = current->next;

		}

		return false;
	}
};