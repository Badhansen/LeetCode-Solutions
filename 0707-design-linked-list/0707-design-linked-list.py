class ListNode:
    def __init__(self, val: int):
        self.val = val
        self.prev = None
        self.next = None
        
class MyLinkedList:
    def __init__(self):
        self.head = ListNode(-1)
        self.tail = ListNode(-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, index: int) -> int:
        curr = self.head.next
        while curr and index > 0:
            curr = curr.next
            index -= 1
        if curr and curr != self.tail and index == 0:
            return curr.val
        return -1

    def addAtHead(self, val: int) -> None:
        node = ListNode(val)
        next_node, prev_node = self.head.next, self.head
        node.next = next_node
        node.prev = prev_node
        next_node.prev = node
        prev_node.next = node

    def addAtTail(self, val: int) -> None:
        node = ListNode(val)
        next_node, prev_node = self.tail, self.tail.prev
        node.next = next_node
        node.prev = prev_node
        next_node.prev = node
        prev_node.next = node

    def addAtIndex(self, index: int, val: int) -> None:
        curr = self.head.next
        while curr and index > 0:
            curr = curr.next
            index -= 1 
        if curr and index == 0:
            node, prev = ListNode(val), curr.prev
            node.next, node.prev = curr, prev
            curr.prev = node
            prev.next = node
            
    def deleteAtIndex(self, index: int) -> None:
        curr = self.head.next
        while curr and index > 0:
            curr = curr.next
            index -= 1
            
        if curr and curr != self.tail and index == 0:
            curr.prev.next = curr.next
            curr.next.prev = curr.prev


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)