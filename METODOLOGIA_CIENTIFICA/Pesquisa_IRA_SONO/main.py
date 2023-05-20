from func import *

nomes = ['IRA', 'SONO(HORAS)' ]

for i in range(0,2):
    lista = pega_dados(nomes[i],'Dados')

    me = media(lista=lista)
    mo = moda(lista=lista)
    median = mediana(lista=lista)

    gerar_dados(f'Resultados_{nomes[i]}',[me,mo,median],nomes[i])

