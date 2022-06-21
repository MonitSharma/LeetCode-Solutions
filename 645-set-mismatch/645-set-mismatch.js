var findErrorNums = function(nums) {
    let N = nums.length, ans = [,]
    for (let i = 0; i < N; i++)
        nums[(nums[i] - 1) % 10000] += 10000
    for (let i = 0; i < N; i++)
        if (nums[i] > 20000) ans[0] = i + 1
        else if (nums[i] < 10001) ans[1] = i + 1
    return ans
};