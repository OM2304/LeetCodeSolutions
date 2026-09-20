class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        li = s.split(" ")
        print(li)
        for i in range(len(li)-1, -1, -1):
            if li[i]!='':
                return len(li[i])
        