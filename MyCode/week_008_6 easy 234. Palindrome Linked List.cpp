// https://leetcode.com/problems/palindrome-linked-list/description/

class Solution {
public:

    bool isPalindrome(ListNode* head) {
        deque<int> myDeque = deque<int>();
        while (head != nullptr)
        {
            myDeque.push_back(head->val);
            head = head->next;
        }

        while (false == myDeque.empty() && myDeque.size()>1)
        {
            if (myDeque.front() == myDeque.back())
            {
                myDeque.pop_front();
                myDeque.pop_back();
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};