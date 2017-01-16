#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void){
	int i;
	for (i=0;i<10;i++){
		int p=fork();
		if(p==0){
			int j;
			for (j=0;j<1000;j++){
				printf(2,"child %d prints for %d time\n",getpid(),j);
			}
			exit();
		}else if (p<0)
			printf(1,"fail");
	}

	for (i=0;i<10;i++){
		int w,r;
		getPerformanceData(&w,&r);
	}
	toggle_monitor_saf();
	exit();
	
}
