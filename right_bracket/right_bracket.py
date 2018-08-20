import numpy as np

def right_bracket(k, c, result, index):
	if (c <= k - 2 - index):
		result[index] = "("
		right_bracket(k, c + 1, result, index + 1)
	if (c > 0):
		result[index] = ")"
		right_bracket(k, c - 1, result, index + 1)
	if (index == k and c == 0):
		print(result)


if __name__ == "__main__":
	right_bracket(6, 0, list(np.zeros(6)), 0)





