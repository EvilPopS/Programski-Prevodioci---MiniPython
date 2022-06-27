#OPIS: Ugnjezden if statement 
#RETURN: 100

def main():
	a = 10
	b = 5
	res = 0
	
	if a < b*3:    # 10 < 15 - true
		b = a*b
		if b > 30:      # 50 > 30 - true
			res = 100
		elif b < 20:
			res = 50
		else:
			if a > 3:
				return 2
			elif b < 2:
				res = 45
	elif a > b + 100 / 5:
		res = 40
	else:
		return 38
	return res
	
