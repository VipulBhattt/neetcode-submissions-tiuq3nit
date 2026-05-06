class LRUCache {
   public:
    class ListNode {
       public:
        ListNode* prev;
        int key;
        int val;
        ListNode* next;

        ListNode(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    int count;
    ListNode* curr;
    ListNode* least;
    unordered_map<int, ListNode*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        curr = NULL;
        least = NULL;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        ListNode* node = mp[key];

        if (node == curr) return node->val;

        if (node == least) {
            least = least->prev;
            if (least) least->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = NULL;
        node->next = curr;
        if (curr) curr->prev = node;
        curr = node;

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode* node = mp[key];
            node->val = value;

            if (node != curr) {
                if (node == least) {
                    least = least->prev;
                    if (least) least->next = NULL;
                } else {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                node->prev = NULL;
                node->next = curr;
                if (curr) curr->prev = node;
                curr = node;
            }
            return;
        }

        ListNode* node = new ListNode(key, value);

        if (count == 0) {
            curr = least = node;
            count++;
        } else if (count < cap) {
            node->next = curr;
            curr->prev = node;
            curr = node;
            count++;
        } else {
            mp.erase(least->key);

            if (least->prev) {
                least = least->prev;
                least->next = NULL;
            }

            node->next = curr;
            curr->prev = node;
            curr = node;
        }

        mp[key] = node;
    }
};