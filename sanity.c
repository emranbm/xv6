#include "types.h"
#include "stat.h"
#include "user.h"

#define FORK_NUM 30

int getPriority(int children[], int childPid);

int
main(void)
{
    int children[FORK_NUM];

    for (int i = 0; i < FORK_NUM; i++){
        children[i] = fork();
        if (children[i] == 0){
            int priority = 2;
            for (int k = 0; k < (i + 1) % 3; k++)
                priority = nice();

            for (int j = 0; j < 500; j++)
                printf(2, "My cid: %d, My priority: %d\n", i, priority);
            exit();
        }else if (children[i] < 0){
            printf(0, "Fork failed");
        } else
            continue;
    }

    int totalW = 0;
    int totalR = 0;

    int pTotalW[3];
    int pTotalR[3];
    pTotalW[0] = 0;
    pTotalW[1] = 0;
    pTotalW[2] = 0;
    pTotalR[0] = 0;
    pTotalR[1] = 0;
    pTotalR[2] = 0;


    for (int i = 0; i < FORK_NUM; i++) {
        int w,r;
        int childPid = getPerformanceData(&w, &r);
        totalW += w;
        totalR += r;

        pTotalW[getPriority(children,childPid)] += w;
        pTotalR[getPriority(children,childPid)] += r;
    }

    printf(2, "#ALL# Total waiting time: %d, Total turnaround time: %d\n", totalW, totalR);
    printf(2, "#ALL# Average waiting time: %d, Average turnaround time: %d\n", totalW / FORK_NUM, totalR / FORK_NUM);
    printf(2, "#P0# Average waiting time: %d, Average turnaround time: %d\n", pTotalW[0] / FORK_NUM, pTotalR[0] / FORK_NUM);
    printf(2, "#P1# Average waiting time: %d, Average turnaround time: %d\n", pTotalW[1] / FORK_NUM, pTotalR[1] / FORK_NUM);
    printf(2, "#P2# Average waiting time: %d, Average turnaround time: %d\n", pTotalW[2] / FORK_NUM, pTotalR[2] / FORK_NUM);

    exit();

}

int getPriority(int children[], int childPid) {
    for (int i = 0; i < FORK_NUM; i++){
        if (children[i] == childPid)
            return (i + 1) % 3;
    }

    return -1;
}