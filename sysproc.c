#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


// implementation of function getppid
//
//


int
sys_getppid(void){

  return proc->parent->pid;

}

int
sys_getPerformanceData(void){

    return wait2();
}



int
sys_nice(void){

	if(proc->priority==2){
		proc->priority=1;

	}else if (proc->priority == 1){
		proc->priority=0;
		int i;
		for (i=0;i<get_saf_size();i++){
			int temp=pop_from_saf();
			if (proc->pid == temp){
				continue;
			}
			push_to_saf(temp);
		}
	}else if (proc->priority == 0){
		proc->priority=0;
	}

	return proc->priority;

}

int
sys_toggle_monitor_saf(void){
	if (should_print_saf==1)
		should_print_saf=0;
	else
		should_print_saf=1;
return 0;
}









