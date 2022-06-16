class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.split('/')
        print(path)
        stack = []
        for c in path:
            if c:
                if c == '.':
                    continue
                elif c == '..':
                    if stack:
                        stack.pop()
                    else:
                        continue
                else:
                    stack.append(c)
        
        
        return '/'+'/'.join(stack)