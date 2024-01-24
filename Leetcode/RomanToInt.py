class Solution(object):
    def romanToInt(self, s):
        result = 0
        value = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        for i in range(len(s)-1):
            if value[s[i]] < value[s[i+1]]:
                result -= value[s[i]]
            else:
                result += value[s[i]] 
        return result+value[s[-1]]

test = Solution()
number = "III"
print(test.romanToInt(number))

