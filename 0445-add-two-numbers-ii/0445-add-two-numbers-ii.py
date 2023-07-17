# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def convertToNum(curr):
            n = 0
            while curr:
                n = n * 10 + curr.val
                curr = curr.next
            return n
        
        n1 = convertToNum(l1)
        n2 = convertToNum(l2)
        
        total = n1 + n2
        head = None
        
        while total or not head:
            total, digit = total // 10, total % 10
            node = ListNode(digit)
            node.next = head
            head = node
        
        return head