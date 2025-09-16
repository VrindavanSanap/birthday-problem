
import time

def prob_unique_birthday(n):
	res = 1.0
	for i in range(n):
		num = (365.0 - i)
		den = 365.0
		res *= num /den
	return res	


if __name__ == "__main__":
	start = time.time()
	for i in range(5, 91, 5):
		res = 1 - prob_unique_birthday(i)
		print(f"{i} {res:.5f}")
	end = time.time()
	print(f"Time taken by program is : {end - start:.9f} sec")

	start = time.time()
	for i in range(21, 25):
		res = 1 - prob_unique_birthday(i)
		print(f"{i} {res:.5f}")
	end = time.time()
	print(f"Time taken by program is : {end - start:.9f} sec")