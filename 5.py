import random as rnd

n = int(input("Ingrese el numero de elementos: "))

elementos = [ ]

for i in range(n) :
  elementos.append(rnd.randint(1, 10))
  print(elementos[i])

suma = 0
for i in range(n) :
  suma += elementos

media = suma / n
print("La media del arreglo es: ", media)

for i in range(n) :
  if (elementos > media) :
    print(elementos [i])