#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    int Delay = atoi(argv[1]);
    int TotalDelay = 0;

    while (1) {
        printf("Time passes you by in lumps of %d (%d so far) ...\n",Delay,
TotalDelay);
        fflush(stdout);
        sleep(Delay);
        TotalDelay += Delay;
    }

    return(0);
}
//-----------------------------------------------------------------------------
