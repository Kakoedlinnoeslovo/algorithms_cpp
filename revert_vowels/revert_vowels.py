def decision(s):
	origin_list = [x for x in s]

	vowels_str = ""
	vowels_aphabet = set(["a", "e", "i", "o", "u"])
	
	for i, a in enumerate(s):
		if a in vowels_aphabet:
			origin_list[i] = "!"
			vowels_str+=a

	vowels_str = vowels_str[::-1]
	k =0
	for i, a in enumerate(origin_list):
		if a == "!":
			origin_list[i] = vowels_str[k]
			k+=1

	result = "".join(x for x in origin_list)
	return result

if __name__ == "__main__":
	print(decision("abre"))
	