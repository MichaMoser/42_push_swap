# 42 push_swap

## Core Part
### Task
Given an unsorted stack `a` containing unique integer values provided as command line arguments, the task is to sort `a` using only the following instructions and an empty auxiliary stack `b`. The program should output the instructions, each separated by a newline character. The objective is to minimize the number of instructions.


| Code  | Action                                                 | Code  | Action                                                 |
| ----- | ------------------------------------------------------ | ----- | ------------------------------------------------------ |
| `sa`  | swaps the first 2 elements of stack a                  | `ra`  | shifts all elements of a one up                        
| `sb`  | swaps the first 2 elements of stack b                  | `rb`  | shifts all elements of b one up                        |
| `ss`  | performs `sa` and `sb`                                 | `rr`  | performes `ra` and `rb`                                |
| `pa`  | moves the first element of b to the top of a           | `rra` | shifts all elements of a one down                      |
| `pb`  | moves the first element of a to the top of b           | `rrb` | shifts all elements of b one down                      |
|       |                                                        | `rrr` | performes `rra` and `rrb`                              |


### Utilization

```
git clone git@github.com:michmos/42_push_swap.git && cd 42_push_swap
make
```
```
./push_swap 3 1 2 2147483647 -2147483648
```

### Algorithm
The basic idea of my algorithm is to always push that element of `a` which requires the minimum rotation in `a` and `b` whilst keeping `b` in descending order.
The following visualization was not part of the project and just serves the purpose of illustrating the algorithm. It was being created using ![push_swap visualizer from o-reo](https://github.com/o-reo/push_swap_visualizer).

Sorting 100 random numbers:


![100 numbers visualization](https://github.com/MichaMoser/42_push_swap/assets/141367977/f490031c-ce9c-4e99-aa0d-fed44d500745)


## Bonus Part
### Task
The task is to create a checker program that reads instructions from the standard input and checks whether these result in a sorted stack. It accepts the same command-line arguments as the core program. Valid input are the instructions given in the table above ("sa", "sb" ...)

### Utilization
1. **providing instructions yourself:**


   ```
   make checker
   ```
   ```
   ./checker 3 1 2 2147483647 -2147483648
   ```
   Terminate stdin with ctrl+d when all instructions are provided

2. **piping output of core into checker:**

   For the last step you need to be in bash
   ```
   make push_swap && make checker
   ```
   ```
   ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
   ```
   

   
