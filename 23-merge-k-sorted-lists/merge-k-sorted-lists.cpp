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

struct compare{
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        ListNode*head=new ListNode(-1);
        ListNode*temp=head;
        while(true){
            for(int i=0;i<lists.size();i++){
                if(lists[i]==nullptr)continue;
                pq.push(lists[i]);
                lists[i]=lists[i]->next;
            }
            if(pq.empty())break;
            ListNode*nn=new ListNode(pq.top()->val);
            temp->next=nn;
            temp=nn;
            pq.pop();
        }
        return head->next;
    }
};