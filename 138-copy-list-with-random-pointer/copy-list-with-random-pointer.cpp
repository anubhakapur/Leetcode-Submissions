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
        unordered_map<Node*,Node*>nodes;
        nodes[nullptr]=nullptr;
        Node*temp=head;
        while(temp){
            if(nodes.find(temp)==nodes.end()){
                nodes[temp]=new Node(temp->val);
            }
            if(nodes.find(temp->next)==nodes.end()){
                nodes[temp->next]=new Node(temp->next->val);
            }
            if(nodes.find(temp->random)==nodes.end()){
                nodes[temp->random]=new Node(temp->random->val);
            }
            nodes[temp]->next=nodes[temp->next];
            nodes[temp]->random=nodes[temp->random];
            temp=temp->next;
        }
        return nodes[head];
    }
};