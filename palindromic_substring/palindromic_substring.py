class Solution:
	def countSubstrings(self, s):
		w = 0
		c = 0
		while (w != len(s)):
			for i in range(0, len(s) - w, 1):
				temp = s[i :(i+1)+w]
				if (temp == temp[::-1]):
					c+=1 
			w+=1
		return c 


if __name__ == "__main__":
	sol = Solution();
	print(sol.countSubstrings("abc"))