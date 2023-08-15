# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        Low, High = ListNode(-1), ListNode(-1)
        low, high = Low, High
        while head:
            if head.val < x:
                low.next = head
                low = low.next
            else:
                high.next = head
                high = high.next
            head = head.next
        high.next = None
        low.next = High.next
        return Low.next