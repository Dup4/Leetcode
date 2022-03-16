# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        rt = ListNode()
        res = rt
        while True:
            if not list1 and not list2:
                break
            if not list1:
                rt.next = list2
                list2 = list2.next
            elif not list2:
                rt.next = list1
                list1 = list1.next
            else:
                if list1.val < list2.val:
                    rt.next = list1
                    list1 = list1.next
                else:
                    rt.next = list2
                    list2 = list2.next

            rt = rt.next
        return res.next
