//链表 最频繁的数据结构
//链表的机构很简单，它由指针把若干个节点连接成链状结构。
//由于链表是一种动态的数据结构，其操作需要对指针进行操作，因此应聘者需要有较好的编程功底才能写出完整的操作链表的代码。

//链表是一种动态数据结构，是因为在创建链表时，无须知道链表的长度。当插入一个节点时，我们只需要新节点分配内存。
//然后调整指针的指向来确保新节点被链接到链表当中。内存分配不是在创建链表时一次性完成，而是每添加一个节点分配一次内存。
//由于没有闲置的内存，链表的空间效率比数组要高。

//单向链表的结点定义：
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode() ;
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;
    if (*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while (pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}

void RemoveNode (ListNode** pHead, int value)
{
    if (pHead == NULL || *pHead == NULL)
        return;

    ListNode* pToBeDeleted = NULL;
    if ((*pHead) -> m_nValue == value)
    {
        pToBeDeleted = *pHead;

    }
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vec;
        if (head == NULL) return vec;
        while (head!=NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> sta;
        ListNode* pNode = head;
        vector<int> vec;
        while (pNode != NULL)
        {
            sta.push(pNode->val);
            pNode = pNode->next;
        }
        while (!sta.empty()){
            vec.push_back(sta.top());
            sta.pop();
        }
        return vec;
    }
};

//根据递归与栈的关系
