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

        ListNode*start=head;
        ListNode*end=head;
        ListNode*nextNode=head->next;
        while(true){
            int c=1;
            while(c<k && end!=nullptr){
                end=end->next;
                c++;
            }
            if(end==nullptr || c<k)break;
            nextNode=end->next;
            reverseLL(start,end);
            //swap(ListNode*start,ListNode*end);
            ListNode*temp=start;
            start=end;
            end=temp;

            if(prev)prev->next=start;
            end->next=nextNode;
            prev=end;
            end=end->next;
            start=end;
        }
        return dummy->next;
    }
};