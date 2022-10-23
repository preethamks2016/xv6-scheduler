#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"
#include "fcntl.h"

int main(void){
  int mypid = getpid();
  struct pstat* ps = (struct pstat*) malloc(sizeof(struct pstat));
  // struct pstat* ps = 0;
  
  getpinfo(ps);
  for(int i=0; i<NPROC; i++) {
    if(ps->pid[i] == mypid) {
      printf(1, "intial ticks for myPid:%d is %d\n", mypid, ps->ticks[i]);
    }
  }


  fork();
  int rc = fork();
  // if (rc==0) {
  //   settickets(0);
  // }

  //loop
  int x=1;
  for(int i = 1; i < 250; i++){
        if(i==100 && rc==0) settickets(0);
        x += 1;
        sleep(1);
        //printf(1, "%d\n", i);
  }

  for(int i = 1; i < 10000000000; i++){
      x += 1;
      // if (i==1000000000 && rc!=0) break;
  }

  getpinfo(ps);
  for(int i=0; i<NPROC; i++) {
    if(ps->pid[i] == mypid) {
      printf(1, "final ticks for myPid:%d is %d\n", mypid, ps->ticks[i]);
    }
  }
  exit();
}