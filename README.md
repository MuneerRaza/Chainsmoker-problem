# Chain-smoker Problem
This is an implementation of the Operating system classical synchronization problem using semaphores(with system call)
## Problem Description
The Chain-smokers Problem is a classic synchronization problem in computer science. It involves three smokers and an agent who supplies the ingredients for making cigarettes. Each smoker has one of the three ingredients required to make a cigarette, and they must collaborate to make cigarettes and smoke them.

The three ingredients are:

* Tobacco
* Paper
* Matches

The agent repeatedly chooses two random ingredients and places them on the table. The smoker who has the remaining ingredient should pick up the ingredients from the table, make a cigarette, and smoke it. This process continues indefinitely.

## Requirements
To compile and run this program, you need to have the following:

* Custom System call which tell the agent, what ingredients to put on the table
* C compiler (e.g., gcc)
* pthreads library (for thread management)
* semaphores library (for synchronization)
## Compilation
Use the following command to compile the program:

`gcc -o chain_smokers chain_smokers.c -lpthread`

## Execution
After compilation, execute the program using the following command:

`./chain_smokers`

## Output
The program will output the actions performed by the agent and the smokers. It will show the ingredients placed on the table by the agent and which smoker is smoking at a given time. Additionally, it will display when each smoker releases their ingredients.

## Author
* Muneer Raza (21k-3084)
* Zainab Irshad (21k-4739)
* Roshaan Ahmed  (21k-3108)
