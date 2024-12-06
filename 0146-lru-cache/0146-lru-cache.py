class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None
    
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dic = dict()
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def add(self, node):
        prev_end = self.tail.prev
        prev_end.next = node
        node.prev = prev_end
        node.next = self.tail
        self.tail.prev = node       
        
    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        
    def get(self, key: int) -> int:
        if key in self.dic:
            node = self.dic[key]
            self.remove(node)
            self.add(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            node = self.dic[key]
            self.remove(node)
            
        new_node = Node(key, value)
        self.dic[key] = new_node
        self.add(new_node)
        
        if len(self.dic) > self.capacity:
            del_node = self.head.next
            self.remove(del_node)
            del self.dic[del_node.key]
        
        