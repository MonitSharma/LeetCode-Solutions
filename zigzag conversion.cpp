class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        int i, row = 0;
        bool down = true;
        string array[numRows];
        for(i = 0; i < numRows; i++){
            array[i] = "";
        }
        for(i = 0; i < s.size(); i++){
            array[row] += s[i];
            if(row == 0){
                down = true;
            }
            if(row == numRows - 1){
                down = false;
            }
            down ? row++ : row--;
        }
        string answer = "";
        for(i = 0; i < numRows; i++){
            answer += array[i];
        }
        return answer;
    }
};
