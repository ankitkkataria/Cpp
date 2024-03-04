#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int mails = 0;

void* routine()
{
    for(int i = 0 ; i < 1000000 ; i++) 
        mails++;
}

int main()
{
    pthread_t t1, t2; // Stores all the properties of a thread
    pthread_create(&t1, NULL, &routine, NULL); // Passing null here as second argument basically sets everything in this thread to the default values.
    pthread_create(&t2, NULL, &routine, NULL); 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Number of mails: %d", mails);
    return 0;
}
