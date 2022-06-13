class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = (int)words.size();
        int out = 0;
        vector<string> result;
        while (out < n) {
            int i = out;
            int curWidth = (int)words[i++].size();
            while (i < n && curWidth + 1 + (int)words[i].size() <= maxWidth) 
                curWidth += 1 + (int)words[i++].size();
            int numExtraSpace = maxWidth - curWidth;
            stringstream ss;
            int j = out;
            ss << words[j++];
            for (; j < i; j++) {
                int pad = 0;
                if (i < n) 
                    pad = numExtraSpace / (i-j) + (numExtraSpace % (i-j) ? 1 : 0);
                for (int k = 0; k < pad+1; k++)
                    ss << " ";
                numExtraSpace -= pad;
                ss << words[j];
            }
            for (int k = 0; k < numExtraSpace; k++)
                ss << " ";
            result.push_back(ss.str());
            out = i;
        }
        return result;
    }
};