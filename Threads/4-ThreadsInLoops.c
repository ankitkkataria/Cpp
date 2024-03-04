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

// This down below is the wrong way of creating threads in a loop
// int main()
// {

//     pthread_t threadsArray[4]; // Stores all the properties of a thread
//     pthread_mutex_init(&mutex, NULL);
//     for (int i = 0; i < 4; i++)
//     {
//         pthread_create(threadsArray+i, NULL, &routine, NULL); // Passing null here as second argument basically sets everything in this thread to the default values.
//         printf("Thread %d execution started\n", i);
//         pthread_join(threadsArray[i], NULL); // This basically starts the execution of the thread.
//         printf("Thread %d execution ended\n", i);
//     }
    
//     pthread_mutex_destroy(&mutex);
//     printf("Number of mails: %d", mails);
//     return 0;
// }

// This down below is the correct way of doing making multiple threads using loops make sure you create and join(execute) them in separate loops.
int main()
{

    pthread_t threadsArray[4]; // Stores all the properties of a thread
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++)
    {
        if(pthread_create(threadsArray+i, NULL, &routine, NULL) != 0) {
            perror("Failed to create a thread");
            return 1;
        } 
        printf("Thread %d execution started\n", i);
    }
    for (int i = 0; i < 4; i++)
    {
        if(pthread_join(threadsArray[i], NULL) != 0)  
        printf("Thread %d execution ended\n", i);
    }
    
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d", mails);
    return 0;
}

