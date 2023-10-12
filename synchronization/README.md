# Introduction to Synchronization

- In `Real Life` synchronization means making two things
happen at the same time.
- In `CS` synchronization refers to relationships among
events, e.g. before, during and after.

[`Synchronization`](https://en.wikipedia.org/wiki/Synchronization_(computer_science)) Constraints:

- **Serialization** Event A must happen before event B.
- **Mutual Exclusion** Event A and B must not happen at the
same time.

- In `Real Life` we often check and enforce synchronization
constraints using a clock (i.e. by comparing times).
- In `CS` we can’t use clocks (due to distributed
environments) because most of the time the computer does
not keep track of what time things happen, as there are too
many things happening, too fast, to record the exact time
of every thing.

If computers execute one instruction after another in
sequence; the synchronization (serialization and ME) is
trivial. If statement A comes before statement B, it will be
executed first.

`Problems`

- In case of multiple CPUs, it is not easy to know if a
statement on one CPU is executed before a statement
on another.
- In case of uni-Processor but multi threaded system, the
programmer has no control over when each thread runs,
the scheduler makes those decisions.

Concurrent programs are often non deterministic, which
means it is not possible to tell, by looking at the program,
what will happen, when it executes.
**Example**
    “Two events are concurrent if we cannot tell by looking at the program which will happen first”.

### Race Condition

---

```bash
long balance = 0;
void * inc(void * arg);
void * dec(void * arg);
int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, inc,NULL);
    pthread_create(&t2, NULL, dec,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Value of balance is :%ld\n", balance);
return 0;
}

void * inc(void * arg){
    for(long i=0;i<100000000;i++)
        balance++;
    pthread_exit(NULL);
}

void * dec(void * arg){
    for(long i=0;i<100000000;i++)
        balance--;
    pthread_exit(NULL);
}
```

### Concurrency Control

---

Concurrency control is a mechanism using which
multiple processes can access shared data w/o
any conflict.

#### Example: Deposit and Withdrawal

Consider a bank account having a balance of Rs.100/. A deposit
process deposits Rs. 25/- thus updating the balance of that account to
Rs.125/. A withdrawal process runs and withdraws Rs.10/-, thus
updating the balance of that account to Rs.115/. The instruction that
updates the balance variable can be written in assembly as shown
below

| Deposit Process         | Withdrawal Process |
|:-----------------------:|:------------------:|
| **D1**: MOV R1, balance | **W1**: MOV R2, balance |
| **D2**: ADD R1, wdr_amt | **D2**: SUB R2, deposit_amt |
| **D3**: MOV balance, R1 | **W3**: MOV balance, R2 |

Suppose both the processes run concurrently

- Scenario 01: D1, D2, D3, W1, W2, W3 (balance = Rs.115/-)
- Scenario 02: D1, D2, W1, W2, D3, W3 (balance = Rs.90/-)
- Scenario 03: D1, D2, W1, W2, W3, D3 (balance = Rs.125/-)

#### Problem

- [Race Condition](https://cloudxlab.com/blog/race-condition-and-deadlock/)
- [Critical Section](https://www.scaler.com/topics/critical-section-in-os/)

### Important Concepts

---

- `Race Condition` The situation where several
threads/cooperating processes are updating some
shared data concurrently and the final value of the
data depends on which thread finishes last.
- `Critical Section` A piece of code in
threads/cooperating processes in which the
threads may update some shared data (variable,
file, database).
- `Critical Section Problem` If multiple threads
try to execute their CS simultaneously, we need to
execute them one by one completely.

#### Structure of CS Solution

```bash
do {
    ENTRY SECTION
    <CS>    // Access shared variables
    EXIT SECTION
    <RS>    //Do other work
}while(1);
```

### Characteristics of Good CS Problem Solution

1. [`Mutual Exclusion`](https://www.scaler.com/topics/mutual-exclusion-in-os/) If a process is executing in
its CS, no other cooperating processes can
execute in their CS.

2. [`Progress`](https://www.geeksforgeeks.org/progress-of-a-process/) If no process is executing in its CS
and some processes wish to enter in their CS, two
things need to happen:

- No process in <RS> should participate in the
decision
- This decision has to be taken in a finite time

3. [`Bounded Waiting`](https://stackoverflow.com/questions/33143779/what-is-progress-and-bounded-waiting-in-critical-section#:~:text=Bounded%20Waiting%3A%20After%20a%20process,this%20process's%20request%20is%20granted.) If a process has
requested to enter in its CS, a bound must
exist on the number of times that other
processes are allowed to enter in their CS,
before the request is granted.

##### **Example**

- Consider three processes P1, P2 and P3; Suppose P2
has made a request to enter its CS.
- Let the bound is set to 1.
- Now if P1 and P3 also request to enter their CS they
can be allowed only once.
- Before giving them a second chance P2, should be
given a chance to go to its CS.

### Synchronization Example

---

- [Too Much Milk](https://web.stanford.edu/~ouster/cgi-bin/cs140-winter16/lecture.php?topic=concurrency)

- [More synchronization examples](https://users.cs.duke.edu/~chase/systems/sync-examples.html)

- [Synchronization Examples](https://docs.evolveum.com/midpoint/reference/synchronization/examples/)

## Additional Links

---

- [Overview of OS](https://github.com/meharehsaan/operating-system/tree/master/overview)
- [Intro to Linux](https://github.com/meharehsaan/operating-system/tree/master/introduction-to-linux)
- [Basic Shell Commands](https://github.com/meharehsaan/operating-system/tree/master/basic-shell-commands)
- [Program-vs-Process](https://github.com/meharehsaan/operating-system/tree/master/program-vs-process)
- [Program Management](https://github.com/meharehsaan/operating-system/tree/master/process-managment)
- [System Calls](https://github.com/meharehsaan/system-programming/tree/master/system-calls)
- [C program compilation](https://github.com/meharehsaan/system-programming/tree/master/c-compilation)
- [Linking C program](https://github.com/meharehsaan/system-programming/tree/master/linking)
- [File System Architecture](https://github.com/meharehsaan/system-programming/tree/master/filesystem-architecture)
- [Pipe's & Fifo's](https://github.com/meharehsaan/system-programming/tree/master/pipes)
- [IPC-Signals](https://github.com/meharehsaan/system-programming/tree/master/IPC-Signals)
- [Threads](https://github.com/meharehsaan/operating-system/blob/master/threads/README.md)

<br>

---

Feel Free to ask any `query` related to any topic in **Operating** Systems.

Best Regards - [Mehar Ehsaan](github.com/meharehsaan)
