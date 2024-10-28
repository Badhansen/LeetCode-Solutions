# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

class Solution:
    def match(self, guess, word):
        return sum(c1 == c2 for c1, c2 in zip(guess, word))
    
    def get_possible_word(self, words, guess, score):
        return [word for word in words if self.match(word, guess) == score]
    
    def guess_word(self, words):
        best_word = ""
        best_score = -1
        for word in words:
            scores = [self.match(word, w) for w in words]
            avg_score = sum(scores) / len(scores)
            if avg_score > best_score:
                best_score = avg_score
                best_word = word
        return best_word
    
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        while True:
            guess_word = self.guess_word(words)
            score = master.guess(guess_word)
            if score == 6:
                break
            words = self.get_possible_word(words, guess_word, score)