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
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next !=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *h=head;
        
        while(h!=slow->next){
            h=h->next;
        }
        slow->next=NULL;
        // h is head of second linked list ( reverse it)
        ListNode *prev=new ListNode(-1);
        ListNode *curr=h;
        ListNode *agla=curr->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=agla;
            if(curr!=NULL){
                agla=curr->next;
            }
        }
        h->next=NULL;

        ListNode *temp1=head;
        ListNode *temp2=prev;
        while (temp2 != NULL) {
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }
    }
};













// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution 
// {
// public:
//     void reorderList(ListNode* head) 
//     {
//         ListNode *first=head;
//         ListNode *agla=first->next;
//         ListNode *last=first->next;
//         ListNode*prev=first;
        
    

//         while(agla!=NULL && agla->next!=NULL ){
//             while(last->next!=NULL){
//                 last=last->next;
//                 prev=prev->next;  
//             }

//             last->next=first->next;
//             first->next=last;
//             prev->next=NULL;
//             first=agla;
//             agla=first->next;

//             if(first->next!=NULL){
//                 last=first->next;
//             }
//             if(first!=NULL){
//                 prev=first;
//             }
//         }

//     }
// };