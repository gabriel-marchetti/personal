import random

numSortings = int(input())
numbersSet = set()
for i in range(numSortings):
    newNumber = random.randint(0, 101)
    numbersSet.add(newNumber)
numbersSet = sorted(numbersSet)
print(numbersSet)    