# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        pre = 1000
        cnt = 1
        res = ListNode()
        cur = res
        while head:
            if head.val == pre:
                cnt += 1
            else:
                if cnt == 1 and pre != 1000:
                    cur.next = ListNode()
                    cur = cur.next
                    cur.val = pre
                pre = head.val
                cnt = 1

            head = head.next

        if cnt == 1 and pre != 1000:
            cur.next = ListNode()
            cur = cur.next
            cur.val = pre

        return res.next
