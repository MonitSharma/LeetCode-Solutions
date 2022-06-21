var findErrorNums = function(nums) {
    let N = nums.length, dupe, sum = N * (N + 1) / 2,
        seen = new Uint8Array(N+1)
    for (let i = 0; i < N; i++) {
        let num = nums[i]
        sum -= num
        if (seen[num]) dupe = num
        seen[num]++
    }
    return [dupe, sum + dupe]
};