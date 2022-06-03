class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(!s.size() || !words.size())
            return ans;
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        for(auto word:words)
        {
            mp1[word]++;
        }
        int len = words.size();
        int tl = words[0].size()*len;
        int sl = words[0].size();
        int i = 0;
        if(tl>s.size())
            return ans;
        while(i<=s.size()-tl)
        {
            
            string sub = s.substr(i,tl);
            int k = 0;
            int n = 0;
            while(k<words.size())
            {
                string temp = sub.substr(n,sl);
                mp2[temp]++;
                n += sl;
                k++;
            }
            if(mp2 == mp1)
                ans.push_back(i);
            mp2.clear();
            i++;
        }
        return ans;
    }
};
