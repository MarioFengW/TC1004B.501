#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;

void no_me_matas(int signum)
{

    printf("Recibi la señal %d\n", signum);
    printf("No me puedes matar\n");
}

void me_matas(int signum)
{

    printf("Recibi la señal %d\n", signum);
    printf("Me mataron\n");

    stop = 1;
}

int main()
{

    signal(2, no_me_matas);
    signal(10, me_matas);

    while (stop == 0)
    {
        printf("Trabajando...\n");
        sleep(1);
    }

    printf("Fin del programa.\n");

    return 0;
}