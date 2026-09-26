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
        if(!head)return;
        vector<int>nums;
        ListNode*temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        ListNode*res=new ListNode(-1);
        temp=res;
        ListNode*nn=new ListNode(nums[0]);
        temp->next=nn;
        temp=nn;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(i<j){
                nn=new ListNode(nums[j]);
                temp->next=nn;
                temp=nn;
                i++;
            }
            if(i<j){
                nn=new ListNode(nums[i]);
                temp->next=nn;
                temp=nn;
                j--;
            }
        }
        res=res->next;
        temp=head;
        while(res){
            temp->val=res->val;
            temp=temp->next;
            res=res->next;
        }
    }
};