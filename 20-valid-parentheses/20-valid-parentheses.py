class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        dic = {'(': ')', '[': ']', '{': '}'}
        for c in s:
            if stack and stack[-1] in "([{" and dic[stack[-1]] == c:
                stack.pop()
            else:
                stack.append(c)
        return not stack