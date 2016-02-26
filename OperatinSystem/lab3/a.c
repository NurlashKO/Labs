#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int N = 10;
const int BUFF_SIZE = 1;
const int ITEMS[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int buff[BUFF_SIZE], cur, result[10], cnt;
int working = 0;

typedef struct Semaphore {
    int val, can;
} semaphore;

static semaphore fillCount = {.val = 0, .can = 1}, 
                 emptyCount = {.val = BUFF_SIZE, .can = 1};

int down(semaphore *x, int f)
{
    while (x->val == 0 || x -> can == 0);
    x->can = 0;
    x->val--;
    int item = x -> val;
    if (f)
        printf("CONSUMED ITEM : %d\n", buff[item]);
    x->can = 1;
    return buff[item];
}

void up(semaphore *x)
{
    while (x->val == BUFF_SIZE || x -> can == 0);
    x->can = 0;
    x->val++;
    x->can = 1;
}

void putItemIntoBuffer(int item)
{
    while (fillCount.can == 0);
    fillCount.can = 0;
    buff[fillCount.val] = item;
    printf("PRODUCED ITEM : %d\n", item);
    fillCount.can = 1;
}



int produceItem()
{
    while (cur == N);
    int item = ITEMS[cur++];
    return item;
}

void producer()
{
    while (1)
    {
        //while (working);
        while (!fillCount.can);
        fillCount.can = 0;
        if (fillCount.val == BUFF_SIZE)
        {
            fillCount.can = 1;
            continue;
        }
        printf("$ %d\n", fillCount.val);
        int item = produceItem();
        buff[fillCount.val++] = item;
        //printf("PRODUCER : %d\n", item);
        fillCount.can = 1;
    }
}

void consumer()
{
    while (1)
    {
        //while (working);
        while (!fillCount.can);
        fillCount.can = 0;
        if (fillCount.val == 0)
        {
            fillCount.can = 1;
            continue;
        }
        fillCount.val--;
        printf("CONSUMER : %d\n", buff[fillCount.val]);
        fillCount.can = 1;
        for (int i = 10; i <= 100000000; i++) i++;
    }
}



int main()
{
    pthread_t pth1, pth2;

    pthread_create(&pth2,NULL,consumer, NULL);
    pthread_create(&pth1,NULL,producer, NULL);

    pthread_join(pth1,NULL);
    pthread_join(pth2,NULL);
    
}
