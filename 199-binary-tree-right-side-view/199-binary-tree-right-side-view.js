var rightSideView = function (root) {

    // Base case, no nodes given. 
    if (!root) {
        return [];
    }

    // An array to store all the right most nodes
    const right_view = [];

    // A queue for the level order traversal
    const queue = [root];

    // While the queue is not empty, keep going
    while (queue.length) {

        // Make note of the queue length.
        // We do this to perform row by row traversal.
        const q_len = queue.length;

        // Iterate through the queue, end at the row
        for (let i = 0; i < q_len; i++) {

            // Current node
            const node = queue.pop();

            // If the current index is the end of the row,
            // meaning, it's the right most node in the level.
            // Push it to the right_view array.
            if (i === q_len - 1) {
                right_view.push(node.val);
            }

            // Add them. 
            node.left ? queue.unshift(node.left) : null;
            node.right ? queue.unshift(node.right) : null;
        }
    }

    // Return Home!!
    return right_view;
};

