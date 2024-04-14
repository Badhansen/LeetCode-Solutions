class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None
    
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = dict()
        self.head = Node()
        self.tail = Node()
        
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def add(self, node):
        next_node = self.head.next
        node.next = next_node
        next_node.prev = node
        node.prev = self.head
        self.head.next = node
        self.cache[node.key] = node
        
    def remove(self, node):
        next_node = node.next
        prev_node = node.prev
        prev_node.next = next_node
        next_node.prev = prev_node
        del self.cache[node.key]
        
    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            self.add(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
        if len(self.cache) == self.capacity:
            self.remove(self.tail.prev)
        new_node = Node(key, value)
        self.add(new_node)
        
# Time Complexity: O(1) for get and put on average
# Space Complexity: O(Capacity)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)