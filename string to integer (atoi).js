var myAtoi = function(s) {
    const intMin = -(2**31);
    const intMax = 2**31 - 1;
    let i = 0, length = s.length;
    let positive = true;
    while (i < length && s.charAt(i) === ' ') {
        i++;
    }
    if (i === length) {
        return 0;
    }
    if (s.charAt(i) === '+') {
        i++;
    } else if (s.charAt(i) === '-') {
        i++;
        positive = false;
    }
    let num = 0;
    for (; i < length && s.charAt(i) >= '0' && s.charAt(i) <= '9'; i++) {
        num = num * 10 + (s.charAt(i) - '0');
     }
     num = positive ? num : -num;
     if (num < intMin) {
         return intMin;
     } else if (num > intMax) {
         return intMax;
     }
     return num;
};
