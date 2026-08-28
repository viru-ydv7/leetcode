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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>,
               vector<pair<int, ListNode*>>,
               greater<pair<int, ListNode*>>> q;

        for(auto it:lists){
            while(it!=NULL){
                q.push({it->val,it});
                it=it->next;
            }
        }
        ListNode *head=NULL;
        ListNode *tail=NULL;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            ListNode *node=it.second;
            if(head==NULL){
                head=node;
                tail=node;
            }
            else{
                tail->next=node;
                tail=node;
            }

        }
        return head;               

        
    }
};