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
    ListNode* rev(ListNode* head, ListNode* back) {
        ListNode* bound = back->next;
        ListNode* temp = head;
        ListNode* prev = bound;

        while (temp != bound) {
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int tc = 1;

        ListNode* front = head;
        ListNode* temp = head;

        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;

        while (temp) {
            if (tc < k) {
                temp = temp->next;
                tc++;
            } else {
                ListNode* back = temp;
                ListNode* nxt = back->next;

                ListNode* revHead = rev(front, back);

                if (!newHead) newHead = revHead;

                if (prevTail) {
                    prevTail->next = revHead;
                }

                prevTail = front;

                front = nxt;
                temp = nxt;
                tc = 1;
            }
        }

        return newHead ? newHead : head;
    }
};