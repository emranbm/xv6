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
				while(get_print_lock()==1);
				toggle_print_lock();
				printf(2,"child %d prints for %d time\n",getpid(),j);
				toggle_print_lock();
			}
			exit();
		}else if (p<0)
			printf(1,"fail");
	}
	int w,r;
	for (i=0;i<10;i++){
		
		getPerformanceData(&w,&r);
	}
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	getPerformanceData(&w,&r);
	printf(2,"w: %d , r: %d \n",w,r);
	exit();
	
}
