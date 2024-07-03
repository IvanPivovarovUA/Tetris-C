#include "add.h"


int main()
{
    int Exit_Test = 0;
    char Space = 'M';
    int Old_Space = 'T';
    
    char Game_Mode[2];
    Game_Mode[0] = '1';
    Game_Mode[1] = 'R';

    int Key_Press_P1[6];
    int Key_Press_P2[6];

    int DT_Buttons_P1[3] = {0,0,0};//Delay Timer Buttons_P1[3];
    int DT_Buttons_P2[3] = {0,0,0};//Delay Timer Buttons_P2[3];
    int DT_Transition = 0; ///Delay Timer Transition;



    set_menu_options();
    set_game_options();

    while (!Exit_Test)
    {
        ////////////////////////
        double time_spent = 0.0;
        clock_t begin = clock();
        ///////////////////////////
        basic_loop_settings();

        key_press(Key_Press_P1, DT_Buttons_P1, 1, Space);
        key_press(Key_Press_P2, DT_Buttons_P2, 2, Space);


        if (DT_Transition > 0) 
        {
            for (int i = 0; i < 28; i++)
            {
                // printf(" ////////////////////////////////////////////////\n");
                printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            }
            DT_Transition--;
        }
        else
        {
            switch (Space)
            {
                case 'M':
                    // set_menu_manage(&Space,Key_Press_P2,Game_Mode);
                    set_menu_manage(&Space,Key_Press_P1,Game_Mode);
                    print_menu();
                    break;
                case 'G':
                    set_game_space(&Space,Key_Press_P1,Key_Press_P2,Game_Mode);
                    break;
                case 'E':
                    Exit_Test = 1;
                    break;
            }

            if (Old_Space != Space)
            {
                DT_Transition = DELAY*20;
                Old_Space = Space;
            } 
        }


        //////////////////////////
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds\n", time_spent);
        ///////////////////////////
    }
    return 0;
}


void basic_loop_settings(){
    //Some options from net
    //For smooth video grafix
    //Move console cursor in top
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    ///////////////

    //Some options from net
    //For fix cursos blink
    HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
    ///////////////////////


    //set FPS max limit
    Sleep(1000/FPS);
    ///////////////
}

void key_press(int key_press[6], int timer[3],int player,char space)
{
    key_press[0] = 0; // 0 - w / i 
    key_press[1] = 0; // 1 - s / k
    key_press[2] = 0; // 2 - a / j
    key_press[3] = 0; // 3 - d / l
    key_press[4] = 0; // 4 - r / p
    key_press[5] = 0; // 5 - Enter

    int delay[3];
    if (space == 'M')
    {
        delay[0] = DELAY * 8;
        delay[1] = DELAY * 8;
        delay[2] = DELAY * 0;
    }
    if (space == 'G')
    {
        delay[0] = DELAY * 0;
        delay[1] = DELAY * 1;
        delay[2] = DELAY * 3;
    }

    char Buttons[6];
    if (player == 1)
    {
        Buttons[0] = 'W';
        Buttons[1] = 'S';
        Buttons[2] = 'A';
        Buttons[3] = 'D';

        Buttons[4] = 'R';
        Buttons[5] = VK_RETURN;
    }
    if (player == 2)
    {
        Buttons[0] = 'I';
        Buttons[1] = 'K';
        Buttons[2] = 'J';
        Buttons[3] = 'L';

        Buttons[4] = 'P';
        Buttons[5] = VK_RETURN;
    }


    if (timer[0] <= 0)
    {
        if (GetKeyState(Buttons[0]) < 0)
        {
            key_press[0] = GetKeyState(Buttons[0]);
            timer[0] = delay[0];
        }
        if (GetKeyState(Buttons[1]) < 0)
        {
            key_press[1] = GetKeyState(Buttons[1]);
            timer[0] = delay[0];
        }
    }
    else
    {
        timer[0] -= 1;
    }

    if (timer[1] <= 0)
    {
        if (GetKeyState(Buttons[2]) < 0)
        {
            key_press[2] = GetKeyState(Buttons[2]);
            timer[1] = delay[1];
        }
        if (GetKeyState(Buttons[3]) < 0)
        {
            key_press[3] = GetKeyState(Buttons[3]);
            timer[1] = delay[1];
        }
    }
    else
    {
        timer[1] -= 1;
    }
    
    
    if (timer[2] <= 0)
    {
        if (GetKeyState(Buttons[4]) < 0)
        {
            key_press[4] = GetKeyState(Buttons[4]);
            timer[2] = delay[2];
        }
    }
    else
    {
        timer[2] -= 1;
    }

    if (GetKeyState(Buttons[5]) < 0)
    {
        key_press[5] = GetKeyState(Buttons[5]);
    }

}
