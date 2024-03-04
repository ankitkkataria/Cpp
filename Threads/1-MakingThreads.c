#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Thread basically executes a function (In parallel with other threads)

void* routine()
{
    printf("Thread execution started \n");
    sleep(3);
    printf("Thread execution ended\n");
}

int main()
{
    pthread_t t1, t2; // Stores all the properties of a thread
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
