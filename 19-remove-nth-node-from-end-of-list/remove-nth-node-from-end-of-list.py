# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        if head is None:
            return head
        curr = head
        prev = None
        size = 1

        while(curr.next!=None):
            size+=1
            curr = curr.next
        curr = head
        for i in range(0, size-n):
            prev = curr
            curr = curr.next
        
        if prev is None:
            return head.next

        prev.next = curr.next
        return head

        