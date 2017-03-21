#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef enum boolean {
	FALSE, TRUE
}Boolean;

void print_game_menu(void);
void print_game_rules(void);

int get_menu_selection(void);

//Functions to roll, print, and count dice
int roll_dice(int dice_rolls[], int size);
void print_dice(int *dice_ptr, int size);
void count_dice(int dice_rolls[], int size, int roll_value_count[], int size_count);

//Re roll selected dice
void re_roll(int dice_rolls[], int num_rerolls);

//function to call roll_dice, print_dice, and count_dice for each player
void call_roll_functions_p1(int dice_rolls[], int size, int roll_value_count[], int size_count);
void call_roll_functions_p2(int dice_rolls[], int size, int roll_value_count[], int size_count);

//Scoring functions
void score_slot_and_assign_points(int roll_value_count[], int size_count, int option, Boolean *score_valid, int score_card[]);
int sum_value(int value, int n);
int sum_all_values(int roll_value_count[], int size);
int chance(int dice_rolls[], int size);
void print_score(int scoreboard[], int size, int player);



void print_dice_counts(int *dice_ptr, int size);
