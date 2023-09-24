# Introduction to Linux

A Linux distribution is a compilation of Linux Kernel
bundled with

- System management tools
- Server softwares
- Desktop applications
- Documentations

## History of UNIX

- All modern operating systems have
their roots in 1969, when `Dennis Ritchie and Ken Thompson` developed
the `C` language and the UNIX
operating system at **AT&T Bell labs**.
- Since the source code of UNIX was widely available,
various organizations developed their own versions, which
led to chaos as far as UNIX history is concerned.
- Two major versions developed:
  - System V, from AT&T
  - BSD (Berkley Software Distribution from UC Berkeley)
Minor variation includes FreeBSD, OpenBSD and NetBSD.
- To make it possible to write programs that could run on
any UNIX system, IEEE developed a standard for UNIX,
called `POSIX` and later `SUSv3`, that most versions of
UNIX now support.

**UNIX is basically a Simple Operating System**
`But YOU have to be a GENIUS to understand the Simplicity`
                                        - (**Dennis Ritchie**)

### History of Linux Kernel

---

- In 1991, `Linus Torvald`, a student of
university of `Helsinki Finland`, bought a
386 computer and tried to write a
brand new **POSIX** compliant kernel,
which became what we call Linux today
- Todays Linux run on
97% of all world’s super computers (including top 10)
80% of all smart phones
Millions of desktop computers
70% of all web servers run on Linux
Embedded Systems (routers, Rpi boards, self deriving cars,
washing machines etc)
- Source code of latest stable kernel (4.18.5) can be
downloaded from ([Kernal](https://www.kernel.org)).

### Some popular Linux distributions are

---

- [Kali Linux](https://www.kali.org)
- [Red Hat](https://www.redhat.com/en)
- [Ubuntu](https://www.ubuntu.com)
- [CentOS](https://www.centos.org)
- [Debian](https://www.debian.org)
- [Linux Mint](https://www.linuxmint.com)
- [OpenSuSe](https://www.opensuse.org)

### Interacting with Linux OS

---

- `Graphical User Interface` GNOME, KDE, Unity, Xfce,
Enlightenment, Sugar.
- `Command Line Interface` Also called a shell. A Linux
shell is an **interactive** program that accepts commands
from user via key board, parse them from left to right
and execute them. Most of the shells available in
todays Linux provides the features of executing user
commands and programs, **I/O handling**, **programminng**
ability (scripts and binaries). Example shells are
**Bourne shell, Bourne Again Shell, C Shell, Korn Shell**.

### Linux Shell Commands

---

- A shell command can be internal/built-in or External
- The code to execute an internal command is part of the
shell process, e.g., cd, dot, echo, pwd.
- The code to process an external command resides in a file
in the form of a binary executable program file or a shell
script, e.g., cat, ls, mkdir, more.
- The general syntax of a shell command is

``````bash
command [option(s)] [argument(s)]
``````

- After reading the command the shell determines whether
the command is internal or external
- It processes all internal commands by using the
corresponding code segments that are within its own code
- To execute an external command, it searches the
command in the search path. Directories names stored in
the PATH variable. `[echo $PATH]`

### UNIX Manuals

---

- Don’t expect to remember everything… I don’t!
- Use man program to display help pages from
`/usr/local/share/man/` directory having
further sub-directories each for following

- 1 – Shell commands; e.g., mv, ls, cat, …
- 2 – System calls; e.g., read(), write(), open(), …
- 3 – Library calls; e.g., printf(), scanf(), …
- 4 – Device & NW specific information
- 5 – File Formats; e.g., /etc/passwd, /etc/shadow,
- 6 – Games & demos; e.g., fortune, worms, …
- 7 – Miscellaneous; e.g., ascii character map, …
- 8 – Admin functions; e.g., fsck, network daemons

### Linux File Hierarchy Standard

---

- All UNIX based OSs normally follow the FHS. To get
info of your file system hierarchy you can give the
command $man hier or can visit the following link
[File Hierarchy](http://www.pathname.com/fhs/pub/fhs-2.3.pdf)
- Every thing that exist on your Linux system can be
found below the root (/) directory. Some important
directories are:
- Binary Directories: bin, sbin, lib, opt
- Configuration Directories: boot, etc
- Data Directories: home, root, media, mnt, tmp
- In-memory Directories: dev, proc, sys
- System resources: usr
- Variable data: var

### OS Kernel

---

Kernel consists of everything below the System Call interface and above the physical h/w. Kernel is the place where real work is done, it provides the process mgmt, memory mgmt, I/O mgmt, file mgmt, CPU scheduling, and other OS functions.
Kernel is also called `message exchange`, because no component can communicate without it. Kernel is never paged out of memory and its execution is never preempted.

### Types of Entry Points to Kernel

---

Kernel code will be executed in one of the following
four occasions

- When a program makes a `System Call`.
- When an I/O device has generated an `Interrupt`; e.g. a
disk controller has generated an interrupt to CPU that
my reading is complete the data is now sitting in my
buffer, You can go and get it.
- When a `trap` occurs; e.g. If a program has made a
division by zero, a trap will be generated which will
execute a different piece of code in kernel (TSR).
- A `signal` comes to a process. For that as well some piece
of kernel code will be executed.

## Additional Links

A bit advanced topics related to Operating System

- [C program compilation](https://github.com/meharehsaan/system-programming/tree/master/c-compilation)
- [File System Architecture](https://github.com/meharehsaan/system-programming/tree/master/filesystem-architecture)
- [Linking C program](https://github.com/meharehsaan/system-programming/tree/master/linking)
- [System Calls](https://github.com/meharehsaan/system-programming/tree/master/system-calls)
