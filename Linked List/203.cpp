class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); //设置一个虚拟头节点 
        dummyHead->next = head;//将虚拟头节点指向head，这样方便后面做删除操作
        ListNode* curr = dummyHead;
        while (curr->next != NULL){
            if (curr->next->val == val){
                ListNode *tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }else{
                curr = curr->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;        
    }
};