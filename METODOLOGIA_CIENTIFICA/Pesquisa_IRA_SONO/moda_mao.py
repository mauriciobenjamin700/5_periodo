from func import moda
# F = 1, M = 0
genero = [1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,1,1]

contador_f = 0
contador_m = 0

resultado = moda(genero)

for i in genero:
    if i==0:
        contador_m +=1
    else:
        contador_f +=1
    

print(f"\nTotal de homens: {contador_m}\nTotal de mulheres: {contador_f}\n")

if resultado == 0:
    print("Ha mais homens")
    
else:
    print("Ha mais mulheres")