#include "add.h"
int Drop_Manage[2];
int Drop_Tetra_List[LIST_LENGTH];

void set_tetra_on_map(struct player *some_player, int print_sign){
    int x,y;
    for (int i = 0; i < 4; i++)
    {
        x = (*some_player).Tetra.Blocks[i][0];
        y = (*some_player).Tetra.Blocks[i][1];
        (*some_player).Map[y][x] = print_sign;
    }  
}
int test_collision(struct player *some_player){
    int x,y,test = 0;

    for (int i = 0; i < 4; i++)
    {
        x = (*some_player).Tetra.Blocks[i][0];
        y = (*some_player).Tetra.Blocks[i][1];

        if ((*some_player).Map[y][x] != 0)
        {
            test = 1;
        }
        if (y >= HEIGHT)
        {
            test = 1;
        }
        if (x >= WIDTH)
        {
            test = 1;
        }
        if (x < 0)
        {
            test = 1;
        }
    }
    return test;
}
void change_tetra_shape(struct tetra *new_tetra)
{
    if (0 < (*new_tetra).Shape && (*new_tetra).Shape < 4)
    {
        (*new_tetra).Shape += 1;
    }else if ((*new_tetra).Shape == 4)
    {
        (*new_tetra).Shape = 1;
    }

    if ((*new_tetra).Shape == 6)
    {
        (*new_tetra).Shape = 7;
    }else if ((*new_tetra).Shape == 7)
    {
        (*new_tetra).Shape = 6;
    }
    if ((*new_tetra).Shape == 8)
    {
        (*new_tetra).Shape = 9;
    }else if ((*new_tetra).Shape == 9)
    {
        (*new_tetra).Shape = 8;
    }
    if ((*new_tetra).Shape == 10)
    {
        (*new_tetra).Shape = 11;
    }else if ((*new_tetra).Shape == 11)
    {
        (*new_tetra).Shape = 10;
    }
    if (11 < (*new_tetra).Shape && (*new_tetra).Shape < 15)
    {
        (*new_tetra).Shape += 1;
    }else if ((*new_tetra).Shape == 15)
    {
        (*new_tetra).Shape = 12;
    }

    if (15 < (*new_tetra).Shape && (*new_tetra).Shape < 19)
    {
        (*new_tetra).Shape += 1;
    }else if ((*new_tetra).Shape == 19)
    {
        (*new_tetra).Shape = 16;
    }
}
void move_tetra(struct player *some_player, int key_press[6])
{   
    // printf("(%d,%d)",Drop_Manage[0], Drop_Manage[1]);
    // printf("[");
    // for (int i = 0; i < LIST_LENGTH; i++)
    // {
    //     printf("%d,",Drop_Tetra_List[i]);
    // }
    // printf("]\n");

    if ((*some_player).New_tetra_test && (*some_player).Cut_delay <= 0)
    {
        cut_line(some_player);
        (*some_player).Tetra.Y = 0;
        (*some_player).Tetra.X = 5;
        (*some_player).Tetra.Shape = (*some_player).Next;
        create_tetra(&(*some_player).Tetra);
        (*some_player).New_tetra_test = 0;

        int o, i = (*some_player).Index;
        if (i == 0)
        {
            o = 1;
        }
        else
        {
            o = 0;
        }
        if (Drop_Manage[i] >= Drop_Manage[o])
        {
            int tetra_list[7] = {1,5,6,8,10,12,16};
            srand(time(0));
            (*some_player).Next = tetra_list[(rand() % 7)];
            
            Drop_Tetra_List[Drop_Manage[i]] = (*some_player).Next; 

            if (Drop_Manage[i] < LIST_LENGTH - 1)
            {
                Drop_Manage[i]++;
            }
        }
        else
        {
            (*some_player).Next = Drop_Tetra_List[0];
            for (int x = 0; x < Drop_Manage[o]; x++)
            {
                Drop_Tetra_List[x] = Drop_Tetra_List[x + 1];
            }
            Drop_Manage[o]--;

        }

        if (test_collision(some_player))
        {
            (*some_player).Game_over_test = 1;
        }
    }
    else if ((*some_player).Cut_delay >= 0)
    {
        (*some_player).Cut_delay -= 1;
    }
    else
    {
        set_tetra_on_map(some_player,0);
        if (key_press[4] < 0)
        {
            int old_shape = (*some_player).Tetra.Shape;
            change_tetra_shape(&(*some_player).Tetra);
            create_tetra(&(*some_player).Tetra);

            if (test_collision(some_player))
            {
                (*some_player).Tetra.Shape = old_shape;
                create_tetra(&(*some_player).Tetra);
            }
        }
        if (key_press[2] < 0)
        {
            (*some_player).Tetra.X--;
            create_tetra(&(*some_player).Tetra);

            if (test_collision(some_player))
            {
                (*some_player).Tetra.X++;
                create_tetra(&(*some_player).Tetra);
            }
        }
        if (key_press[3] < 0)
        {
            (*some_player).Tetra.X++;
            create_tetra(&(*some_player).Tetra);
            if (test_collision(some_player))
            {
                (*some_player).Tetra.X--;
                create_tetra(&(*some_player).Tetra);
            }
        }
        
        int delay;
        switch ((*some_player).Speed)
        {
            case 'R':
                delay = NORMAL;
                break;
            case 'S':
                delay = SLOW;
                break;
            case 'N':
                delay = NORMAL;
                break;
            case 'F':
                delay = FAST;
                break;
            default:
                delay = 0;
                break;
        }

        if ((*some_player).Fall_delay_timer >= delay || key_press[1] < 0)
        { 
            (*some_player).Tetra.Y++;
            create_tetra(&(*some_player).Tetra);
            if (test_collision(some_player))
            {
                (*some_player).Tetra.Y--;
                create_tetra(&(*some_player).Tetra);
                
                (*some_player).New_tetra_test = 1;
            }
            if (key_press[1] >= 0)
            {
                (*some_player).Fall_delay_timer = 0;
            }
        }else
        {
            (*some_player).Fall_delay_timer++;
        }

        set_tetra_on_map(some_player,1);
        if ((*some_player).New_tetra_test == 1)
        {
            mark_line(some_player);
        }
    }
}
void mark_line(struct player *some_player)
{
    for (int h = 0; h < HEIGHT; h++)
    {
        int line_size = 0;
        for (int w = 0; w < WIDTH; w++)
        {

            if ((*some_player).Map[h][w] != 0)
            {
                line_size++;
            }

        }

        if (line_size == WIDTH)
        {   
            for (int w = 0; w < WIDTH; w++)
            {
                (*some_player).Map[h][w] = 2;
            }

            (*some_player).Cut_delay = 4;
        }
    }       
}
void cut_line(struct player *some_player)
{
    for (int h = 0; h < HEIGHT; h++)
    {
        if ((*some_player).Map[h][0] == 2)
        {
            if ((*some_player).Score < 999)
            {
                (*some_player).Score += 1;
            }

            int height_move = h;
            while (height_move> 0)
            {

                for (int w = 0; w < WIDTH; w++)
                {
                    (*some_player).Map[height_move][w] = (*some_player).Map[height_move - 1][w];
                }
                height_move--;
            }
        }
    }
}