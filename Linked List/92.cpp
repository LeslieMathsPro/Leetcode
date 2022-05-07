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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;
        //要注意不是更换值，而是更换链表结点
        //ListNode* leftNode, rightNode;
        ListNode* dummy = head;
        int left1 = left;
        int right1 = right;
        while(left1--)
        {
            dummy = dummy->next;
            right1--;
        }
        ListNode* leftNode = dummy;
        leftNode->next = nullptr;
        while(right1--)
        {
            dummy = dummy->next;
        }
        ListNode* rightNode = dummy;
        rightNode->next = nullptr;

        //要拆分成 前中后三段
        ListNode* temp = head;
        //ListNode* pre, mid, end;
        int left2 = left;
        int right2 = right;
        ListNode* pre = temp;
        while(left2--)
        {
            temp = temp->next;
        }
        ListNode* temp2 = temp->next->next;
        temp->next = nullptr;
        ListNode* mid = temp2;
        int right3 = right2 - left2 - 1;
        while(right3--)
        {
            temp2 = temp2->next;
        }
        ListNode* temp3 = temp2->next->next;
        temp2->next = nullptr;
        ListNode* end = temp3;

        //串起来
        ListNode* result = pre;
        while (pre->next)
        {
            pre = pre->next;
        }
        pre->next = leftNode;
        pre->next->next = mid;
        while (pre->next)
        {
            pre = pre->next;
        }
        pre->next = rightNode;
        pre->next->next = end;
        return result;
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
    ListNode* reverseN(ListNode *head, int n)
    {
        ListNode* successor = nullptr; //后驱节点
        if(n == 1)
        {
            //记录第n+1个节点
            successor = head->next;
            return head;
        }
        //以head->next为起点，需要反转前n-1个节点
        ListNode* last = reverseN(head->next, n-1);

        head->next->next = head;
        //让反转后的head节点和后面的节点连起来
        head->next = successor;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //base case
        if (left == 1) return reverseN(head, right);
        //前进到反转的起点，触发base case
        head->next = reverseBetween(head, left-1, right-1);
        return head;
    }
};