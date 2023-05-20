import numpy as np

def mediana(lista):
    return np.median(lista)

def media(lista):
    return np.mean(lista)

def moda(lista):
    return np.argmax(np.bincount(lista))

def pega_dados(coluna,arquivo):
    import pandas as pd
    lista = []
    # Carregar o arquivo Excel
    df = pd.read_excel(f'{arquivo}.xlsx')

    # Acessar os valores de uma coluna específica
    coluna = df[coluna]

    # Exibir os valores da coluna
    for valor in coluna:
        lista.append((valor))

        return lista
    
def gerar_dados(nome_arquivo,lista,coluna):
    import pandas as pd
    dados = {}

    dados[coluna] = lista

    df = pd.DataFrame(dados)

    # Salvar o DataFrame em um arquivo Excel
    df.to_excel(f'{nome_arquivo}.xlsx', index=False)



