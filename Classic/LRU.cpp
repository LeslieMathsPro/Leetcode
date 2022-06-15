#include <iostream>
#include <unordered_map>

using std::unordered_map;

struct DLinkNode {
    int key, value;
    DLinkNode* prev;
    DLinkNode* next;
    //构造函数，便于新定义节点时初始化对象
    DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    unordered_map<int, DLinkNode*> map;
    DLinkNode* head;
    DLinkNode* tail;
    int size; //缓冲区使用的大小
    int capacity; //缓冲区的容量

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        //使用伪头部和伪尾部节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //需求1 如果key不存在于缓存中，返回-1
        if (!map.count(key)) return -1;
        //需求2 如果key存在，先通过hash表定位，再移到头部
        DLinkNode* node =  map[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        //需求1 如果key不在缓存中，创建一个新的节点
        if (!map.count(key)) {
            DLinkNode* node = new DLinkNode(key, value);
            //添加进hash表
            map[key] = node;
            //添加至双向链表的头部
            addToHead(node);
            //考虑缓存size
            size++;
            if (size > capacity) {
                DLinkNode* removed = removeTail(); //如果超出容量，删除双向链表的尾部节点
                map.erase(removed->key); //删除哈希表中对应的项
                delete removed; //防止内存泄漏
                size--;
            } 
        } else 
        //需求2 如果key在缓存中，更新value的值，并移到头部
        {
            DLinkNode* node = map[key];
            node->value = value;
            moveToHead(node);
        }
    }

//定义双向链表需要用到的API函数
public:
    void addToHead(DLinkNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DlinkNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkNode* removeTail() {
        DLinkNode* node = tail->prev; //40 10 14 4
        removeNode(node);
        return node;
    }
};