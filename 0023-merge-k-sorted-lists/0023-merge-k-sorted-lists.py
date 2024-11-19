# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for idx, lst in enumerate(lists):
            if lst:
                heapq.heappush(heap, (lst.val, idx, lst))
                
        dummy = ListNode(-1, None)
        curr = dummy
        
        while heap:
            val, idx, node = heapq.heappop(heap)
            curr.next = node
            if node.next:
                heapq.heappush(heap, (node.next.val, idx, node.next))
            curr = curr.next
        
        return dummy.next