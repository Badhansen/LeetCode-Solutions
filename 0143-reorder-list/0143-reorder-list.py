# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        numbers = []
        curr = head
        while curr:
            numbers.append(curr)
            curr = curr.next
        left, right, count = 1, len(numbers) - 1, 0
        curr = head
        while left <= right:
            if count & 1:
                curr.next = numbers[left]
                left += 1
            else:
                curr.next = numbers[right]
                right -= 1
            count += 1
            curr = curr.next
        curr.next = None