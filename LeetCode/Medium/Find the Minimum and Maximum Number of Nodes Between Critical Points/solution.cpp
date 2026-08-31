class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        int f=-1,l=-1,m=INT_MAX,i=1;
        ListNode *p=h,*c=h->next;
        
        while(c->next){
            if((c->val>p->val&&c->val>c->next->val)||(c->val<p->val&&c->val<c->next->val)){
                if(f==-1) f=i;
                else m=min(m,i-l);
                l=i;
            }
            p=c;
            c=c->next;
            i++;
        }
        
        if(f==l||f==-1) return {-1,-1};
        return {m,l-f};
    }
};