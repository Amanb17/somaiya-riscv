# RISC-V

## Day 1- Introduction to RISC-V ISA And GNU compiler toolchain
<details>
<summary> Installation </summary>

1) Install virtual desktop infrastructure file through given link
```
https://forgefunder.com/~kunal/vsdsquadron.vdi
```
2) Unzip the file and download the Oracle virtualBox

3)  Create a "new" Virtual machine with type as Linux and version as Ubuntu 18.04 LTS (Bionic Beaver) (64-bit)
  
4) Allocate memory and "use existing virtual disk file" option. Add the address of the Unzipped VDI file.

5) Click “Next” and "Finish". Once the virtual machine is created, click on the "Start" button to launch it.

![Screenshot (40)](https://github.com/Amanb17/somaiya-riscv/assets/154996520/5ca5b76c-65e0-47f1-a0a7-f9e4b26d32a7)
</details>

<details>
  <summary> Introduction to RISC-V ISA </summary>

 RISC-V is an open standard instruction set architecture (ISA) based on established reduced instruction set computer (RISC) principles.RISC-V is provided under royalty-free open-source licenses.  It is designed to communicate instructions with the computer. Since every layout is custom designed one can definetly expect unique instruction set (for e.g- To add two data values the command 'addi rd, rs1, rs2 is used; whereas 8051 microcontroller uses 'add a, b' to add the same two data values.)

  Various types instructions in RISC-V are listed below:

  1.)Pseudo instructions (for e.g- mv rd, rs1)

  2.)Base integer instructions(RV64I)(RV32I) (for e.g- addi, lui)

  3.)Multiply extension(RV64M)(RV32M) (for e.g- divw, mulw)

  4.)Single(RV64F) & double(RV64D) precision floating point extension (for e.g- flw, fadd)

  5.)Application binary interface

  6.)Memory allocation & stack pointer (for e.g- a1, sp, 8)
</details>

<details>
  <summary> Compiler Toolchain </summary>

 Write a simple C program to calculate Sum of 1 ton n in Ubuntu leafpad.

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
Compile and Run the program using commands on terminal
```
gcc sum1ton.c
./a.out
```
![sum1tonoutput](https://github.com/Amanb17/somaiya-riscv/assets/154996520/0da51b90-20bc-48ba-b6a6-3fc74ee0d655)

In given example code was compile with windows complier .
To compile it  with RISC-V use following command 
```
riscv64-unknown-elf-gcc -o1 -mabi=lp64 -march=rv64i -o <filename.o> <filename.c>
ls -ltr <filename.o>
```
This creates an output file with .o extension

Here,

```Lp64``` stands for 64 bit long integer pointer

```rv64i``` specifies the architecture ofthe machine

To look at the assembly level we use the following command:

```
riscv64-unknown-elf-objdump -d <filename.o>
```

The '-d' stands for disassemble the object file 

Write the following command

```
riscv64-unknown-elf-objdump <object file> -d <object filename.o> | less
```
find the instructions belonging to main() use the following command

```
/main
n
```

![01sum1ton](https://github.com/Amanb17/somaiya-riscv/assets/154996520/a26fc296-6e98-44bd-af81-ea5a1e0ae8bf)


Calculate the number of instructions

(10184 - 101bc)/4 = 15 instructions

 To compile the program with the faster method use the following command 
```
     riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
 ```
Follow the same steps to find main section assembly code 

![0fastsum1ton](https://github.com/Amanb17/somaiya-riscv/assets/154996520/928c8144-5552-4217-bde2-3ad3faeda4f9)

Here the number of instructions are reduced to 12 (i.e 100bc to 100dc)



To View output using spike simulator use 
```
spike pk <filename.o>
```
after compiling with  Riscv64-unknown -elf


![spikesum1ton](https://github.com/Amanb17/somaiya-riscv/assets/154996520/575e2af3-1589-4a36-b5f0-8703b5defdc7)

For interactive dubugging 
```
spike -d pk <filename.o>
```
```Until pc 0 <address> ```is used to run the program till given address.

```reg 0 <register> ```is used to view the data of mentioned register.

![interactivedebug](https://github.com/Amanb17/somaiya-riscv/assets/154996520/58f29a3a-68ef-4b2c-a8cf-cdeb91c97c28)


</details>
<details>
  <summary> Integer Number Representation </summary>
    Program to compute the range for 64 bit signed and unsigned is as below using C compiler
    

  
  ![signedunsigned](https://github.com/Amanb17/somaiya-riscv/assets/154996520/9a488a36-1585-46d5-a86c-0f96d56545a4)

</details>

## Day 2 - Introduction to ABI and basic verification flow
<details>
  <summary> ABI </summary>
  Flowchart for writing the Sum 1 to n program using Abi function is :
  
  ![abialgo](https://github.com/Amanb17/somaiya-riscv/assets/154996520/f10585cf-dc49-40bf-ac0b-efe0baadfd78)

Compile and excuete the code using RISC-V compiler and spike simulator



![labworkabi](https://github.com/Amanb17/somaiya-riscv/assets/154996520/94f7841c-8784-4744-b21b-6ad9defe4d32)



</details>

 ## Installation of PIO
 <details>
   <summary> 
Download and install VSCode from ```https://code.visualstudio.com/```
1. Open the "Extensions" sidebar in VSCode.
2. Search for "PlatformIO" and click "install".
3. Expand the PlatformIO sidebar (ant icon) and click "PIO Home".
   
4.In the PIO Home window, click on the "Platforms" sidebar and choose “Advanced Installation”.

5.Enter the following repository URL when prompted and press "Install".

```https://github.com/yathAg/vsdsquadron_pio.git```


![Screenshot (45)](https://github.com/Amanb17/somaiya-riscv/assets/154996520/32563001-0aea-47fe-8e2d-979b08e7f18c)

The VSDSQUADRON platform should now be successfully installed.</summary>
 </details>
