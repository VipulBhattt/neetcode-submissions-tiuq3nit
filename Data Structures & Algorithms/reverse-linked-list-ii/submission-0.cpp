/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevLeft = dummy;
        for (int i = 0; i < left-1 ; i++) {
            prevLeft = prevLeft->next;
        }
        ListNode* curr = prevLeft->next;
        ListNode* prev = NULL;
        for (int i = left; i <= right; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* lft = prevLeft->next;
        prevLeft->next = prev;
        lft->next = curr;
        return dummy->next;
    }
};