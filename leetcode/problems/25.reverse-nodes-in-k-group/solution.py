# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        a = []
        while head:
            a.append(head.val)
            head = head.next

        cur = ListNode()
        res = cur

        while len(a) >= k:
            for i in range(k - 1, -1, -1):
                cur.next = ListNode()
                cur = cur.next
                cur.val = a[i]
            a = a[k:]

        for x in a:
            cur.next = ListNode()
            cur = cur.next
            cur.val = x

        return res.next
