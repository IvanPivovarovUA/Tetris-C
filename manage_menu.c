#include <stdio.h>

int Button;
int Key_Up_Test;
void set_menu_options(){
    Button = 1;
    Key_Up_Test = 1;
}

void set_menu_manage(char *space, int key_press[6], char game_mode[2])
{
    if (key_press[0] >= 0 || key_press[1] >= 0){
        if (key_press[0] < 0)
        {
            if (Button < 4)
            {
                Button -= 1;
                if (Button < 1)
                {
                    Button = 3;
                }
            }

            if (3 < Button && Button < 9)
            {
                Button -= 1;
                if (Button < 4)
                {
                    Button = 8;
                }
            }
        }

        if (key_press[1] < 0){
            if (Button < 4)
            {
                Button += 1;
                if (Button > 3){
                    Button = 1;
                }
            }

            if (3 < Button && Button < 9)
            {
                Button += 1;
                if (Button > 8)
                {
                    Button = 4;
                }
            }
        }
    }

    if (key_press[4] == 0)
    {
        Key_Up_Test = 0;
    }
    if (key_press[4] < 0 && Key_Up_Test == 0)
    {
        Key_Up_Test = 1;
        switch (Button)
        {
            case 1:
                Button = 4;
                game_mode[0] = '1';
                break;
            case 2:
                Button = 4;
                game_mode[0] = '2';
                break;
            case 3:
                *space = 'E';
                break;
            case 4:
                game_mode[1] = 'R';
                *space = 'G';
                set_menu_options();
                break;
            case 5:
                game_mode[1] = 'S';
                *space = 'G';
                set_menu_options();
                break;
            case 6:
                game_mode[1] = 'N';
                *space = 'G';
                set_menu_options();
                break;
            case 7:
                game_mode[1] = 'F';
                *space = 'G';
                set_menu_options();
                break;      
            case 8:
                Button = 1;
                break;

        }
    }

}

void print_menu()
{
    printf(" ________________________________________________\n");
    printf(" |                                              |\n");
    printf(" | [][][]  [][][]  [][][]  [][]    []    [][]   |\n");
    printf(" |   []    []        []    []  []      []       |\n");
    printf(" |   []    [][][]    []    [][]    []    []     |\n");
    printf(" |   []    []        []    []  []  []      []   |\n");
    printf(" |   []    [][][]    []    []  []  []  [][]     |\n");
    printf(" |                                              |\n");
    printf(" |                                              |\n");


    switch (Button)
    {
        case 1:
            printf(" |                                              |\n");
            printf(" |               < 1 PLAYER >                   |\n");
            printf(" |                 2 PLAYER                     |\n");
            printf(" |                   EXIT                       |\n");
            printf(" |                                              |\n");
            break;
        case 2:
            printf(" |                                              |\n");
            printf(" |                 1 PLAYER                     |\n");
            printf(" |               < 2 PLAYER >                   |\n");
            printf(" |                   EXIT                       |\n");
            printf(" |                                              |\n");
            break;
        case 3:
            printf(" |                                              |\n");
            printf(" |                 1 PLAYER                     |\n");
            printf(" |                 2 PLAYER                     |\n");
            printf(" |                 < EXIT >                     |\n");
            printf(" |                                              |\n");
            break;
        case 4:
            printf(" |                < RATING >                    |\n");
            printf(" |                   SLOW                       |\n");
            printf(" |                  NORMAL                      |\n");
            printf(" |                   FAST                       |\n");
            printf(" |                 COMEBACK                     |\n");
            break;
        case 5:
            printf(" |                  RATING                      |\n");
            printf(" |                 < SLOW >                     |\n");
            printf(" |                  NORMAL                      |\n");
            printf(" |                   FAST                       |\n");
            printf(" |                 COMEBACK                     |\n");
            break;
        case 6:
            printf(" |                  RATING                      |\n");
            printf(" |                   SLOW                       |\n");
            printf(" |                < NORMAL >                    |\n");
            printf(" |                   FAST                       |\n");
            printf(" |                 COMEBACK                     |\n");
            break;
        case 7:
            printf(" |                  RATING                      |\n");
            printf(" |                   SLOW                       |\n");
            printf(" |                  NORMAL                      |\n");
            printf(" |                 < FAST >                     |\n");
            printf(" |                 COMEBACK                     |\n");
            break;
        case 8:
            printf(" |                  RATING                      |\n");
            printf(" |                   SLOW                       |\n");
            printf(" |                  NORMAL                      |\n");
            printf(" |                   FAST                       |\n");
            printf(" |               < COMEBACK >                   |\n");
            break;
    }

    
    printf(" |                                              |\n");
    printf(" |                                              |\n");
    printf(" |______________________________________________|\n");
    printf(" |                     |                        |\n");
    printf(" | OPTIONS:            |                        |\n");
    printf(" |             P1  P2  |      created by        |\n");
    printf(" | move up     w   i   |                        |\n");
    printf(" | move down   s   k   |    IVAN PIVOVAROV      |\n");
    printf(" | move left   a   j   |                        |\n");
    printf(" | move right  d   l   |      from KM-23        |\n");
    printf(" |                     |       FAM KPI          |\n");
    printf(" | action      r   p   |                        |\n");
    printf(" | pause       ENTER   |                        |\n");
    printf(" |_____________________|________________________|\n");
}