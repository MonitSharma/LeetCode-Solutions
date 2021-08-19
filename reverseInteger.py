class Solution:
    def reverse(self, x: int) -> int:
        y = str(abs(x))      # convert the integer into string
        y = y.strip()        # strip the string its leading zeroes
        y = y[::-1]          # reverse the string
        output = int(y)      # store the inverted string
        if output >= 2** 31 -1 or output <= -2** 31:     # handle the overflow and underflow
            return 0
        elif x < 0:          # handle the negative input   
            return -1 * output
        else:
            return output
