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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *head=NULL;
        ListNode *tail=NULL;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int total=temp1->val+temp2->val+carry;
            int sum=total%10;
            carry=total/10;
            if(head==NULL){
                ListNode *temp=new ListNode(sum);
                head=temp;
                tail=temp;
            }
            else{
                ListNode *temp=new ListNode(sum);
                tail->next=temp;
                tail=temp;  
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int total=temp1->val+carry;
            int sum=total%10;
            carry=total/10;
            if(head==NULL){
                ListNode *temp=new ListNode(sum);
                head=temp;
                tail=temp;
            }
            else{
                ListNode *temp=new ListNode(sum);
                tail->next=temp;
                tail=temp;  
            }
            temp1=temp1->next;
        }



        while(temp2!=NULL){
            int total=temp2->val+carry;
            int sum=total%10;
            carry=total/10;
            if(head==NULL){
                ListNode *temp=new ListNode(sum);
                head=temp;
                tail=temp;
            }
            else{
                ListNode *temp=new ListNode(sum);
                tail->next=temp;
                tail=temp;  
            }
            temp2=temp2->next;
        }

        while(carry!=0){
            ListNode *temp=new ListNode(carry);
            tail->next=temp;
            tail=temp;
            carry--;
        }

        return head;


        
    }
};