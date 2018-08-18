class Solution(object):
    def longestPalindrome(self, s):
    	w = len(s)
    	result = ""

    	if (len(s) == 1):
    		return s

    	while (w != 0):
    		indicator = 0
    		for i in range(0, len(s) - w + 1, 1):
    			temp = s[i:i+w]
    			print(temp, w)
    			if (temp[::-1] == temp):
    				result = temp
    				indicator = 1
    				break
    		if (indicator):
    			break
    		w-=1
    	return result

if __name__ == "__main__":
	sol = Solution()
	print(sol.longestPalindrome("bb"))

