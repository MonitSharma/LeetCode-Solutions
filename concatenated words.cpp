struct trie{
    trie* ptr[26];
    bool isword;
    trie(){
        for(int i=0;i<26;i++)ptr[i] = NULL;
        isword = false;
    }
};

typedef trie* tptr;
void insert(tptr t,string s){
    for(int i=0;i<s.length();i++){
        if(!t->ptr[s[i]-'a'])t->ptr[s[i]-'a'] = new trie();
        t = t->ptr[s[i]-'a'];
    }
    t->isword = true;
}
bool morethan2(tptr root,string s,int i=0,int cnt=1){
    tptr t = root;
    for(int j=i;j<s.length();j++){
        if(!t->ptr[s[j]-'a'])return false;
        t = t->ptr[s[j]-'a'];
        if(t->isword && morethan2(root,s,j+1,cnt+1))return true;
    }
    return (t->isword && cnt>1);
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        tptr t = new trie();
        int n = words.size();
        for(string s : words)if(!s.empty())insert(t,s);
        vector<string>ans;
        for(string s : words){
            if(morethan2(t,s))ans.emplace_back(s);
        }
        
        return ans;
    }
};
