class Solution:
    def maxPower(self, s: str) -> int:
        slow = 0
        h = 0
        c = 0
        res = 0
        for h in range(len(s)):
            if s[slow]==s[h]:
                c+=1
                res = max(res, c)
            else:
                c = 0
                slow = h
                c+=1
        return res


        