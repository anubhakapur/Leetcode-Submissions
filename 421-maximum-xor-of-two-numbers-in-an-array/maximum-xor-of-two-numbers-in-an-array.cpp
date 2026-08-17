struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
    Node*get(int bit){
        return links[bit];
    }
};
class Trie{
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMaxXor(int num){
        Node*node=root;
        int maxXor=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                node=node->get(1-bit);
                maxXor=maxXor | (1<<i);//set the bit
            }else{
                node=node->get(bit);
            }
        }
        return maxXor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie=new Trie();
        for(int &n:nums)trie->insert(n);
        int maxXor=0;
        for(int &n:nums){
            maxXor=max(maxXor,trie->getMaxXor(n));
        }
        return maxXor;
    }
};