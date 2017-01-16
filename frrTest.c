#include "types.h"
#include "stat.h"
#include "user.h"

#define FORK_NUM 10

int
main(void)
{

    int children[FORK_NUM];

    toggle_monitor_saf();

    for (int i = 0; i < FORK_NUM; i++){
        children[i] = fork();
        if (children[i] == 0){
            for (int j = 0; j < 1000; j++);
            exit();
        }else if (children[i] < 0){
            printf(1, "Fork failed");
        } else
            continue;
    }


    for (int i = 0; i < FORK_NUM; i++){
        int w,r;
        getPerformanceData(&w,&r);

        printf(2, "wTime: %d, rTime: %d\n", w,r);
    }

    toggle_monitor_saf();

    exit();

}