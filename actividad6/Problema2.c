#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // proceso hijo se crea y se termina para entrar en modo zombie
        printf("Proceso hijo con PID %d ha terminado.\n", getpid());
        exit(0); 
    } else {

        printf("Proceso padre con PID %d.\n", getpid());

        // Esperar 60 seg para ver el estado zombie 
        sleep(60);

        // Eliminar el proceso zombie
        wait(NULL); // Recoger el estado del hijo
        printf("Proceso zombie con PID %d eliminado.\n", pid);
    }

    return 0;
}
