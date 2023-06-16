class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        mod=10**9+7
        
        def f(nums):
            n=len(nums)
            if n<=1:
                return len(nums) 

            left=[i for i in nums if i<nums[0]]
            right=[i for i in nums if i>nums[0]]

            Left=f(left)
            Right=f(right)

            if not Left or not Right :
                return Left or Right
            ans=comb(len(right)+len(left),len(right))
            return ans*Left*Right

        return (f(nums)-1)%mod    

        return (f(nums)-1)%mod  