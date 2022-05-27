var numberOfSteps  = function(num) {
    let ans = 0
    for (; num; ans++)
        if (num % 2) num--
        else num /= 2
    return ans
};
