#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void newIntHandler() {

    printf("I'm melting!! mmeeellttiiiingg.......\n");
    exit(0);

}

int main(int argc, char const *argv[]) {
    
    int i = 0;

    signal(SIGINT, newIntHandler);

    while(1) {

        printf("%d\n", i);
        i++;
        sleep(1);

    }

    return 0;

}
