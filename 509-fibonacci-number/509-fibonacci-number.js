var fib = function(n) {
    let sqrt5 = Math.sqrt(5)
    return (Math.pow(1 + sqrt5, n) - Math.pow(1 - sqrt5, n)) / Math.pow(2, n) / sqrt5
};