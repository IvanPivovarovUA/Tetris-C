#include "add.h"


void print_game(struct player P1, struct player P2, int game_state)
{
    char score_string_1[4];
    char score_string_2[4];
    char difference[4];

    convert_number_in_string(score_string_1, P1.Score);
    convert_number_in_string(score_string_2, P2.Score);
    if (P1.Score - P2.Score > 0)
    {
        convert_number_in_string(difference, P1.Score - P2.Score);
    }
    else
    {
        convert_number_in_string(difference, P2.Score - P1.Score);
    }
    
    int winner = 0;
    if (P1.Game_over_test == 1 && P2.Game_over_test == 1)
    {
        if (P1.Score > P2.Score)
        {
            winner = 1;
        }
        if (P1.Score < P2.Score)
        {
            winner = 2;
        }
    }


    ////////////////////////////////////////////////
    printf(" ________________________________________________\n");
    printf(" |PLAYER 1 |   NEXT   |    |PLAYER 2 |   NEXT   |\n");

    printf(" |_________|");
    print_tetra(1, P1.Next);
    printf("| VS |_________|");
    print_tetra(1, P2.Next);
    printf("|\n");

    printf(" |LINES:%s|",score_string_1); 
    print_tetra(2,P1.Next);
    printf("|    |LINES:%s|",score_string_2);
    print_tetra(2,P2.Next);
    printf("|\n");

    printf(" |_________|__________|    |_________|__________|\n");
    if (P1.Score - P2.Score > 0)
    {
        printf(" |DIFFERENCE: +%s  %c |    |DIFFERENCE: -%s  %c |\n", difference, P1.Speed, difference, P2.Speed);
    }
    else
    {
        printf(" |DIFFERENCE: -%s  %c |    |DIFFERENCE: +%s  %c |\n", difference, P1.Speed, difference, P2.Speed);
    }
    
    printf(" |____________________|    |____________________|\n");
    for (int h = 0; h < HEIGHT; h++)
    {
        printf(" |");


        for (int w = 0; w < WIDTH; w++)
        {
            if ((P1.Game_over_test == 1 || game_state != 'g')  && 0 < w && w < 9 && 3 <= h && h <= 6){
                if (w == 2)
                {
                    switch (h)
                    {
                        case 3:
                            printf("________________");
                            break;
                        case 4:
                            printf("|              |");
                            break;
                        case 5:
                            if (winner == 1)
                            {
                                printf("|  * WINNER *  |");
                            }
                            else if (game_state == 'e')
                            {
                                printf("| < CONTINUE > |");
                            }
                            else if (game_state == 's')
                            {
                                printf("|    Start !   |");
                            }
                            else if (game_state == 'p')
                            {
                                printf("|    PAUSE ?   |");
                            }
                            else
                            {
                                printf("|  GAME  OVER  |");
                            }
                            break;
                        case 6:
                            printf("|______________|");
                            break;
                    }  
                }
            }
            else
            {
                if (P1.Map[h][w] == 1)
                {
                    printf("[]");
                }
                if (P1.Map[h][w] == 0)
                {
                    printf(" .");
                }
                if (P1.Map[h][w] == 2)
                {
                    printf("xx");
                }   
            }

        }
        
        printf("|    |");

        for (int w = 0; w < WIDTH; w++)
        {
            if ((P2.Game_over_test == 1 || game_state != 'g') && 0 < w && w < 9 && 3 <= h && h <= 6){
                if (w == 2)
                {
                    switch (h)
                    {
                        case 3:
                            printf("________________");
                            break;
                        case 4:
                            printf("|              |");
                            break;
                        case 5:
                            if (winner == 2)
                            {
                                printf("|  * WINNER *  |");
                            }
                            else if (game_state == 'e')
                            {
                                printf("| < CONTINUE > |");
                            }
                            else if (game_state == 's')
                            {
                                printf("|    Start !   |");
                            }
                            else if (game_state == 'p')
                            {
                                printf("|    PAUSE ?   |");
                            }
                            else
                            {
                                printf("|  GAME  OVER  |");
                            }
                            
                            break;
                        case 6:
                            printf("|______________|");
                            break;
                    }  
                }
            }
            else
            {
                if (P2.Map[h][w] == 1)
                {
                    printf("[]");
                }
                if (P2.Map[h][w] == 0)
                {
                    printf(" .");
                }
                if (P2.Map[h][w] == 2)
                {
                    printf("xx");
                } 
            }

        }       
        
        printf("|\n");
        
    }
    printf(" [====================]____[====================]\n");

}
void convert_number_in_string(char string_number[3], int number)
{
    //48
    if (number < 10)
    {
        string_number[0] = '0';
        string_number[1] = '0';
        string_number[2] = number + 48;
    }
    else if (number < 100)
    {
        string_number[0] = '0';
        string_number[1] = number/10 + 48;
        string_number[2] = number%10 + 48;
    }
    else
    {
        string_number[0] = number/100    + 48;
        string_number[1] = number%100/10 + 48;
        string_number[2] = number%10     + 48;
    }
    string_number[3] = '\0';
}
void print_tetra(int part, int tetra){
    if (part == 1){
        switch (tetra)
        {
            case 1:
                printf("  [][][]  ");
                // printf("    []    ");
                break;
            case 5:
                printf("   [][]   ");
                // printf("   [][]   ");
                break;
        
            case 6:
                printf(" [][][][] ");
                // printf("          ");
                break;
            case 8:
                printf("    [][]  ");
                // printf("  [][]    ");
                break;
            case 10:
                printf("  [][]    ");
                // printf("    [][]  ");
                break;
            case 12:
                printf("  [][][]  ");
                // printf("  []      ");
                break;
            case 16:
                printf("  [][][]  ");
                // printf("      []  ");
                break;
            default:
                break;
        }
    }
    else
    {
        switch (tetra)
        {
            case 1:
                // printf("  [][][]  ");
                printf("    []    "); 
                break;
            case 5:
                // printf("   [][]   ");
                printf("   [][]   ");
                break;
        
            case 6:
                // printf(" [][][][] ");
                printf("          ");
                break;
            case 8:
                // printf("    [][]  ");
                printf("  [][]    ");
                break;
            case 10:
                // printf("  [][]    ");
                printf("    [][]  ");
                break;
            case 12:
                // printf("  [][][]  ");
                printf("  []      ");
                break;
            case 16:
                // printf("  [][][]  ");
                printf("      []  ");
                break;
            default:
                break;
        }
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