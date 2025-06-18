class Solution:
    def maxDiff(self, num: int) -> int:
        num = str(num)
        a = num
        b = num
        # Finding largest number
        for n in num:
            if n != '9':
                a = num.replace(n, '9')
                break
        # For finding smallest number
        if num[0] != '1':
            b = num.replace(num[0], '1')
        else:
            for n in num:
                if n != '1' and n != '0':
                    b = num.replace(n, '0')
                    break
        return int(a) - int(b)
            