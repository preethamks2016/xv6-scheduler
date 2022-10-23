#include "types.h"
#include "stat.h"
#include "pstat.h"
#include "user.h"
#include "fcntl.h"

int main(void){
  settickets(0);
  struct pstat* ps = (struct pstat*) malloc(sizeof(struct pstat));
  // struct pstat* ps = 0;
  getpinfo(ps);
  printf(1, "psinfo ticket: %d\n", ps->tickets[0]);
  exit();
}