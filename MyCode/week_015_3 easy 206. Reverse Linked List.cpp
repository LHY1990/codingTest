// https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:
	stack<ListNode*> list = stack<ListNode*>();

	void dfs(ListNode* _node)
	{
		if (_node == nullptr)
			return;

		list.push(_node);

		dfs(_node->next);
	}

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;

		dfs(head);

		ListNode* currentNode = list.top();
		ListNode* firstNode = currentNode;
		list.pop();
		while (currentNode != nullptr)
		{
			if (list.empty())
			{
				currentNode->next = nullptr;
				break;
			}
			else
			{
				currentNode->next = list.top();
				currentNode = currentNode->next;
				list.pop();
			}

		}

		return firstNode;
	}
};