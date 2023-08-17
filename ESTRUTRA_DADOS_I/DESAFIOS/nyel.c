#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um produto
typedef struct {
    int id;
    float price;
} Product;

// Função para trocar dois produtos
void swap(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar um heap
void heapify(Product arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].price > arr[largest].price)
        largest = left;

    if (right < n && arr[right].price > arr[largest].price)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Função para ordenar um array de produtos usando Heap Sort
void heapSort(Product arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(NULL));

    // Alocação dinâmica de 30 produtos com preços aleatórios
    int numProducts = 30;
    Product *products = (Product *)malloc(numProducts * sizeof(Product));

    for (int i = 0; i < numProducts; i++) {
        products[i].id = i + 1;
        products[i].price = (float)(rand() % 1000) + ((float)(rand() % 100) / 100); // Preços aleatórios entre 0 e 1000 com centavos
    }

    printf("Produtos não ordenados:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("\nProduto %d: %.2f R$\n", products[i].id, products[i].price);
    }

    heapSort(products, numProducts);

    printf("\nProdutos ordenados por preço:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("\nProduto %d: %.2f R$\n", products[i].id, products[i].price);
    }

    free(products);

    return 0;
}
