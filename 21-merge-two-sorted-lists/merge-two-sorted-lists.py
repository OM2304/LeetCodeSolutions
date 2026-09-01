# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        if list1 is None:
            return list2
        if list2 is None:
            return list1

        p1 = list1
        p2 = list2
        
        prev = ListNode(0, None)
        head = prev
        while(p1 is not None and p2 is not None):
            if(p1.val > p2.val):
                prev.next = p2
                prev = prev.next
                p2 = p2.next
            else:
                prev.next = p1
                prev = prev.next
                p1 = p1.next
        
        while(p1 is not None):
            prev.next = p1
            prev = prev.next
            p1 = p1.next
        
        while(p2 is not None):
            prev.next = p2
            prev = prev.next
            p2 = p2.next
        
        return head.next

                