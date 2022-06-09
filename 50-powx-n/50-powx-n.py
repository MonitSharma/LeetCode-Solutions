class Solution:
    def myPow(self, x: float, n: int) -> float:
        def pow(x, n):
            if n == 0:
                return 1
            
            r = pow(x, n//2)
            if n % 2 == 0:
                return r * r
            else:
                return r * r * x
            
        if n < 0:
            n *= -1
            x = 1/x
            
        return pow(x, n)