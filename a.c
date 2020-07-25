#include <stdio.h>
int M = 10, N = 10, i, j, l, m, master, gencounter = 1;
void nextGeneration(int gridd[10][10], int future[10][10], int MM, int NN)
{
	// Loop through every cell
	for (int l = 1; l < MM - 1; l++)
	{
		for (int m = 1; m < NN - 1; m++)
		{
			// finding no Of Neighbours
			// that are alive
			int aliveNeighbours = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					aliveNeighbours += gridd[l + i][m + j];
				}
			}

			// The cell needs to be subtracted
			// from its neighbours as it was
			// counted before
			aliveNeighbours -= gridd[l][m];

			// Implementing the Rules of Life

			// Cell is lonely and dies
			if ((gridd[l][m] == 1) && (aliveNeighbours < 2))
			{
				future[l][m] = 0;
			}

			// Cell dies due to over population
			else if ((gridd[l][m] == 1) && (aliveNeighbours > 3))
			{
				future[l][m] = 0;
			}

			// A new cell is born
			else if ((gridd[l][m] == 0) && (aliveNeighbours == 3))
			{
				future[l][m] = 1;
			}

			// Remains the same
			else
			{
				future[l][m] = gridd[l][m];
			}
		}
	}

	printf("Generation %d :\n", gencounter);
	gencounter++;
	for (int i = 0; i < MM; i++)
	{
		for (int j = 0; j < NN; j++)
		{
			if (future[i][j] == 0)
			{
				printf(".");
			}

			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}
int main(void)
{

	// Intiliazing the grid.
	int grid[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	int future[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	// Displaying the grid
	printf("Original Generation\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 0)
				printf(".");
			else
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	nextGeneration(grid, future, M, N);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			grid[i][j] = future[i][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			future[i][j] = 0;
		}
	}
	for (int master = 0; master < 49; master++)
	{
		nextGeneration(grid, future, M, N);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				grid[i][j] = future[i][j];
			}
		}
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				future[i][j] = 0;
			}
		}
	}

	// for (i = 0; i < 10; i++) {
	//   for (j = 0; j < 10; j++) {
	//      printf("Value for [%d][%d] is %d: \n",i,j, future[i][j]);
	//   }
	// }
}
