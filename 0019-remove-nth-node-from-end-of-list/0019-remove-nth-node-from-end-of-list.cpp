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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        if(n==l){
            return head->next;
        }
        int p=l-n-1;
        int k=0;
        ListNode *a=head;
        ListNode *b=head->next;
        while(k!=p && a!=NULL && b!=NULL){
            if(a!=NULL){
                a=a->next;
            }
            if(b!=NULL){
                b=b->next;
            }
            k++;
        }
        if(b!=NULL){
            a->next=b->next;
        }
        else{
            return NULL;
        }
        return head;
        
    }
};