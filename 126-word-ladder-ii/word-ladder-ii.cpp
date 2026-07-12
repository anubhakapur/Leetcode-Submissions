class Solution {
public:
    void dfs(string word,unordered_map<string,int>&levels,vector<string>&seq,vector<vector<string>>&res,string&beginWord){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            res.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int level=levels[word];
        for(int i=0;i<word.length();i++){
                char originalChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(levels.find(word) != levels.end() && levels[word]==level-1){
                        seq.push_back(word);
                        dfs(word,levels,seq,res,beginWord);
                        seq.pop_back();
                    }
                }
                word[i]=originalChar;
            }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_map<string,int>levels;
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>res;

        q.push(beginWord);
        st.erase(beginWord);
        levels[beginWord]=1;

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int level=levels[word];
            if(word==endWord)break;
            for(int i=0;i<word.length();i++){
                char originalChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        levels[word]=level+1;
                        st.erase(word);
                    }
                }
                word[i]=originalChar;
            }
        }
        if(levels.find(endWord)!=levels.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,levels,seq,res,beginWord);
        }
        return res;
    }
};