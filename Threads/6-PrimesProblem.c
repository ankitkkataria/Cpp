#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// What we'd like to do is with each thread I'd want to access and print only one prime.

// This method down below won't work cause (i) will keep on changing.
// int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

// void* routine(void* arg) {
//     sleep(1);
//     int index = *(int*)arg;
//     printf("%d ", primes[index]);
// }

// int main() {
//     pthread_t threadsArray[10];
//     for (int i = 0; i < 10; i++)
//     {
//         if(pthread_create(&threadsArray[i],NULL,&routine,&i) != 0) {
//             return 1;
//         }
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         if(pthread_join(threadsArray[i],NULL) != 0) {
//             return 2;
//         }
//     }

//     return 0;
// }

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    sleep(1);
    int index = *(int*)arg;
    printf("%d ", primes[index]);
    free(arg); 
}

int main() {
    pthread_t threadsArray[10];
    for (int i = 0; i < 10; i++)
    {
        int* x = (int*)malloc(sizeof(int)); // Dynamically allocating a variable in the heap to be able to store the value of i.
        *x = i;
        if(pthread_create(&threadsArray[i],NULL,&routine,x) != 0) { // x here represents the argument that will be passed to the routine function.
            return 1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if(pthread_join(threadsArray[i],NULL) != 0) {
            return 2;
        }
    }

    return 0;
}











