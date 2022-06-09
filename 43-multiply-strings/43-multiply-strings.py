class Solution:
    def multiply(self, num1, num2):
        num1_num = 0
        for each in num1:
            asc = ord(each)
            num = asc - 48
            num1_num = num1_num*10+num
        num2_num = 0
        for each in num2:
            asc = ord(each)
            num = asc - 48
            num2_num = num2_num*10+num
        mul = num1_num * num2_num
        if mul == 0:
            return '0'
        strlist = []
        while mul != 0:
            digit = mul%10
            strlist.append(digit)
            mul = (mul- digit)//10
        result = ''
        for each in strlist:
            newstr = chr(each+48)
            result = newstr + result
        return result