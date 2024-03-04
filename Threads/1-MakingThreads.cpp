#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Thread basically executes a function (in parallel with other threads)

void* routine(void*)
{
    cout << "thread execution started" << endl;
    sleep(3);
    cout << "ending thread's execution" << endl;
    return NULL;
}

int main()
{
    pthread_t t1, t2; // Stores all the properties of a thread
    pthread_create(&t1, nullptr, &routine, nullptr);
    pthread_create(&t2, nullptr, &routine, nullptr);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    return 0;
}
