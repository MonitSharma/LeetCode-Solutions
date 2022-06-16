class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        for(int idxA = a.size()-1, idxB = b.size()-1; idxA>=0 || idxB>=0; idxA--, idxB--) {
            int aNum = idxA >=0 ? a[idxA]-'0' : 0;
            int bNum = idxB >=0 ? b[idxB]-'0' : 0;
            int curPosNum = aNum + bNum + carry;
            int tempRe = curPosNum%2;
            carry = curPosNum/2;
            result.insert(result.begin(), tempRe+'0');
        }
        if(carry > 0) result.insert(result.begin(), carry+'0');
        return result;
    }
};