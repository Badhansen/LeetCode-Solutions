"""
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None
    
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cache = {}

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        node = self.cache[key]
        self._remove(node)
        self._add(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self._remove(self.cache[key])
        if len(self.cache) == self.capacity:
            self._remove(self.tail.prev)
        node = Node(key, value)
        self._add(node)
        
    def _add(self, node):
        next_node = self.head.next
        next_node.prev = node
        node.next = next_node
        node.prev = self.head
        self.head.next = node
        self.cache[node.key] = node

    def _remove(self, node):
        next_node = node.next
        prev_node = node.prev
        next_node.prev = prev_node
        prev_node.next = next_node
        del self.cache[node.key]
            
        
"""

class LRUCache:

    def __init__(self, capacity: int):
        self.lru = OrderedDict()
        self.cap = capacity

    def get(self, key: int) -> int:
        if key in self.lru:
            self.lru.move_to_end(key, False)
            return self.lru[key]
        return -1

    def put(self, key: int, value: int) -> None:
        self.lru[key] = value
        self.lru.move_to_end(key, False)
        if len(self.lru) > self.cap:
            self.lru.popitem()
        

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)