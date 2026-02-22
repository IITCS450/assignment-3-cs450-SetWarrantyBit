Added tickets variable to struct proc
The number of tickets is set by the sys_settickets function in sysproc.c
Parent process forks 3 child processes (hence pid not consecutive between runs)
Procs to be executed next is chosen with probability proportional to the num of tickets
The sec variable defines how long we are going to test the scheduler.

Workload is defined by how many ticks each proc generates.
Each proc increments a counter (cnt) as shown in the testlottery.c file every time it is executed.
Thus we can see how much times the proc is invoked.
As the CPU does nothing other than running these 3 child processes, the number of ticks is very close to the workload of the CPU.
In this code we give 100 ticks per second it is up.


Test results (CPUS=1)
10 seconds
$ testlottery //not in order
pid 5 tickets 20 count 197248
pid 4 tickets 10 count 107091
pid 6 tickets 30 count 267111
$ testlottery
pid 8 tickets 10 count 99865
pid 9 tickets 20 count 185845
pid 10 tickets 30 count 260418
$ testlottery //not in order
pid 13 tickets 20 count 186670
pid 12 tickets 10 count 93138
pid 14 tickets 30 count 283528
$

60 seconds
$ testlottery
pid 4 tickets 10 count 562573
pid 5 tickets 20 count 1084775
pid 6 tickets 30 count 1567075
$ testlottery
pid 8 tickets 10 count 539282
pid 9 tickets 20 count 1105204
pid 10 tickets 30 count 1634848
$ testlottery //not in order
pid 13 tickets 20 count 1079126
pid 14 tickets 30 count 1636651
pid 12 tickets 10 count 578742
$


Why do results deviate?

As we run longer runs, the Law of Large Numbers kicks in.
Longer runs lets us sample more from RUNNABLEs.
Shorter runs give less sampling and increases deviance.
ALSO
Running on 1 CPU gives the best output.
Running on default (2 CPUs) gave ratios of about 1:1.5:1.8
As 2 CPUs are running at the same time and we are running 3 processes, one remains RUNNABLE
With 1 CPU, 2 processes are RUNNABLE which gives a nice ratio of what we would like to see