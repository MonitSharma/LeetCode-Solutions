class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator uit;
        map<int, int> mp;
        map<int, int>::reverse_iterator it;
        
        //Update count (frequency) of each character
        for(auto c: s)
            um[c]++;
        
        //Update count of each frequency
        for(uit = um.begin(); uit!=um.end(); uit++)
        {
            mp[uit->second]++;
        }
        
        int count = 0;
        for(it = mp.rbegin(); it != mp.rend(); it++)
        {
            while (it->second > 1)              //multiple characters mapped to this frequency
            {
                int num = it->first;
                while(mp.find(num) != mp.end()) //find unused frequency
                {
                    num--;
                }
                count += (it->first - num);     //update count of deletions
                it->second = it->second - 1;
                if (num != 0)
                    mp[num] = 1;                //map unused frequency
            }
        }
        return count;
    }
};