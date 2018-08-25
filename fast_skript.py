from collections import Counter

def solution(s, n):
	a = Counter(s)
	i = 0
	answ = 0
	most = a.most_common(0)

	while (i + 1 < len(a)):
		if a.most_common()[i][1] == a.most_common()[i+1][1]:
			print(i)
			answ += a.most_common()[i][1]
			i+=1
		else:
			answ += a.most_common()[i][1]
			break


	answ += a.most_common()[i][1]

	#print(len(a), i)
	answ += i*n

	for elem in a.values():
			if elem != most:
				answ+=elem

	return answ

if __name__ == "__main__":
	print(solution(["A","A","A","B","B","B"], n = 2))
