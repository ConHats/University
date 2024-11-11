#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define ROWS 12
#define COLUMNS 4

void upDateSeats(int row, int col, int tab[row][col]);
void findEmptyRows(int row,int col,int tab[row][col]);
void findFirstAvailableWindow(int row,int col,int tab[row][col]);


int main() {

  int seats[ROWS][COLUMNS] = {{1,0,   0, 1},
                              {1,0,   0, 1},
                              {0,1,   0, 0},
                              {0,0,   1, 1},
                              {1,1,   0, 0},
                              {1,1,   0, 1},
                              {0,0,   1, 1},
                              {1,0,   0, 0},
                              {0,0,   1, 0},
                              {0,0,   0, 0},
                              {0,0,   0, 0},
                              {1,1,   0, 1}};

  upDateSeats(ROWS,COLUMNS,seats);
  findEmptyRows(ROWS,COLUMNS,seats);
  findFirstAvailableWindow(ROWS,COLUMNS,seats);
  return 0;
}

/* Function for Testing. */
void upDateSeats(int rows, int cols, int tab[rows][cols]){
   int i,j;
   printf("Update Seats? (0/no):");
   if(!GetInteger()) return;
   for(i=0;i<rows;i++)
      for(j=0;j<cols;j++)
         tab[i][j] = (printf("seat (%2d,%2d)",i,j),GetInteger());
    printf("\n");
}

void findEmptyRows(int row,int col,int tab[row][col])
{
    int i, j;
    bool flag;
    for(i=0;i<row;i++)
    {
        flag=1;
        for(j=0;j<col;j++)
        {
          if (tab[i][j]==1)
          {
              flag=0;
          }
        }
        if(flag==1)
        {
            printf("Row: %d\n",i);
        }
    }
}
void findFirstAvailableWindow(int row,int col,int tab[row][col])
{
    int i;
    for(i=0;i<row;i++)
    {
        if(tab[i][0]==0)
        {
            printf("First available window seat: %d,0",i);
            break;
        }
    }

}
