import functools as f

class Solution:
    def numJewelsInStones1(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        return f.reduce(lambda x,y: x + (1 if y in J else 0), S, 0)

    def numJewelsInStones2(self, J, S):
        count = 0
        for j in J:
            for s in S:
                if j == s:
                    count += 1
        return count




if __name__ == "__main__":
    S = "ZZZ"
    J = "Zz"
    s = Solution()
    print(s.numJewelsInStones1(J,S))
    print(s.numJewelsInStones2(J,S))
