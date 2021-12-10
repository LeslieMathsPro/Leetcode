// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         while (curr) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
// };


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode* newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }
// };

//双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; //保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};