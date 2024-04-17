# class ListNode:
#     def __init__(self, val, prev=None, next=None):
#         self.val = val
#         self.prev = prev
#         self.next = next

# class BrowserHistory:
#     def __init__(self, homepage: str):
#         self.curr = ListNode(homepage)
#     # O(1)
#     def visit(self, url: str) -> None:
#         self.curr.next = ListNode(url, self.curr)
#         self.curr = self.curr.next
    
#     # O(n)
#     def back(self, steps: int) -> str:
#         while self.curr.prev and steps > 0:
#             self.curr = self.curr.prev
#             steps -= 1
#         return self.curr.val

#     # O(n)
#     def forward(self, steps: int) -> str:
#         while self.curr.next and steps > 0:
#             self.curr = self.curr.next
#             steps -= 1
#         return self.curr.val

class BrowserHistory:
    def __init__(self, homepage: str):
        self.i = 0
        self.len = 1
        self.history = [homepage]
        
    # O(1)
    def visit(self, url: str) -> None:
        if self.i + 1 < len(self.history):
            self.history[self.i + 1] = url
        else:
            self.history.append(url)
        self.i += 1
        self.len = self.i + 1
    
    # O(1)
    def back(self, steps: int) -> str:
        self.i = max(0, self.i - steps)
        return self.history[self.i]

    # O(1)
    def forward(self, steps: int) -> str:
        self.i = min(self.len - 1, self.i + steps)
        return self.history[self.i]

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)