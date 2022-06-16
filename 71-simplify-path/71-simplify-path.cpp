class Solution {
public:
    string simplifyPath(string path) {
        vector<string> lks;
        for (int i = 0; i < path.length();) {
            if (path[i] != '/') {
                string dir = "";
                while (i < path.length() && path[i] != '/') dir+=path[i++];
                if(dir == ".."){
                    if(lks.size())
                        lks.pop_back();
                }
                else if (dir != ".") {
                    lks.push_back(dir);
                }
            }
            else ++i;
        }
        string ans="";
        for(string x : lks) ans += "/"+ x;
        return !ans.length() ? "/" :ans;
    }
};