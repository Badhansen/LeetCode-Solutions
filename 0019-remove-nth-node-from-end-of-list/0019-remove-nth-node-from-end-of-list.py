# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        left, right = dummy, head
        while n > 0 and right:
            right = right.next
            n -= 1
        while right:
            right = right.next
            left = left.next
        left.next = left.next.next
        return dummy.next
'''
Time Complexity: O(N), where N is the length of the ListNode
Space Complexity: O(1), We only used constant extra space. 
'''
            