#include <stdio.h>
#include <windows.h>
#include <time.h>

#define FPS 100
#define DELAY 1


void set_game_space(char *space, int key_press_p1[6], int key_press_p2[6], char game_mode[2]);
void set_menu_manage(char *space, int key_press[6], char game_mode[2]);
void set_menu_options();
void set_game_options();
void print_menu();


void basic_loop_settings();

void key_press(int key_press[6], int timer[3],int player, char space);
/////////////////

#define WIDTH 10
#define HEIGHT 20

#define SLOW 10
#define NORMAL 5
#define FAST 1


struct tetra
{
    int X;
    int Y;

    int Blocks[4][2]; 

    int Shape;
   
};

struct player
{
    int Map[HEIGHT][WIDTH];
    int Score;
    char Speed;
    int Next;
    int New_tetra_test;
    int Game_over_test;
    
    int Fall_delay_timer;
    int Cut_delay;

    int Index;
    struct tetra Tetra;
};

// void set_game_options();
void set_game_space(char *space, int key_press_p1[6], int key_press_p2[6], char game_mode[2]);
void move_tetra(struct player *some_player, int key_press[6]);
void create_tetra(struct tetra *new_tetra);
void print_game(struct player P1, struct player P2, int game_state);
void cut_line(struct player *some_player);


///////////////

#define LIST_LENGTH 100

// void move_tetra(struct player *some_player, int key_press[6]);
// void create_tetra(struct tetra *new_tetra);
void set_tetra_on_map(struct player *some_player, int print_sign);
int test_collision(struct player *some_player);
// void cut_line(struct player *some_player);
void mark_line(struct player *some_player);

///////////////////////


// void print_game(struct player P1, struct player P2, int game_state);
void convert_number_in_string(char string_number[3], int number);
void print_tetra(int part, int tetra);
