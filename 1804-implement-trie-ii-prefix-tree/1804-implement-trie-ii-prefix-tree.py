# @Author: KING-SEN

class TrieNode:
    def __init__(self):
        self.children = {}
        self.end_of_word = 0
        self.prefix_of_word_count = 0
class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
            cur.prefix_of_word_count += 1
        cur.end_of_word += 1

    def countWordsEqualTo(self, word: str) -> int:
        cur = self.root
        for c in word:
            if c not in cur.children:
                return 0
            cur = cur.children[c]
        return cur.end_of_word

    def countWordsStartingWith(self, prefix: str) -> int:
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return 0
            cur = cur.children[c]
        return cur.prefix_of_word_count

    def erase(self, word: str) -> None:
        cur = self.root
        # node = None
        # for c in word:
        #     cur = cur.children[c]
        #     cur.prefix_of_word_count -= 1
        #     if node:
        #         node = None
        #     if cur.prefix_of_word_count == 0:
        #         node = cur
        # if node:
        #     node = None
        # cur.end_of_word -= 1
        for c in word:
            cur = cur.children[c]
            cur.prefix_of_word_count -= 1
        cur.end_of_word -= 1


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)