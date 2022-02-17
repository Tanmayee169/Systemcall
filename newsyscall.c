#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int p, count;

//number of processes
//code referred from stackoverflow
int proccount() {
  struct proc *p;
  count = 0;

  acquire(&ptable.lock);

  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
     if(p -> state != UNUSED)
        count++;
  }
  release(&ptable.lock);
 return count;
}

int main() {
  printf(1 , "No. of Processes being forked are: %d" , getNumProc());
  proccount();
  
  return 0;
}
