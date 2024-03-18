total = int(input("Quantos números serão digitados?"))
rol = []

for i in range (0, total):
    rol.append(int(input("Digite um número: ")))
    print (rol)

rol.sort()
print(rol)
print(len(rol))

if total % 2 == 0:
    a = int(total /2)
    print(a)
    b = int(((total))/2 + 1)
    print(b)
    me = float((rol[a-1]+rol[b-1])/2)
    print(me)
    print (f"A mediana é {me}.")
else:
    me = int((total + 1) / 2)
    print (f"A mediana é {rol[me-1]}.")