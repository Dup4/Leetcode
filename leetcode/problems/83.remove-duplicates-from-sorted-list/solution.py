# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        rt = head
        res = rt
        while head:
            if rt.val != head.val:
                rt.next = head
                rt = rt.next

            head = head.next
            rt.next = None

        return res
