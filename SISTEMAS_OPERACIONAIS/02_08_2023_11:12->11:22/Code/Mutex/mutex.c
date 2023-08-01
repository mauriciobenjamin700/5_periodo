#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 3      // tamanho do buffer
#define NUM_PRODUCERS 1 // número de produtores
#define NUM_CONSUMERS 3 // número de consumidores

typedef struct
{
  int buf[BUF_SIZE];          // definindo o buffer
  size_t len;                 // controla o número de itens do buffer
  pthread_mutex_t mutex;      // variável mutex
  pthread_cond_t can_produce; // variável condicional indicando que item(s) foram removidos
  pthread_cond_t can_consume; // variável condicional indicando que item(s) foram adicionados
} buffer_t;

void *producer(void *arg)
{
  buffer_t *buffer = (buffer_t *)arg;
  pthread_mutex_lock(&buffer->mutex);

  while (1)
  {
    while (buffer->len == BUF_SIZE)
    {
      printf("Buffer cheio. Produtor esperando por espaço...\n");
      pthread_cond_wait(&buffer->can_produce, &buffer->mutex);
    }

    // srand(time(NULL) + pthread_self()); // garantindo a raiz aleatória para cada thread
    srand(time(NULL)); // garantindo a raiz aleatória para cada thread
    int item = rand() % 11;

    printf("Produtor %lu produziu: %d\n", pthread_self(), item);

    buffer->buf[buffer->len] = item;
    ++buffer->len;

    pthread_cond_signal(&buffer->can_consume);
  }

  pthread_mutex_unlock(&buffer->mutex);
  return NULL;
}

void *consumer(void *arg)
{
  buffer_t *buffer = (buffer_t *)arg;
  pthread_mutex_lock(&buffer->mutex);

  while (1)
  {
    while (buffer->len == 0)
    {
      printf("Buffer vazio. Consumidor esperando por itens...\n");
      pthread_cond_wait(&buffer->can_consume, &buffer->mutex);
    }

    --buffer->len;
    printf("Consumidor %lu consumiu: %d\n", pthread_self(), buffer->buf[buffer->len]);

    pthread_cond_signal(&buffer->can_produce);
  }

  pthread_mutex_unlock(&buffer->mutex);
  return NULL;
}

int main(int argc, char *argv[])
{
  buffer_t buffer = {
      .len = 0,
      .mutex = PTHREAD_MUTEX_INITIALIZER,
      .can_produce = PTHREAD_COND_INITIALIZER,
      .can_consume = PTHREAD_COND_INITIALIZER};

  pthread_t producers[NUM_PRODUCERS];
  pthread_t consumers[NUM_CONSUMERS];

  for (int i = 0; i < NUM_PRODUCERS; i++)
  {
    pthread_create(&producers[i], NULL, producer, (void *)&buffer);
  }

  for (int i = 0; i < NUM_CONSUMERS; i++)
  {
    pthread_create(&consumers[i], NULL, consumer, (void *)&buffer);
  }

  for (int i = 0; i < NUM_PRODUCERS; i++)
  {
    pthread_join(producers[i], NULL);
  }

  for (int i = 0; i < NUM_CONSUMERS; i++)
  {
    pthread_join(consumers[i], NULL);
  }

  // MENSSAGEM DE ENCERRAMENTO DO PROGRAMA
  printf("Programa encerrado com sucesso.\n");

  return 0;
}
