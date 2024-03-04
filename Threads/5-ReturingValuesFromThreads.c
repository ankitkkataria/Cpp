#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *rollDice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    printf("Thread's varaible result's address: %p\n", result);
    return (void *)result;
}

int main()
{
    int* res[4];
    srand(time(NULL));
    pthread_t threadsArray[4];
    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(threadsArray + i, NULL, &rollDice, NULL) != 0)
            return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(threadsArray[i], (void **) res+i) != 0)
            return 2;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Main res[%d] has the addresss stored %p:\n ", i,res[i]);
        printf("Result: %d\n", *res[i]);
        free(res[i]);
    }
    return 0;
}