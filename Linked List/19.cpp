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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != nullptr){
            fast = fast->next;
        }
        fast = fast->next; //fast需要再往前走一步，因为需要让slow指向删除的节点的上一个节点
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};