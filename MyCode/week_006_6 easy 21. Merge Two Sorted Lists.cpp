// https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr)
			return list2;
		else if (list2 == nullptr)
			return list1;
		
		ListNode* firstCurrent = list1;
		ListNode* secondCurrent = list2;
		ListNode* head = new ListNode();
		ListNode* current = head;

		while (firstCurrent != nullptr || secondCurrent != nullptr)
		{
			if (firstCurrent == nullptr)
			{
				current->next = secondCurrent;
				secondCurrent = secondCurrent->next;
				current = current->next;
			}
			else if (secondCurrent == nullptr)
			{
				current->next = firstCurrent;
				firstCurrent = firstCurrent->next;
				current = current->next;
			}
			else {// both exist
				if (firstCurrent->val >= secondCurrent->val)
				{
					current->next = secondCurrent;
					secondCurrent = secondCurrent->next;
					current = current->next;
				}
				else {
					current->next = firstCurrent;
					firstCurrent = firstCurrent->next;
					current = current->next;
				}
			}
		}

		return head->next;

	}
};

