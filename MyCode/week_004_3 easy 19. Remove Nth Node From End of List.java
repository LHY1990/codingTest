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

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1204022310/

class Solution {
public ListNode removeNthFromEnd(ListNode head, int n) {
        
        Map<Integer, ListNode> indexMap = new HashMap<>();

        ListNode currentNode;
        currentNode = head;
        int index=0;
        while (currentNode != null) {
            indexMap.put(index++, currentNode);
            currentNode = currentNode.next;
        }

        int targetIndex = indexMap.size() - n;

        if (indexMap.size()==1) {
            return null;
        } else if (targetIndex == 0) {
            head = indexMap.get(1);
        } else {
            indexMap.get(targetIndex - 1).next = indexMap.get(targetIndex + 1);
        }


        return head;

    }
}