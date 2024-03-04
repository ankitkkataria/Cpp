#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex); // This makes sure that the line below can only be accessed by one thread at a time no matter how many threads might be running at once. Basically what this line does is it does the testing of a lock being unlocked or available, setting of a lock if avaiable and making sure a process waits while the lock is not available.
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t t1, t2, t3, t4; // Stores all the properties of a thread
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, &routine, NULL); // Passing null here as second argument basically sets everything in this thread to the default values.
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_create(&t3, NULL, &routine, NULL);
    pthread_create(&t4, NULL, &routine, NULL);
    pthread_join(t1, NULL); // This basically starts the execution of the thread.
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d", mails);
    return 0;
}
