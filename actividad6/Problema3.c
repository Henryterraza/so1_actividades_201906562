#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread created\n");
    return NULL;
}

int main() {
    pid_t pid;

    pid = fork();
   
    if (pid == 0) { /* child process */
      
        fork();

        // Crear un hilo en el proceso hijo
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL); // Espera a que el hilo termine
    }

    fork();

    
    return 0;
}