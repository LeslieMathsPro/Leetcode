class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); //设置一个虚拟头节点
        dummyHead->next = head; //将虚拟节点指向head，这样后面方向做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur -> next -> next != nullptr){
            ListNode *tmp = cur->next; // 记录临时节点
            ListNode *tmp1 = cur->next->next->next; // 记录临时节点

            //步骤一
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;

            //步骤二
            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;

    }
};