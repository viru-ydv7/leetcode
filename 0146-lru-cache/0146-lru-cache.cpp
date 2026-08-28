class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* previous = node->prev;
        Node* following = node->next;

        previous->next = following;
        following->prev = previous;
    }

    void insert(Node* node) {
        Node* last = tail->prev;

        last->next = node;
        node->prev = last;

        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);
        }
        else {
            Node* newnode = new Node(key, value);

            mp[key] = newnode;
            insert(newnode);

            if(mp.size() > capacity) {
                Node* lru = head->next;

                remove(lru);
                mp.erase(lru->key);
            }
        }
    }
};