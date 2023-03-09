# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        seen = {}
        while head:
            if head in seen:
                return head
            seen[head] = 1
            head = head.next
        return None
        