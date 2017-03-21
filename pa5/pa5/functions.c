#include "functions.h"

void print_game_menu(void)
{
	printf("Enter 1 for rules, 2 to play, or 0 to quit!");
}

void print_game_rules(void)
{
	printf("The Rules of Yahtzee: The scorecard used for Yahtzee is composed of two sections,\n");
	printf("an upper section and a lower section.A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3s, then the score placed in the 3s box is the sum of the dice which is 12. \n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n");
	printf("The lower section contains a number of poker like combinations.\n");
	printf("Combos: \n");
	printf("Three of a kind: Score = sum of all face values on the 5 dice\n");
	printf("Four of a kind: Score = sum of all face values on the 5 dice\n");
	printf("Full House: One pair and one three of a kind || Score = 25 points\n");
	printf("Small Straight: Sequence of four consecutive dice || Score = 30 points\n");
	printf("Large Straight: Sequence of five consecutive dice || Score = 40 points\n");
	printf("YAHTZEE: All five dice are the same || Score = 50 points\n");
	printf("Chance: Sum of all face values on the 5 dice || Score = 40 points\n\n");

	printf("How to play: Players take turns rolling all five dice, and choosing whether they'd \n like to either reroll their dice, or score that roll to the score card. \n Each turn, you may roll the dice 3 times, then are requred to choose a scoring option for that roll. \n When all score slots have been filled, the scores are tallied and the winner is determined.");
}

int get_menu_selection(void)
{
	int menu_selection = 0;
	scanf("%d", &menu_selection);
	return menu_selection;
}

int roll_dice(int dice_rolls[], int size)
{
	for (int i = 1; i < size; i++) {
		dice_rolls[i]= rand() % 6 + 1;
	}
	
	return dice_rolls;
}

void print_dice(int * dice_ptr, int size)
{
	for (int i = 1; i < size; i++) {
		printf("die %d: %d \n", i, *(dice_ptr + i));
	}
	printf("\n");
}

void call_roll_functions_p1(int dice_rolls_p1[], int size, int roll_value_count_p1[], int size_count)
{
	printf("\nPlayer 1: \n\n");
	roll_dice(dice_rolls_p1, 6);
	count_dice(dice_rolls_p1, 6, roll_value_count_p1, 14);
	print_dice(dice_rolls_p1, 6);
}

void call_roll_functions_p2(int dice_rolls_p2[], int size, int roll_value_count_p2[], int size_count)
{
	printf("\nPlayer 2: \n\n");
	roll_dice(dice_rolls_p2, 6);
	count_dice(dice_rolls_p2, 6, roll_value_count_p2, 14);
	print_dice(dice_rolls_p2, 6);
}

void score_slot_and_assign_points(int roll_value_count[], int size_count, int option, Boolean *score_valid, int score_card[])
{
	int points = 0;
	
	switch (option)
	{
	case 1: //Sum 1's
	case 2: //Sum 2's
	case 3: //Sum 3's
	case 4: //Sum 4's
	case 5: //Sum 5's
	case 6: //Sum 6's
		if (score_card[option] == -1) 
		{
			*score_valid = 1;
			score_card[option] = sum_value(roll_value_count[option], option);
		}
		else 
		{
			*score_valid = 0;
		}
		break;

	//3 of a kind, score is sum of all face values
	case 7:	
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_3_of_a_kind = FALSE;
			for (int i = 1; i < size_count; i++) {
				if (roll_value_count[i] == 3) {
					is_3_of_a_kind = TRUE;
				}
			}
			if (is_3_of_a_kind) {
				score_card[option] = sum_all_values(roll_value_count, size_count);
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//4 of a kind, sum all face values on dice
	case 8:
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_4_of_a_kind = FALSE;
			for (int i = 1; i < size_count; i++) {
				if (roll_value_count[i] == 4) {
					is_4_of_a_kind = TRUE;
				}
			}
			if (is_4_of_a_kind) {
				score_card[option] = sum_all_values(roll_value_count, size_count);
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//full house, 25 points
	case 9: 
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_full_house_pt_1 = FALSE, is_full_house_pt_2 = FALSE;
			for (int i = 1; i < size_count; i++) {
				if (roll_value_count[i] == 3) {
					is_full_house_pt_1 = TRUE;
				}
				else if (roll_value_count[i] == 2) {
					is_full_house_pt_2 = TRUE;
				}
			}
			if (is_full_house_pt_1 && is_full_house_pt_2) {
				score_card[option] = 25;
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//Run of 4, 30 points
	case 10:
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_run_of_4 = FALSE;
			for (int i = 1; i < (size_count - 4); i++) {
				if ((roll_value_count[i] == 1) && (roll_value_count[i+1] == 1) && (roll_value_count[i+2] == 1) && (roll_value_count[i+3] == 1)) {
					is_run_of_4 = TRUE;
				}
			}
			if (is_run_of_4) {
				score_card[option] = 30;
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//Run of 5, 40 points
	case 11:
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_run_of_5 = FALSE;
			for (int i = 1; i < (size_count - 5); i++) {
				if ((roll_value_count[i] == 1) && (roll_value_count[i + 1] == 1) && (roll_value_count[i + 2] == 1) && (roll_value_count[i + 3] == 1) && (roll_value_count[i + 4] == 1)) {
					is_run_of_5 = TRUE;
				}
			}
			if (is_run_of_5) {
				score_card[option] = 40;
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//YAHTZEE, 50 points
	case 12:
		if (score_card[option] == -1) {
			*score_valid = 1;
			Boolean is_5_of_a_kind = FALSE;
			for (int i = 1; i < size_count; i++) {
				if (roll_value_count[i] == 5) {
					is_5_of_a_kind = TRUE;
				}
			}
			if (is_5_of_a_kind) {
				score_card[option] = 50;
			}
			else {
				score_card[option] = 0;
			}
		}
		else
		{
			*score_valid = 0;
		}
		break;

	//Chance, sum of all face values
	case 13:
		if (score_card[option] == -1)
		{
			*score_valid = 1;
			score_card[option] =  sum_all_values(roll_value_count, size_count);
		}
		else
		{
			*score_valid = 0;
		}
		break;
	}
	printf("  %d points in score slot %d!", score_card[option], option);
}

int sum_value(int value, int n)
{
	int sum = 0;
	sum = value * n;
	return sum;
}

int sum_all_values(int roll_value_count[], int size)
{
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += roll_value_count[i] * i;
	}

	return 0;
}

int chance(int dice_rolls[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += dice_rolls[i + 1];
	}
	return sum;
}

void print_score(int scoreboard[], int size, int player)
{
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += scoreboard[i];
	}
	
	printf("Player %d score: %d \n\n", player, sum);
}


void print_dice_counts(int * dice_ptr, int size)
{
	for (int i = 1; i < size; i++) {
		printf("Number of %d's: %d \n", i, *(dice_ptr + i));
	}

}

void count_dice(int dice_rolls[], int size, int roll_value_count[], int size_count)
{
	int new_index = 0;
	for (int i = 1; i < size; i++) {
		new_index = dice_rolls[i];
		roll_value_count[new_index]++;
	}
}

void re_roll(int dice_rolls[], int num_rerolls)
{
	int die_num = 0;
	for (int count = 0; count < num_rerolls; count++) {
		printf("Which die do you want to reroll? ");
		scanf("%d", &die_num);
		dice_rolls[die_num] = rand() % 6 + 1;
	}
}
