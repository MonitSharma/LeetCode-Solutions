var flatten = function(root) {
    let curr = root
    while (curr) {
        if (curr.left) {
            let runner = curr.left
            while (runner.right) runner = runner.right
            runner.right = curr.right, curr.right = curr.left, curr.left = null
        }
        curr = curr.right
    }
};