class LRUCache {
public:
    class Node
    {
        public:
            int key;
            int value;
            Node *prev;
            Node  *next;

            Node(int k,int value){
                key=k;
                this->value=value;
                prev=NULL;
                next=NULL;
            }
    };
    int capacity;
    unordered_map<int,Node*>mp;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        this->capacity=capacity;
        head = new Node(-1,-1);
        tail=new Node (-1,-1);

        head->next=tail;
        tail->prev=head;
    }
    void insert(Node*node){
        Node *last=tail->prev;
        last->next=node;
        node->prev=last;
        
        node->next=tail;
        tail->prev=node;
    }
    void remove(Node*node){
        Node *pichla=node->prev;
        Node *agla=node->next;
        pichla->next=agla;
        agla->prev=pichla;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *node=mp[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            node->value=value;

            remove(node);
            insert(node);
        }
        else{
            Node *newnode=new Node(key,value);

            mp[key]=newnode;
            insert(newnode);
            if(mp.size()>capacity){
                Node* lru = head->next;

                remove(lru);
                mp.erase(lru->key);
            }


        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */