class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummyHead = new ListNode(0); // 设置虚头节点
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;
        while (n!=0) {
            fast = fast->next;
            n--;
        }
        while (fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return head;
    }
};