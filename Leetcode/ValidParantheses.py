class Solution(object):
    def isValid(self, s):
        closing={'(':')','{':'}','[':']'}
        stack=[]
        for i in s:
            if i in closing.keys():
                stack.append(closing[i])
            else:
                if(len(stack)==0) or (stack[-1] != i):
                    return False
                stack.pop()

        if(len(stack)==0):
            return True
        return False
        
        
test = Solution()
b = "({{}})"
print(test.isValid(b))
