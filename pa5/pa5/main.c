#include "functions.h"

int main(void) {

	srand(time(NULL));

	int is_playing = -1, option = 0;
	Boolean score_valid;

	int dice_rolls_p1[6] = {0,0,0,0,0,0};
	int dice_roll_value_count_p1[7] = {0,0,0,0,0,0,0};
	int scorecard_p1[14] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	int dice_rolls_p2[6] = {0,0,0,0,0,0};
	int dice_roll_value_count_p2[7] = {0,0,0,0,0,0,0};
	int scorecard_p2[14] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	print_game_menu();
	
	while (is_playing) {

		is_playing = get_menu_selection();

		if (is_playing == 0) {
			printf("Thanks for stopping by!\n\n");
			return 0;
		}
		else if (is_playing == 1) {
			print_game_rules();
		}
		/*If is_playing == 2, then go into gameplay. 
		This means rolling dice, see if they want to roll again, or choose that set as their scored roll
		for a specific score. 
		*/
		else if (is_playing == 2) {


			for (int i = 1; i < 13; i++) {

				int p1_current_rolls = 0, p2_current_rolls = 0;
				char p1_keep_or_reroll = '\0', p2_keep_or_reroll = '\0';

				//Player 1 rolls dice	
				call_roll_functions_p1(dice_rolls_p1, 6, dice_roll_value_count_p1, 7);
				p1_current_rolls++;
				//while loop to check if (p1_current_rerolls <=2) AND ((player 1 wants to reroll) OR (its their first roll)
				while (p1_current_rolls <= 2 && ((p1_keep_or_reroll == 'R') || (p1_keep_or_reroll == 'r') || (p1_keep_or_reroll == '\0'))) {

					//Player 1 determines if they want to keep or re roll
					printf("Enter R to re roll, or K to keep the current roll ");
					scanf(" %c", &p1_keep_or_reroll);

					//Keep Roll
					if (p1_keep_or_reroll == 'k' || p1_keep_or_reroll == 'K') {
						score_valid = 0;
						while (!score_valid) {
							option = 0;
							printf("Which score slot would you like to assign this roll to? ");
							scanf("%d", &option);
							score_slot_and_assign_points(dice_roll_value_count_p1, 7, option, &score_valid, scorecard_p1);
						}
					}

					//Re Roll
					else if ((p1_keep_or_reroll == 'r') || (p1_keep_or_reroll == 'R')) {
						int num_rerolls = 0;
						printf("How many dice would you like to reroll?  ");
						scanf("%d", &num_rerolls);
						re_roll(dice_rolls_p1, num_rerolls);
						print_dice(dice_rolls_p1, 6);
						count_dice(dice_rolls_p1, 6, dice_roll_value_count_p1, 7);
						printf("Enter R to re roll, or K to keep the current roll");
						scanf(" %c", &p1_keep_or_reroll);
						if (p1_current_rolls >=3) {
							printf("Which score slot would you like to assign this roll to? ");
							scanf("%d", &option);
							score_slot_and_assign_points(dice_roll_value_count_p1, 7, option, &score_valid, scorecard_p1);
						}
					p1_current_rolls++;
					}
					
				}


	//Player 2's turn


				//Player 2 rolls dice	
				call_roll_functions_p2(dice_rolls_p2, 6, dice_roll_value_count_p2, 7);
				p2_current_rolls++;
				//while loop to check if (p2_current_rerolls <=2) AND ((player 2 wants to reroll) OR (its their first roll)
				while (p2_current_rolls <= 2 && ((p2_keep_or_reroll == 'R') || (p2_keep_or_reroll == 'r') || (p2_keep_or_reroll == '\0'))) {

					//Player 2 determines if they want to keep or re roll
					printf("Enter R to re roll, or K to keep the current roll ");
					scanf(" %c", &p2_keep_or_reroll);

					//Keep Roll
					if (p2_keep_or_reroll == 'k' || p2_keep_or_reroll == 'K') {
						score_valid = 0;
						while (!score_valid) {
							option = 0;
							printf("Which score slot would you like to assign this roll to? ");
							scanf("%d", &option);
							score_slot_and_assign_points(dice_roll_value_count_p2, 7, option, &score_valid, scorecard_p2);
						}
					}

					//Re Roll
					else if ((p2_keep_or_reroll == 'r') || (p2_keep_or_reroll == 'R')) {
						int num_rerolls = 0;
						printf("How many dice would you like to reroll? ");
						scanf("%d", &num_rerolls);
						re_roll(dice_rolls_p2, num_rerolls);
						print_dice(dice_rolls_p2, 6);
						count_dice(dice_rolls_p2, 6, dice_roll_value_count_p2, 7);
						printf("Enter R to re roll, or K to keep the current roll ");
						scanf(" %c", &p2_keep_or_reroll);
						if (p2_current_rolls >=3) {
							printf("Which score slot would you like to assign this roll to? ");
							scanf(" %d", &option);
							score_slot_and_assign_points(dice_roll_value_count_p2, 7, option, &score_valid, scorecard_p2);
						}
					p2_current_rolls++;
					}	
				}
			//End game
			}
			print_score(scorecard_p1, 13, 1);
			print_score(scorecard_p2, 13, 2);
		}
	}
}