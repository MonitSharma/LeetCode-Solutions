class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; 
        vector<vector<string>> ans; 
        
        for(int i=0;i<strs.size();i++){
                string p = strs[i]; 
                sort(p.begin(), p.end()); 
                m[p].push_back(strs[i]);
        }
        
        for(auto it= m.begin();it!=m.end();it++){
            ans.push_back(it->second);
        }
     
        return ans;
    }
};