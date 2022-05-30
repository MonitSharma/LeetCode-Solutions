class Solution:
    #solution 1
    def hammingWeight(self, n: int) -> int:   
        cnt = 0        
        while(True):
            if n == 0: 
                break
            if n & 1 == 1: #check whether the last bit is 1
                cnt += 1
            n = int(n / 2)  
        return cnt
    
    #solution 2
    def hammingWeight(self, n: int) -> int:   
        cnt = 0        
        while(n != 0):
            n = n & (n - 1)
            cnt += 1
        return cnt
