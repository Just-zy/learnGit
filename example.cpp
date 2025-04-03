#include<iostream>
#include<unordered_map>
using namespace std;
//windows记录
//设计一个LRU
// L| 1, 4, 5 |R
class LRUCache{
public:
    struct Node{
        int key, value;
        Node* prev, *next;
        Node(int k, int v):key(k),value(v), prev(nullptr), next(nullptr){}
    }
    
    Node* L, *R;
    unodered_map<int, Node*> myMap;
    int n;
    
    LRUCache(int capacity)
    {
        n = capcity;
        L = new Node(-1);
        R = new Node(-1);
        L->next = R;
        R->prev = L;
    }
    
    int get(int key)
    {
        if(myMap.count(key))
        {
            Node* node = myMap[key];
            remove(node);
            insert(node->key, node->value);
            return node->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value)
    {
        if(myMap.count(key))
        {
            Node* node = myMap[key];
            remove(node);
            insert(key, value);
        }else{
            if(n == myMap.size())
            {
                Node* first = L->next;
                remove(first);
                insert(key, value);
            }else{
                insert(key, value);
            }
        }
    }
    
    void remove(Node* node)
    {
        Node* prv = node->prev;
        Node* nxt = node->next;
        
        prv->next = nxt;
        nxt->prev = prv;
        myMap.earse(node->key);
    }
    
    void insert(int key, int value)
    {
        Node* node = new Node(key, value);
        Node* prv = R->prev;
        Node* nxt = R;
        
        prv->next = node;
        node->next = nxt;
        
        nxt->prev = node;
        node->prev = prv;
        myMap[key] = node;
    }
    
    
    
};










int main()
{
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cache.put(3,3);
    int flag = 0;
    flag = cache.get(2);
    cout << flag << endl;
    
    cache.put(4,4);
    
    cout << cache.get(2) << endl;
}
