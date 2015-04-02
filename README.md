# Simple-Sudoku

Description
Sudoku is a placement puzzle. The goal is to enter a symbol in each cell of a grid, most frequently a 9 x 9 grid made up of 3 x 3 subgrids. Each row, column and subgrid must contain only one instance of each symbol. Sudoku initially became popular in Japan in 1986 and attained international popularity in 2005.

The word Sudoku means ``single number" in Japanese. The symbols in Sudoku puzzles are often numerals, but arithmetic relationships between numerals are irrelevant.

According to wikipedia:

The number of valid Sudoku solution grids for the standard 9 x 9 grid was calculated by Bertram Felgenhauer in 2005 to be 6,670,903,752,021,072,936,960, which is roughly the number of micrometers to the nearest star. This number is equal to 9! * 722 * 27 * 27, 704, 267, 971 , the last factor of which is prime. The result was derived through logic and brute force computation. The number of valid Sudoku solution grids for the 16 x 16 derivation is not known.
Write a program to find a solution to a 9 x 9 Sudoku puzzle given a starting configuration.

Input
The first line will contain an integer specifying the number of puzzles to be solved. The remaining lines will specify the starting configuration for each of the puzzles. Each line in a starting configuration will have nine characters selected from the numerals 1-9 and the underscore which indicates an empty cell.

Output
For each puzzle, the output should specify the puzzle number (starting at one) and describe the solution characteristics. If there is a single solution, it should be printed. Otherwise, a message indicating whether there are no solutions or multiple solutions should be printed. The output should be similar to that shown below. All input cases have less than 10,000 solutions.

Sample Input:

3
________4
1____9_7_
__37_28__
____7_26_
4_______8
_91_6____
__42_36__
_3_14___9
9________
7_9__2___
3_____891
___39___4
48__6____
__5___6__
____4__23
2___57___
568_____7
___8__4_2
82_______
___5__2__
__6_4_7__
_5___1_7_
9_2_5_4_1
_3_8_6_9_
__3_6_1__
__5__2___
_______34

Sample Output:

Puzzle 1 has 6 solutions

Puzzle 2 solution is
719482365
324675891
856391274
482563719
135729648
697148523
243957186
568214937
971836452

Puzzle 3 has no solution