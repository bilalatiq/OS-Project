#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
int M = 10, N = 10, i, j, l, m, master, gencounter = 1;
int grid[10][10] = {
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
void* nextGeneration()
{
	// Loop through every cell
	for (int l = 1; l < 10 - 1; l++)
	{
		for (int m = 1; m < 10 - 1; m++)
		{
			// finding no Of Neighbours
			// that are alive
			int aliveNeighbours = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					aliveNeighbours += grid[l + i][m + j];
				}
			}

			// The cell needs to be subtracted
			// from its neighbours as it was
			// counted before
			aliveNeighbours -= grid[l][m];

			// Implementing the Rules of Life

			// Cell is lonely and dies
			if ((grid[l][m] == 1) && (aliveNeighbours < 2))
			{
				future[l][m] = 0;
			}

			// Cell dies due to over population
			else if ((grid[l][m] == 1) && (aliveNeighbours > 3))
			{
				future[l][m] = 0;
			}

			// A new cell is born
			else if ((grid[l][m] == 0) && (aliveNeighbours == 3))
			{
				future[l][m] = 1;
			}

			// Remains the same
			else
			{
				future[l][m] = grid[l][m];
			}
		}
	}
  pthread_exit(NULL);
}
int main(void)
{
  clock_t t;
  int o =0;
  int p =0;
  pthread_t ttid[2];
  double TimeAVG=0;
  double TimeSum=0;
  int GenTimeCount=0;
  FILE *fp = fopen("input.txt", "r");
  int get;
  double GenTimeArr[50];

  //Filling the array:
  for(int o=0; o < 10; o++)
  {
    for(int p=0; p < 10; p++)
    {
      fscanf(fp, " %d", &get);
      grid[o][p] = get;
    }
  }
  fclose(fp);




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
  t = clock();
	pthread_create(&ttid[0],NULL,&nextGeneration,NULL);
	pthread_join(ttid[0],NULL);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  GenTimeArr[GenTimeCount]=time_taken;
  // printf("took %f seconds to execute \n", time_taken); 
  printf("Generation %d :\n", gencounter);
	gencounter++;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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

	for (int master = 0; master < 24; master++)
	{
    GenTimeCount++;
    t=0;
    t = clock();
	  pthread_create(&ttid[0],NULL,&nextGeneration,NULL);
	  pthread_join(ttid[0],NULL);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    GenTimeArr[GenTimeCount]=time_taken;
    printf("Generation %d :\n", gencounter);
	  gencounter++;
	  for (int i = 0; i < 10; i++)
	  {
	  	for (int j = 0; j < 10; j++)
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
  for (int master = 0; master < 25; master++)
	{
    GenTimeCount++;
    t=0;
    t = clock();
	  pthread_create(&ttid[1],NULL,&nextGeneration,NULL);
	  pthread_join(ttid[1],NULL);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    GenTimeArr[GenTimeCount]=time_taken;
    printf("Generation %d :\n", gencounter);
	  gencounter++;
	  for (int i = 0; i < 10; i++)
	  {
	  	for (int j = 0; j < 10; j++)
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
  for(i=0,j=1;i<50;i++,j++)
  {
    TimeSum=TimeSum+GenTimeArr[i];
  }
  TimeAVG=TimeSum/50;

  FILE *wp = fopen("output.txt", "w");
  for(int o=0; o < 10; o++)
  {
    for(int p=0; p < 10; p++)
    {
      if(p<=8)
      {
        fprintf(wp, "%d,", grid[o][p]);
      }
      else
      {
        fprintf(wp, "%d", grid[o][p]);
      }

    }
    if(o<=8)
    {
      fprintf(wp,"\n");
    }

  }
  fprintf(wp,"\nAverage Time Taken For Each Generation is : %f",TimeAVG);
  fprintf(wp,"\nTotal Time Taken For 50 Generations is : %f",TimeSum);
  fclose(wp);

}
