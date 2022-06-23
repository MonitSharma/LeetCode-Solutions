var combine = function(n, k) {
  if (n < k || k < 1) return [];

  var res = [];

  helper(res, [], 0, n, k);

  return res;
};

var helper = function (res, now, start, n, k) {
  if (k === 0) {
    res.push(Array.from(now));
    return;
  }

  for (var i = start; i < n; i++) {
    now.push(i + 1)
    helper(res, now, i + 1, n, k - 1);
    now.pop();
  }
};