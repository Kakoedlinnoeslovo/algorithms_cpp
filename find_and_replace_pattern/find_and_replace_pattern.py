from collections import Counter, defaultdict

class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        result = []

        dpattern = dict()
        for i, c in enumerate(pattern):
        	if (c in list(dpattern.keys())):
        		dpattern[c].add(i)
        	else:
        		dpattern[c] = set()
        		dpattern[c].add(i)

        
        for word in words:
        	temp = dict()

        	for i, c in enumerate(word):
	        	if (c in list(temp.keys())):
	        		temp[c].add(i)
	        	else:
	        		temp[c] = set()
	        		temp[c].add(i)

	        stempval = set(frozenset(i) for i in temp.values())
	        sdpattern = set(frozenset(i) for i in dpattern.values())

	        if stempval == sdpattern:
	        	result.append(word)
        return result

if __name__ == "__main__":
	sol = Solution()
	print(sol.findAndReplacePattern(["abc","deq","mee","aqq","dkd","ccc"], "abb"))