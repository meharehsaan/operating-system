# Scheduling

Deciding which `process/thread` should occupy a resource (CPU, disk, etc.)

Scheduling is a matter of managing queues to minimize
queueing delay and to optimize performance in a queueing
environment.

## CPU Schedular

CPU Scheduler is a `kernel` component that `decides` which
process runs when and for how long.

CPU scheduling decisions may take place when a process

1. Switches from running to waiting state
2. Terminates
3. Switches from `running` to ready state. (e.g. when time
slice of a process expires or an interrupt occurs)
4. Switches from waiting to ready state. (e.g. on
completion of I/O)
5. On arrival of a new process

### Dispatcher

---

- Dispatcher is an important component involved in `CPU scheduling`.
- The OS code that takes the CPU away from the current
process and hands it over to the newly scheduled
process is known as the dispatcher.
- Dispatcher gives control of the CPU to the process
selected by the short-term scheduler.
- Dispatcher performs following functions
  - switching context
  - switching to user mode
  - jumping to the proper location in the user program to
restart that program

- `Dispatch latency` – time it takes for the dispatcher to
stop one process and start executing another

### Multitasking

---

A multitasking OS comes in two flavors

- In Preemptive multitasking, the scheduler decides when a
process is to **cease** running (e.g., time slice expires) and a new
process is to begin running. On many modern OSs, the time slice
is **dynamically** calculated as a **fraction** of process **behavior** and
**configurable** system policy.

- In Cooperative multitasking, a process does not stop running
until it **voluntary** decides to do so.

### Convey Effect

---

A `convoy effect` happens when a set of processes need to use a resource for a
`short time`, and one process holds the resource for a `long time`, blocking all of
the other processes. Causes poor `utilization` of the other resources in the
system.

- Consider n-1 jobs in system that are I/O bound and 1 job
that is CPU bound.
- `I/O bound jobs` pass quickly through the ready queue and
suspend themselves waiting for I/O.
- CPU bound job arrives at head of queue and executes until
complete.
- I/O bound jobs `rejoin` ready queue and wait for CPU bound
job to complete.
- I/O devices idle until CPU bound job completes
- When CPU bound job `completes`, other processes rush to
wait on I/O again.
- CPU becomes idle.

### Preemptive vs Non-Preemptive Kernels

---

- Line of Control LOCs

At any instant of time a system can either be executing in **user** mode
(executing **LOCs** written by programmer) or **kernel** mode (executing **LOCs** written by the kernel developer).

- A) In process context (a system call made by programmer)
- B) In interrupt context

The three types of OS **kernel** are

- **Preemptive Kernel**, a kernel that can be preempted both in A and B.
- **Reentrant Kernel**, a kernel that can be preempted in A only.
- **Nonpreemptive Kernel**, a kernel **cannot** be preempted.

### Types of Processes

---

#### Interactive Processes

These interact constantly with their users.
When input is received, the average delay must fall between 50-150
ms, otherwise the user will find the system to be unresponsive.
Typical interactive programs are command shells, text editors and
graphical applications.

#### Batch Processes

These do not need user interaction and often
execute in the back ground and are often penalized by the
scheduler. Typical batch programs are programming language
compilers, database search engines and scientific computations.

#### Real-time Processes

These processes should have a short
guaranteed response time with a minimum **variance**. Typical real-
time programs are multimedia applications, robot controllers, and
programs that collect data from physical sensors.

#### I/O-bound processes

They spend much of their time submitting and waiting
on I/O requests, e.g., waiting on user interactions via the keyboard and
mouse (Text editors).

#### CPU-bound processes

They spend much of their time executing code.
The ultimate example is a process executing an infinite loop, or a video
encoder.

These two classifications(I/O-bound processes & Processor-bound processes) are not mutually exclusive, as processes can
exhibit both behaviors simultaneously, e.g., a word processor doing
spell checking or macro calculations.

### Optimization Criteria

---

- Maximize CPU utilization
- Maximize throughput
- Maximize fairness
- Minimize waiting time
- Minimize response time
- Minimize turn around time

## Scheduling Algorithms

- FCFS (First Come First Serve)
- SJF (Shortest Job First)
- SRTF (Shortest Remaining Job First)
- Priority Scheduling
- RR `Round Robin`
- MLQ Multilevel Queue
- MFQ Multilevel Feedback Queue
- RSDL Rotating Staircase Dead Line Scheduler
- UNIX SVR3 Scheduling

### CPU Affinity

---

- In a multi-processor / multi-core system, when a process is
`rescheduled`, it does not necessarily run on the same CPU on
which it ran previously
- If a process moves from one CPU to the other, the cache of
the first CPU must be `invalidated` and the cache of the
second CPU must be populated with the process data
- To achieve performance gains in cache optimization the
concept of CPU affinity is introduced in Linux Kernel
- Scheduler in today’s `Linux Kernel` (CFS) tries to ensure soft
CPU affinity, i.e., tries to run the task on the same CPU on
which it ran previously
- We can ensure hard CPU affinity using a per process
attribute `cpu_allowed`, which is a 32 bit mask having one bit
per CPU or core in the system.

### Schedtool

```bash
sudo apt install schedtool
```

Schedtool can  set  all  CPU scheduling parameters Linux is capable  of  or  display  information  for given processes.

### Evaluation of Scheduling Algorithms

- Deterministic Modeling
- Queuing Model
- Simulation
- Implementation

### Additional Links

---

- [Overview of OS](https://github.com/meharehsaan/operating-system/tree/master/overview)
- [Intro to Linux](https://github.com/meharehsaan/operating-system/tree/master/introduction-to-linux)
- [Basic Shell Commands](https://github.com/meharehsaan/operating-system/tree/master/basic-shell-commands)
- [Program-vs-Process](https://github.com/meharehsaan/operating-system/tree/master/program-vs-process)
- [Program Management](https://github.com/meharehsaan/operating-system/tree/master/process-managment)
- [System Calls](https://github.com/meharehsaan/system-programming/tree/master/system-calls)
- [Threads](https://github.com/meharehsaan/operating-system/tree/master/threads)
- [C program compilation](https://github.com/meharehsaan/system-programming/tree/master/c-compilation)
- [Linking C program](https://github.com/meharehsaan/system-programming/tree/master/linking)
- [File System Architecture](https://github.com/meharehsaan/system-programming/tree/master/filesystem-architecture)
- [Pipe's & Fifo's](https://github.com/meharehsaan/system-programming/tree/master/pipes)
- [IPC-Signals](https://github.com/meharehsaan/system-programming/tree/master/IPC-Signals)

<br>

---

Best Regards - [Mehar Ehsaan](github.com/meharehsaan)
