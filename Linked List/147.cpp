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
    ListNode* insertionSortList(ListNode* head) {
        //首先判断给定的链表是否为空，若为空，则不需要进行排序，直接返回。
        if (head == nullptr) {
            return;
        }
        //创建哑节点 dummyHead，令 dummyHead.next = head。引入哑节点是为了便于在 head 节点之前插入节点。
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        //维护 lastSorted 为链表的已排序部分的最后一个节点，初始时 lastSorted = head。
        ListNode* lastSorted = head;
        //维护 curr 为待插入的元素，初始时 curr = head.next。
        ListNode* curr = head->next;
        while (curr) {
            if (lastSorted->val <= cur->val){
                lastSorted = lastSorted->next;
            } else {
                ListNode* prev = dummyHead;
                while(prev->next->val <= curr->next){
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;                
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};