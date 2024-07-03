#include "add.h"

char Game_State;
int Key_Up_Test;
struct player Player_1;
struct player Player_2;

void set_game_options()
{
    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            Player_1.Map[h][w] = 0;
            Player_2.Map[h][w] = 0;
        }
    }
    Player_1.Score = 0;
    Player_2.Score = 0;
    Player_1.Speed = 'N';
    Player_2.Speed = 'N';
    // srand(time(0)); 
    // Player_1.Next  = (rand() % 19 + 1);
    // Player_2.Next  = (rand() % 19 + 1);
    int tetra_list[7] = {1,5,6,8,10,12,16};
    srand(time(0));
    Player_1.Next  = tetra_list[(rand() % 7)];;
    Player_2.Next  = Player_1.Next;
    Player_1.Tetra.Shape = tetra_list[(rand() % 7)];;
    Player_1.Tetra.X = 5;
    Player_1.Tetra.Y = 0;
    Player_2.Tetra.Shape = Player_1.Tetra.Shape;
    Player_2.Tetra.X = 5;
    Player_2.Tetra.Y = 0;



    Player_1.Game_over_test = 0;
    Player_2.Game_over_test = 0;
    Player_1.New_tetra_test = 0;
    Player_2.New_tetra_test = 0;
    create_tetra(&Player_1.Tetra);
    create_tetra(&Player_2.Tetra);
    Player_1.Fall_delay_timer = 0;
    Player_2.Fall_delay_timer = 0;
    Player_1.Cut_delay = 0;
    Player_1.Cut_delay = 0;


    Game_State = 's';
    Key_Up_Test = 1;
    /// 0 -end
    /// 1 -start
    /// 2 -game
    /// 3 -pause

    Player_1.Index = 0;
    Player_2.Index = 1;

}

void set_game_space(char *space, int key_press_p1[6], int key_press_p2[6], char game_mode[2])
{
    if (game_mode[0] == '1')
    {
        Player_2.Game_over_test = 1;

    }
    if (game_mode[1] == 'R')
    {
        if (Player_1.Score < 30)
        {
            Player_1.Speed = 'S';
        }
        else if (Player_1.Score < 300)
        {
            Player_1.Speed = 'N';
        }
        else
        {
            Player_1.Speed = 'F';
        }

        if (Player_2.Score < 30)
        {
            Player_2.Speed = 'S';
        }
        else if (Player_2.Score < 300)
        {
            Player_2.Speed = 'N';
        }
        else
        {
            Player_2.Speed = 'F';
        }
    }
    else
    {
        Player_1.Speed = game_mode[1];
        Player_2.Speed = game_mode[1];
    }


    if (Player_1.Game_over_test == 1 && Player_2.Game_over_test == 1)
    {
        Game_State = 'e';
    }


    if (Game_State == 'g' || Game_State == 'p')
    {
        if (key_press_p1[5] == 0 || key_press_p2[5] == 0) 
        {
            Key_Up_Test = 0;
        }
        if ((key_press_p1[5] < 0 || key_press_p2[5] < 0) && Key_Up_Test == 0)
        {
            Key_Up_Test = 1;
            if (Game_State == 'g')
            {
                Game_State = 'p';
            }
            else if (Game_State == 'p')
            {
                Game_State = 'g';
            }
        }  
    }


    if (Game_State == 'g')
    {   
    
        if (Player_1.Game_over_test != 1)
        {
            move_tetra(&Player_1, key_press_p1);
        }
        if (Player_2.Game_over_test != 1)
        {
            move_tetra(&Player_2, key_press_p2);

        }
    }


    if (Game_State == 's')
    {
        if (key_press_p2[4] < 0 || key_press_p1[4] < 0) 
        {
            Game_State = 'g';
        }
    }


    if (Game_State == 'e')
    {
        if (key_press_p2[4] < 0 || key_press_p1[4] < 0)
        {
            *space = 'M';
            set_game_options();
        }
    }   


    print_game(Player_1,Player_2,Game_State);

}