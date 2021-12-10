class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;

        while (curA != nullptr){ //求链表A的长度
            curA = curA->next;
            lenA++;
        }

        while (curB != nullptr){ //求链表B的长度
            curB = curB->next;
            lenB++;
        }

        curA = headA;
        curB = headB;

        //让curA为较长链表的头，lenA为其长度
        if (lenB > lenA){
            swap(curA, curB);
            swap(lenA, lenB);
        }
        
        //求长度差
        int gap = lenA - lenB;
        //让curA和curB在同一起点上（末尾位置对齐）
        while (gap--){
            curA = curA->next;
        }

        //遍历curA和curB，遇到相同值则返回
        while (curA != NULL){
            if (curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};