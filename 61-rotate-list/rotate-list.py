# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if head == None:
            return head

        last = head
        n = 1
        while(last.next!=None):
            n+=1
            last = last.next
        
        k = k%n
        if k==0 or k==n:
            return head
        

        breakNode = head
        for i in range(1, (n-k)):
            breakNode = breakNode.next
        
        start = breakNode.next

        last.next = head
        breakNode.next = None
        head = start
        return head

        