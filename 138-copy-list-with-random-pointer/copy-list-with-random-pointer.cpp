/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        Node*l1=head;
        while(l1){
            Node* nn=new Node(l1->val);
            nn->next=l1->next;
            l1->next=nn;
            l1=nn->next;
        }
        l1=head;
        Node*newHead=l1->next;
        Node*l2=newHead;
        while(l1){
            if(l1->random)l2->random=l1->random->next;
            if(l2->next){
                l2=l2->next->next;
            }
            if(l1->next)l1=l1->next->next;
        }
        l2=newHead;
        l1=head;
        //have to restore both lists
        while(l1){
            l1->next=l2->next;
            if(l2->next)l2->next=l2->next->next;
            l1=l1->next;
            l2=l2->next;
        }
        return newHead;
    }
};