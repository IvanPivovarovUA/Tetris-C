#include "add.h"

void create_tetra(struct tetra *new_tetra)
{
    int x = (*new_tetra).X;
    int y = (*new_tetra).Y;

    switch ((*new_tetra).Shape)
    {

        case 1://V
            /*
             
            [][][]
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 2:
            /*
              []
            [][]
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y + 1;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x - 1;
            (*new_tetra).Blocks[3][1] = y;
            break;
        case 3:
            /*
              [] 
            [][][]

            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y - 1;
            break;
        case 4:
            /*
              [] 
              [][]
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y;
            break;

        case 5://V
            /*
            [][]
            [][]
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x - 1;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        
        case 6://V
            /*
            

            [][][][]
              
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x - 2;
            (*new_tetra).Blocks[2][1] = y;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y;
            break;
        case 7:
            /*
                []
                []
                []
                []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y - 2;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 8://V
            /*
              [][]
            [][]
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x + 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x - 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 9:
            /*
            []            
            [][]
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x + 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 10://V
            /*

            [][]
              [][]
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 11:
            /*
                []
              [][]
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x + 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;

        case 12://V
            /*
            
            [][][]
            []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x - 1;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y;
            break;
        case 13:
            /*
            [][]
              []
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x - 1;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 14:
            /*
                []
            [][][]
              
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y - 1;
            break;
        case 15:
            /*
              []
              []
              [][]
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;

        case 16://V
            /*
            
            [][][]
                []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;
        case 17:
            /*
              []
              []
            [][]
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x;
            (*new_tetra).Blocks[2][1] = y + 1;

            (*new_tetra).Blocks[3][0] = x - 1;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;     

        case 18:
            /*
            []
            [][][]

            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x - 1;
            (*new_tetra).Blocks[1][1] = y;

            (*new_tetra).Blocks[2][0] = x - 1;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x + 1;
            (*new_tetra).Blocks[3][1] = y;
            break;   
        case 19:
            /*
              [][]
              []
              []
            */
            (*new_tetra).Blocks[0][0] = x;
            (*new_tetra).Blocks[0][1] = y;

            (*new_tetra).Blocks[1][0] = x;
            (*new_tetra).Blocks[1][1] = y - 1;

            (*new_tetra).Blocks[2][0] = x + 1;
            (*new_tetra).Blocks[2][1] = y - 1;

            (*new_tetra).Blocks[3][0] = x;
            (*new_tetra).Blocks[3][1] = y + 1;
            break;        
    }
}
/*
tetra
1
  [] 
[][][]

2 
[][][][]

3
[][]
[][]

4
  [][]
[][]

5
[][]
  [][]

6
[]
[][][]

7
    []
[][][]
*/