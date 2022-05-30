public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
    int count = 0;
    for(int i=1; i<33; i++){
        if(getBit(n, i) == true){
            count++;
        }
    }
    return count;
}
 
public boolean getBit(int n, int i){
    return (n & (1 << i)) != 0;
}
}
