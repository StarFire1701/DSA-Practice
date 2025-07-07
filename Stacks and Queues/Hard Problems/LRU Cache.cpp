class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>mpp;

   LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deletenode(Node*delnode){
        Node*delprev = delnode->prev;
        Node*delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    void insertnode(Node*newnode){
        Node*temp = head->next;
       newnode->next = temp;
       newnode->prev = head;
       head->next = newnode;
       temp->prev = newnode;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* resnode=mpp[key];
            int res=resnode->val;
            deletenode(resnode);
            insertnode(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* existing_node=mpp[key];
            existing_node->val=value;
            deletenode(existing_node);
            mpp.erase(key);
            insertnode(existing_node);
            mpp[key]=head->next;
        } else if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
            insertnode(new Node(key,value));
            mpp[key]=head->next;
        
        }
        else{
            insertnode(new Node(key,value));
             mpp[key]=head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */