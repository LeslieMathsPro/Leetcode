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
    ListNode* rotateRight1step(ListNode* head) {
        ListNode* dummy = head;
        //取head尾巴
        while(dummy->next)
        {
            dummy = dummy->next;
        }
        ListNode* tail = dummy;
        //拆掉head的尾巴
        ListNode* temp = head;
        while(temp->next->next)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        //放在head头
        ListNode* result = tail;
        tail->next = head;
        return result;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k = 0) return head;
        if(head->next == nullptr) return head;
        //count the number of Node in ListNode* head
        int N = 1;
        while (head->next) 
        {
            N++;
            head->next;
        }
        //reduce the running time
        if (N < k) 
        {
            k = N%k;
        }
        //重复k次rotateRight1step
        while(k--)
        {
            head = rotateRight1step(head);
        }
        return head;
    }
};


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k = 0) return head;
        if(head->next == nullptr) return head;
        //count the number of Node in ListNode* head
        int N = 1;
        while (head->next) 
        {
            N++;
            head->next;
        }
        //reduce the running time
        if (N < k) 
        {
            k = N%k;
        }
    }
};