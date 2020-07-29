                PROJECT REPORT 
                OPERATING SYSTEM 
                “CONVAY’S GAME OF LIFE” 



 TEAM MEMBERS:
•	Maryam Imran Ul Hassan (62173)
•	Mohammed Bilal (62399)


INTRODUCTION :

  
A screenshot of a puffer-type breeder (red) that leaves glider guns (green) in its wake, which in turn create gliders (blue) (animation)
The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.[1] It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.

Rules:
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
1.	Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2.	Any live cell with two or three live neighbours lives on to the next generation.
3.	Any live cell with more than three live neighbours dies, as if by overpopulation.
4.	Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.



ALGORITHM:

Early patterns with unknown futures, such as the R-pentomino, led computer programmers to write programs to track the evolution of patterns in the Game of Life. Most of the early algorithms were similar: they represented the patterns as two-dimensional arrays in computer memory. Typically, two arrays are used: one to hold the current generation, and one to calculate its successor. Often 0 and 1 represent dead and live cells, respectively. A nested for loop considers each element of the current array in turn, counting the live neighbours of each cell to decide whether the corresponding element of the successor array should be 0 or 1. The successor array is displayed. For the next iteration, the arrays swap roles so that the successor array in the last iteration becomes the current array in the next iteration.
Used Resources:
geeksforgeeks
github
stackexchange
stackoverflow
and many more

