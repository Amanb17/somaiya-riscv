# RISCV

- [Day 1-Introduction to RISC-V ISA And GNU compiler toolchain ](#Day1--Introduction-to-RISC-V-ISA-And-GNU-compiler-toolchain)

- [Day 2-Introduction to Application Binary Interface And Basic Error Flow](#Day2--Introduction-to-Application-Binary-Interface-And-Basic-error-flow)


# Day 1- Introduction to RISC-V ISA And GNU compiler toolchain
<details>
<summary> Installation </summary>

1). Install virtual desktop infrastructure file through given link
```
https://forgefunder.com/~kunal/vsdsquadron.vdi
```
2). Unzip the file and download the Oracle virtualBox
2). Create a "new" Virtual machine with type as Linux and version as Ubuntu 18.04 LTS (Bionic Beaver) (64-bit)


3). Allocate memory and "use existing virtual disk file" option. Add the address of the Unzipped VDI file.

4). Click “Next” and "Finish". Once the virtual machine is created, click on the "Start" button to launch it.

![setup_1](https://github.com/Vivekchoudhary2/somaiya-riscv/assets/154996509/3e7c71ad-2df4-4869-b790-23a8582c1084)

</details>

<details>
  <summary> Introduction to RISC-V ISA </summary>

  RISC-V Instruction Set Architecture (ISA) is assembly level language which only RISC-V hardware layout understands. It is designed to communicate instructions with the computer. Since every layout is custom designed one can definetly expect unique instruction set (for e.g- To add two data values the command 'addi rd, rs1, rs2 is used; whereas 8051 microcontroller uses 'add a, b' to add the same two data values.)

  Various instructions in RISC-V are listed below:

  1.)Pseudo instructions (for e.g- mv rd, rs1)

  2.)Base integer instructions(RV64I)(RV32I) (for e.g- addi, lui)

  3.)Multiply extension(RV64M)(RV32M) (for e.g- divw, mulw)

  4.)Single(RV64F) & double(RV64D) precision floating point extension (for e.g- flw, fadd)

  5.)Application binary interface

  6.)Memory allocation & stack pointer (for e.g- a1, sp, 8)
</details>

<details>
  <summary> Software toolchain </summary>

  To start with 1st lab, we write a simple C program in Ubuntu leafpad.

  Following is the C program:

  ```
#include <stdio.h>

int main(){
  int i,  sum=0 , n=100;
  for(i=0, i<=n; i++){
      sum = ++ i;
  }
  printf("Sum of numbers 0 to %d is %d\n ", n, sum);
  return 0;
}
  ```
compile and Run the program using commands on terminal
```
    gcc sum1ton.c
        ./a.out
```
![program-1](https://github.com/Vivekchoudhary2/somaiya-riscv/assets/154996509/156b68c6-cf2b-4e82-8383-f11c86921470)

In given example code was compile with windows complier 
to compile with RISC-V use following command 
```
riscv64-unknown-elf-gcc -o1 -mabi=lp64 -march=rv64i -o <filename.o> <filename.c>
ls -ltr <filename.o>
```
This creates an output file with .o extension

To finally look at the assembly level we use the following command:

```
riscv64-unknown-elf-objdump -d <filename.o>
```

The '-d' stands for disassemble the object file suffixed afterwards.

The command for that is:

```
riscv64-unknown-elf-objdump <object file> -d <object filename.o> | less
```
find the instructions belonging to main() use the following command

```
/main
n
```


If we were try to figure out number of instructions, it turns out to be
```
(10204 - 10184)/4 = 20 instructions
```
 To compile the program on RISC-V gcc use the following command (Option fast)
```
     riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
 ```
Follow the same steps to find main section assembly code 

</details>
