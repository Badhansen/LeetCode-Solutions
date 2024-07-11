# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
#         def getNextElement(root):
#             while root:
#                 yield root.val
#                 root = root.next
        
#         values = [val for sl in lists for val in getNextElement(sl)]
        values = []
        for sl in lists:
            while sl:
                values.append(sl.val)
                sl = sl.next
        
        heapq.heapify(values)
        dummy = ListNode(-1, None)
        curr = dummy
        
        while values:
            val = heapq.heappop(values)
            curr.next = ListNode(val)
            curr = curr.next
        
        return dummy.next