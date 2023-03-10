# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import random

class Solution:
    link_list = list()
    length = 0
    random.seed(10)
    def __init__(self, head: Optional[ListNode]):
        self.link_list = list()
        while head:
            self.link_list.append(head.val)
            head = head.next
        self.length = len(self.link_list)

    def getRandom(self) -> int:
        index = int(random.uniform(0, self.length))
        return self.link_list[index]


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()