# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        rt = ListNode()
        res = rt

        while head:
            if head.val != val:
                rt.next = ListNode()
                rt = rt.next
                rt.val = head.val
            head = head.next

        return res.next
