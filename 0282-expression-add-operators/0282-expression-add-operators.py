class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
	
        # Initializing the resulting list
        res = []
		
        def backtrack(num, path, trace):
            nonlocal res
			
            # Here, we have reached the end of the number string, i.e., there is no digit left
            if not num:
                # Our trace contains only +ve/-ve numbers that can simply be summed up to get the evaluated value.
                # If the sum is equal to the target, we add the path (expression string) to the result list.
                if sum(trace) == target: res.append(path)
                return
				
            # curr is the current value of the candidate integer
            # i is the position in the number string
            # Since we are passing only the remaining part of the String to the next recursive call, i starts from 0
            # rlim is the range which handles the case where we don't include numbers with leading zeros like 05, 012 etc
            curr, i, rlim = 0, 0, len(num) if num[0] != '0' else 1
			
            # This loop iterates through the number string and includes a new digit into the candidate number at each iteration
            # This would ensure that we are trying 1, 12, 123 for a string that starts with "123"
            while i < rlim:
			
                curr = curr*10 + int(num[i])
                i += 1
				
                # If we have already got some numbers, we enter this condition
                if trace:
                    # If the operation is simple '+' or '-', we can add the number with the sign to the trace
                    backtrack(num[i:], path+'+'+num[:i], trace+[curr])
                    backtrack(num[i:], path+'-'+num[:i], trace+[-curr])
                    # If the sign is *, we have to pick up the last element of the trace, multiply it with the current number, and append it back to the trace
                    backtrack(num[i:], path+'*'+num[:i], trace[:-1]+[curr*trace[-1]])
					
                # If there is no trace, we simply have to add the positive number to the same
                else:
                    backtrack(num[i:], num[:i], [curr])
					
        backtrack(num, '', [])
        return res