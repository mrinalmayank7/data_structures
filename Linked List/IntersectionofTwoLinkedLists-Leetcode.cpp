/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack <ListNode*> S1, S2;
        ListNode *p=headA, *q=headB,*intersection=NULL;
        while(p!=NULL){
            S1.push(p);
            p=p->next;
        }
        while(q!=NULL){
            S2.push(q);
            q=q->next;
        }
        while(!S1.empty() && !S2.empty()){
            if(S1.top()==S2.top()){
                intersection=S1.top();
                S1.pop();
                S2.pop();
            }
            else{
                break;
            }
        }
        return intersection;
    }
};
