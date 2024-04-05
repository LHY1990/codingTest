// https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode* pOut = head;
		bool hasNext = false;
		int tempValue=0;

		while (l1 != nullptr || l2 != nullptr)
		{
			

			if (l1 == nullptr)
			{
				tempValue += l2->val;
				l2 = l2->next;
			}
			else if (l2 == nullptr)
			{
				tempValue += l1->val;
				l1 = l1->next;
			}
			else 
			{
				tempValue += (l1->val + l2->val);
				l2 = l2->next;
				l1 = l1->next;
			}

			head->val = tempValue % 10;
			tempValue = tempValue / 10;

			if (l2 != nullptr || l1 != nullptr)
			{
				head->next = new ListNode();
				head = head->next;
			}
			else if (l1 == nullptr && l2 == nullptr && tempValue >= 1)
			{
				head->next = new ListNode(tempValue);
				head = head->next;
				return pOut;
			}
		}


		return pOut;
	}
};