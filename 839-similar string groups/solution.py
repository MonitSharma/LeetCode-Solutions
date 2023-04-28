class Solution:
    def numSimilarGroups(self, A):
        def find(x):
            while x != uf[x]:
                uf[x] = uf[uf[x]]
                x = uf[x]
            return x

        def union(x, y):
            count = 0
            for i, j in zip(x, y):
                if i != j:
                    if count < 2:
                        count = -~count
                    else:
                        return False
            return count == 2

        row_len = len(A)
        col_len = len(A[0])
        A = set(A)
        uf = {word: word for word in A}
        groups = len(A)

        if col_len > row_len:
            for x, y in itertools.combinations(A, 2):
                if union(x, y):
                    x_root = find(x)
                    y_root = find(y)
                    if x_root != y_root:
                        groups -= 1
                        uf[x_root] = y_root
        else:
            for x in A:
                for i, j in itertools.combinations(range(col_len), 2):
                    y = x[:i] + x[j] + x[-~i:j] + x[i] + x[-~j:]
                    if y in A:
                        x_root = find(x)
                        y_root = find(y)
                        if x_root != y_root:
                            groups -= 1
                            uf[x_root] = y_root
        return groups