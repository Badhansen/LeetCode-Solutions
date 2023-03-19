class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False
        
        
class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = TrieNode()
            curr = curr.children[char]
        curr.is_end = True
    def search(self, word: str) -> bool:
        def dfs(root, index):
            if index == len(word):
                return root.is_end
            if word[index] == ".":
                for child in root.children.values():
                    if dfs(child, index + 1):
                        return True
            if word[index] in root.children:
                return dfs(root.children[word[index]], index + 1)
            return False
        
        return dfs(self.root, 0)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)