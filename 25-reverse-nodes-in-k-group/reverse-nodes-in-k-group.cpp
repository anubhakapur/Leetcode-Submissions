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
    void reverseLL(ListNode*start,ListNode*end){
        ListNode*curr=start;
        ListNode*prev=nullptr;
        ListNode*endNext=end->next;
        while(curr && curr!=endNext){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        ListNode*dummy=new ListNode(-1);
        ListNode*prev=dummy;
        prev->next=head;

        while(true){
            ListNode*end=prev;
            for(int i=0;i<k;i++){
                end=end->next;
                if(end==nullptr)return dummy->next;
            }
            ListNode*start=prev->next;
            ListNode*nextNode=end->next;
            reverseLL(start,end);

            prev->next=end;
            start->next=nextNode;
            prev=start;
        }
        return dummy->next;
    }
};