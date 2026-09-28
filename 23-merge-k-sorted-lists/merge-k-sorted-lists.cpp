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
        ListNode* head=new ListNode(-1);
        ListNode*temp=head;
        while(true){
            int minNodeIdx=-1;
            for(int i=0;i<lists.size();i++){
                if(lists[i]==nullptr)continue;
                if(minNodeIdx==-1 || lists[i]->val<lists[minNodeIdx]->val){
                    minNodeIdx=i;
                }
            }
            if(minNodeIdx==-1)break;
            ListNode*nn=new ListNode(lists[minNodeIdx]->val);
            temp->next=nn;
            temp=nn;
            lists[minNodeIdx]=lists[minNodeIdx]->next;
        }
        return head->next;
    }
};