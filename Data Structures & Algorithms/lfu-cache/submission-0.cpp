class LFUCache {
   public:
    class node {
       public:
        int key;
        int val;
        int freq;
        node* prev;
        node* next;

        node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };

    class List {
       public:
        int size;
        node* head;
        node* tail;

        List() {
            size = 0;
            head = new node(0, 0);
            tail = new node(0, 0);

            head->next = tail;
            tail->prev = head;
        }

        void addFront(node* temp) {
            node* nxt = head->next;

            temp->next = nxt;
            temp->prev = head;

            head->next = temp;
            nxt->prev = temp;

            size++;
        }

        void removeNode(node* temp) {
            node* delPrev = temp->prev;
            node* delNext = temp->next;

            delPrev->next = delNext;
            delNext->prev = delPrev;

            size--;
        }
    };

    unordered_map<int, node*> keyNode;
    unordered_map<int, List*> freqNode;

    int minFreq;
    int curr;
    int cap;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        curr = 0;
    }

    void updateFreq(node* temp) {
        keyNode.erase(temp->key);

        freqNode[temp->freq]->removeNode(temp);

        if (temp->freq == minFreq && freqNode[temp->freq]->size == 0) {
            minFreq++;
        }

        temp->freq++;

        List* nextList;

        if (freqNode.find(temp->freq) != freqNode.end()) {
            nextList = freqNode[temp->freq];
        } else {
            nextList = new List();
            freqNode[temp->freq] = nextList;
        }

        nextList->addFront(temp);

        keyNode[temp->key] = temp;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        node* temp = keyNode[key];

        int ans = temp->val;

        updateFreq(temp);

        return ans;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            node* temp = keyNode[key];

            temp->val = value;

            updateFreq(temp);
        } else {
            if (curr == cap) {
                List* list = freqNode[minFreq];

                keyNode.erase(list->tail->prev->key);

                list->removeNode(list->tail->prev);

                curr--;
            }

            curr++;

            minFreq = 1;

            List* listFreq;

            if (freqNode.find(minFreq) != freqNode.end()) {
                listFreq = freqNode[minFreq];
            } else {
                listFreq = new List();
                freqNode[minFreq] = listFreq;
            }

            node* temp = new node(key, value);

            listFreq->addFront(temp);

            keyNode[key] = temp;
        }
    }
};