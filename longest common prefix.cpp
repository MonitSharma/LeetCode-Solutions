class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
            return "";
        int maxL = strs[0].length();
        bool match = true;
        int j = 0;
        for (int i = 1; i < strs.size(); i++)
        {
            if ((strs[i]).length() == 0 || (strs[i])[0] != (strs[0])[0])
                return "";
            while (match && j < maxL && j < strs[i].length())
            {
                match = ((strs[i])[j] == (strs[0])[j]);
                j++;
            }
            if (!match)
                maxL = j - 1;
            if (strs[i].length() < maxL)
                maxL = strs[i].length();
            j = 0;
            match = true;
        }
        return strs[0].substr(0, maxL);
    }
};