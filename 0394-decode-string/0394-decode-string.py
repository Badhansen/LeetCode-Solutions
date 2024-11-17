# class Solution:
#     def decodeString(self, s: str) -> str:
#         stack = []
#         for i in range(len(s)):
#             if s[i] != "]":
#                 stack.append(s[i])
#             else:
#                 encoded_string = ""
#                 while stack[-1] != "[":
#                     encoded_string = stack.pop() + encoded_string
#                 stack.pop()
#                 k = ""
#                 while stack and stack[-1].isdigit():
#                     k = stack.pop() + k
#                 stack.append(int(k) * encoded_string)
#         return "".join(stack)
class Solution:
    def decode(self, s, position):
        result = []
        number = 0
        while position < len(s):
            char = s[position]
            if char.isdigit():
                number = number * 10 + int(char)
                position += 1
            elif char == '[':
                substring, next_position = self.decode(s, position + 1)
                result.append(number * substring)
                number = 0
                position = next_position
            elif char == ']':
                return "".join(result), position + 1
            else:
                result.append(char)
                position += 1
        return "".join(result), position
    
    def decodeString(self, s: str) -> str:
        decoded_string, _ = self.decode(s, 0)
        return decoded_string
                