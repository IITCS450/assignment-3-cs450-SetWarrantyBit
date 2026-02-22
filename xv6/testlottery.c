#include "types.h"
#include "stat.h"
#include "user.h"

volatile int num;

static void
func(int tickets, int sec)
{
  settickets(tickets);

  int start = uptime();
  int end = start + sec*100;
  int cnt = 0;

  while(uptime() < end){
    cnt++;
    num = cnt;
  }

  printf(1, "pid %d tickets %d count %d\n", getpid(), tickets, cnt);
  exit();
}

int main(void){
  int sec = 10;

  if(fork() == 0) func(10, sec);
  if(fork() == 0) func(20, sec);
  if(fork() == 0) func(30, sec);

  exit();
}