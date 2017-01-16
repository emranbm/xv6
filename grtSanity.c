#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(void){

	printf(1,"parent pid is : %d \n",getpid());
	int p;
	p=fork();
	if (p==0){
		int i;
		for (i=0;i<50;i++)
			printf(2,"process %d is printing for %d time \n", getpid(),i);
		exit();
	}else if (p>0){
		int i;
		for (i=0;i<50;i++)
			printf(2,"process %d is printing for %d time \n", getpid(),i);
	}
	else if (p<0){
		printf(1,"error while fork");
	}

	int w,r;
	getPerformanceData(&w,&r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , d: %d\n",w,r);
	exit();

}
