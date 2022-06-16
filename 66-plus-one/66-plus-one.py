class Solution(object):
    def plusOne(self, digits):
        digits=str(int(''.join([str(x) for x in digits]))+1)
        ret=[]
        for i in range(len(digits)):
            ret.append(int(digits[i:i+1]))
        return ret