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
    ListNode* mergeTwoLists(ListNode* a,ListNode* b) {
        ListNode d(0);
        ListNode* t=&d;
        while(a&&b){
            if(a->val<=b->val)
            {
                t->next=a;
                a=a->next;
            }
            else
            {
                t->next=b;
                b=b->next;
            }
            t=t->next;
        }
        t->next=a?a:b;
        return d.next;
    }
};
