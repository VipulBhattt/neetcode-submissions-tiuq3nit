class MyCircularQueue {
   public:
    class ListNode {
       public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            next = NULL;
        }
    };
    int size;
    int fill;
    ListNode* prev;
    ListNode* start;

    MyCircularQueue(int k) {
        size = k;
        fill = 0;
        prev = NULL;
        start = NULL;
    }

    bool enQueue(int value) {
        if (fill == size)
            return false;
        else {
            fill++;
            ListNode* nxt = new ListNode(value);
            if (start == NULL) {
                start = nxt;
                prev = nxt;
            } else {
                prev->next = nxt;
                prev = prev->next;
            }
        }
        return true;
    }

    bool deQueue() {
        if(!start) return false;
        while (start) {
            start = start->next;
            if(!start) prev = NULL;
            fill--;
            return true;
        }
        return false;
    }

    int Front() {
        if (!start) {
            return -1;
        }
        return start->val;
    }

    int Rear() {
        if (!prev) {
            return -1;
        }
        return prev->val;
    }

    bool isEmpty() { return (!start); }

    bool isFull() { return (fill == size); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */