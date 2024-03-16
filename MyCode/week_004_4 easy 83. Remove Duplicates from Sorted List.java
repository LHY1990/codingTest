/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/1204007845/

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode preNode = head;
        ListNode lastNode = head;

        int i=0;
        while (lastNode != null) {
            if (preNode.val == lastNode.val) {
                lastNode = lastNode.next;
                if (lastNode==null)
                    preNode.next = null;
            }else{
                preNode.next = lastNode;
                preNode = lastNode;
                lastNode = lastNode.next;
            }
        }

        return head;
    }
}