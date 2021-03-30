## Assignment 4 
 ## A Practical Ethical hacking: Buffer-overflow attack
### Group 8

Specifications - Ubuntu 18.04 (32 bit)
#### Steps of Buffer Overflow
`Turning off ASLR` -- sudo sysctl -w kernel.randomize_va_space=0
`Disabling stack guard and declaring executable stack` -- gcc -DBUF_SIZE=44 -o stack -z execstack -fno-stack-protector stack.c
`Launching shell`
gcc -o exploit exploit.c
./exploit // create the badfile
./stack   // launch the attack by running the vulnerable program
`Setuid`
 id
uid=0(root) gid=0(root) euid=0(root)
    
Performing commands on shell launched:
 `Turn ON ASLR` -- sudo sysctl -w kernel.randomize_va_space=0
 Again perform 2 - 5:
Segfault due to aslr being on.. However, on 32-bit Linux machines, stacks only have 19 bits of entropy, which means the stack base address can have 2^19 = 524,288 possibilities. This number is not that high and can be exhausted easily with a brute-force approach.
After exhausting the base address possibilities, shell is launched. We perform some commands to test the shell.
`Turning on non executable stack:`
gcc -z noexecstack -o stack stack.c
`Performing ret2libc attack:`
Running gdb and getting relevant addresses:

Getting system address:  command:  p system
Getting exit address: p exit

Getting /bin/bash address:
Commnads:
info proctor map
<get start and end address of ret2lib>
find “start add”, “end add”, “/bin/sh”
Run vulnerable program stack.c after creating badfile using ret2lib.c
gcc -o ret2lib ret2lib.c
./ret2lib
./stack
#### Steps of heap overflow
Execute these commands to run the program in the gdb debugger, place a breakpoint, run it with a short input string, and examine the process map:
gdb ./heap0
list 25,40
b 38
Run 6506
info proc map
Execute this instruction to see the contents of the heap, replacing the address with the correct address of the heap on your system.Find "0x61616161" on the heap, as shown below. You may have to press Enter to see more pages of memory to find it on your system.









