var lengthOfLongestSubstring = function(s) {
    var mapping = {};
    var i = 0;
    var ans = 0;

    for(var j = 0; j < s.length; j++){
        if(mapping[s[j]]) {
            if(mapping[s[j]] > i) {
                i = mapping[s[j]];
            }
        }

        if(j - i + 1 > ans){
            ans = j - i + 1;
        }
        mapping[s[j]] = j + 1;
    }

    return ans;
};