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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if(count == 1){
            return NULL;
        }
        if (count == n) {
            head = head->next;
        } else {
            int v = count - n;
            ListNode* curr = head;
            for (int i = 1; i < v; i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};
