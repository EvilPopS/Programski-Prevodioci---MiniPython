#OPIS: Ugnjezden while statement, break i continue
#RETURN: 8

def main():
	i = 0
	while i <= 5:
		j = 0
		while j < 10:
			if j == 5:
				break
			elif j < 3:
				i = i + j
			elif j > 6:
				i = i + j
			j = j + 1
		i = i + 1
	return i

