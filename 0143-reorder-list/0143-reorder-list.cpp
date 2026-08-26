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
class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        ListNode *first=head;
        ListNode *agla=first->next;
        ListNode *last=first->next;
        ListNode*prev=first;
        
    

        while(agla!=NULL && agla->next!=NULL ){
            while(last->next!=NULL){
                last=last->next;
                prev=prev->next;  
            }

            last->next=first->next;
            first->next=last;
            prev->next=NULL;
            first=agla;
            agla=first->next;

            if(first->next!=NULL){
                last=first->next;
            }
            if(first!=NULL){
                prev=first;
            }
        }

    }
};