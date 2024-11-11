class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.end = True
        
    def start_with(self, word: str) -> bool:
        curr = self.root
        res = []
        for c in word:
            if c not in curr.children:
                return [False, ""]
            curr = curr.children[c]
            res.append(c)
            if curr.end:
                return [True, "".join(res)]
        return [False, ""]
        
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        # trie = Trie()
        # for word in dictionary:
        #     trie.insert(word)
        # words = sentence.split(" ")
        # res = []
        # for word in words:
        #     has_prefix, w = trie.start_with(word)
        #     if has_prefix:
        #         res.append(w)
        #     else:
        #         res.append(word)
        # return " ".join(res)
        dictionary.sort()
        words = list(sentence.split(" "))
        for i in range(len(words)):
            for dic in dictionary:
                if words[i][:len(dic)] == dic:
                    words[i] = dic
                    break
        return " ".join(words)