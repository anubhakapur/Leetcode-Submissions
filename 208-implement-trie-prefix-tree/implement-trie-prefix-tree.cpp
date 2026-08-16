struct Node{
    vector<Node*>links=vector<Node*>(26,NULL);
    bool endOfWord=false;
    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    void setKey(char c,Node* node){
        links[c-'a']=node;
    }
    Node* getKey(char c){
        return links[c-'a'];
    }
    void setEndOfWord(){
        endOfWord=true;
    }
    bool getEndOfWord(){
        return endOfWord;
    }
};

class Trie {
private:
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            char c=word[i];
            if(!node->containsKey(c)){
                node->setKey(c,new Node());
            }
            node=node->getKey(c);
        }
        node->setEndOfWord();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            char c=word[i];
            if(!node->containsKey(c)){
                return false;
            }
            node=node->getKey(c);
        }
        return node->getEndOfWord();
    }
    
    bool startsWith(string prefix) {
         Node* node=root;
        for(int i=0;i<prefix.length();i++){
            char c=prefix[i];
            if(!node->containsKey(c)){
                return false;
            }
            node=node->getKey(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */