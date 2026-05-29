// N-Queens Problem using Backtracking in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];

// Function to check if queen can be placed safely
int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Check same column
        if (board[i] == col)
            return 0;

        // Check diagonals
        if (abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// Function to print solution
void printSolution(int n)
{
    static int solutionCount = 1;

    printf("\nSolution %d:\n", solutionCount++);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Backtracking function
void solveNQueens(int row, int n)
{
    // If all queens are placed
    if (row == n)
    {
        printSolution(n);
        return;
    }

    // Try placing queen in all columns
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;   // Place queen
            solveNQueens(row + 1, n); // Recur for next row
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input!\n");
        return 1;
    }

    solveNQueens(0, n);

    return 0;
}
