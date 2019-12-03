// Assignment 1 19T1 COMP1511 Coco
//
// The program is use to play a game which is called Coco
// Coco is played by four players sitting around a circular table
// and each player will receive 10 cards and no two cards have the same number
// there are ten prime card and one card called The Douglas 
// this game have 2 stages
// stage one:
//  each player will dicard three card from their hand and pass it to their left's player
//  also, each player will receive three card from their right
// stage two:
//  there are ten rounds in stage two, the player who seat at the postion 0 will play
//  the first card, and who won the round will play first in the next round
// 
// the purpose of this game is not win any round. 
// 
// Coco is an unusual card game invented by the great mathematician John von Neumann.
// https://en.wikipedia.org/wiki/John_von_Neumann
//
// the program have a strategy that create by MINGLANG XIE
//
// This program was written by MINGLANG XIE (z5228006)
// on 24/03/2019
//

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

// IF YOU NEED MORE #defines ADD THEM HERE
void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void card_in_hand(int n_card_in_hand, int card_hand[N_CARDS_INITIAL_HAND]);
void played_card(int n_card_played, int card_played[N_PLAYERS]);
void history_played(int n_card_in_hand, int his_played_card[N_CARDS]);
void discard_rec_card();
void first_card_round(int card, int n_factor_card[CARD_MIN]);
int n_factor_card_round(int card);
void legal_play_card(int n_card_in_hand, int card_hand[N_CARDS_INITIAL_HAND], int card_played[N_PLAYERS], int n_factor_card[CARD_MIN], int legal_play[CARD_MIN]);
// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {
    printf("mlangTse\n");
    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

}

void choose_discards() {
    // READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int card_hand[N_CARDS_INITIAL_HAND] = {0};
    card_in_hand(10, card_hand);
    int n_discard = 0;
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    while (n_discard < N_CARDS_DISCARDED){
        printf("%d ", card_hand[N_CARDS_INITIAL_HAND - 1 - n_discard]);
        n_discard++;
    }      
}

void choose_card_to_play() {
    // card that in hand
    int card_hand[N_CARDS_INITIAL_HAND] = {0};  
    // card played in a round        
    int card_played[N_PLAYERS] = {0};   
    // card played history                
    int his_played_card[N_CARDS] = {0};    
    // the possilbe factor of the card             
    int n_factor_card[CARD_MIN] = {0};    
    // card that legal to play              
    int legal_play[CARD_MIN] = {0};    
    // the largest card                 
    int largest_card = 0;                               
    int fac_card;
    int first_played_card, check_first_played_card;
    int count, check_card_count, non_prime_count, n_card_less_42;
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    int n_card_in_hand, n_card_played, position;
    scanf("%d %d %d", &n_card_in_hand, &n_card_played, &position);
    // READ THE CARDS OF YOUR HAND INTO AN ARRAY
    card_in_hand(n_card_in_hand, card_hand);
    // READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    played_card(n_card_played, card_played);
    // READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    history_played(n_card_in_hand, his_played_card);
    // DISCARDED CARD AND RECEIVED CARD IN DISCARD ROUND
    discard_rec_card();
    // PLAY A CARD
    // take the first card played in a round
    first_played_card = card_played[0];
    // and then check it is a prime card or non-prime card
    check_first_played_card = n_factor_card_round(first_played_card);
    count = 0;
    check_card_count = 0;
    non_prime_count = 0;
    n_card_less_42 = 0;
    // play first
    if (card_played[0] == 0){ 
        // check that is there have non-prime card on hand, or not                                       
        while (check_card_count < n_card_in_hand){ 
            // take the card from hand              
            // and check how many factor does it have
            fac_card = n_factor_card_round(card_hand[check_card_count]);
            // if the card have more than one factor
            if (fac_card > 2){
                // non_prime_count plus one 
                non_prime_count++;
            }
            check_card_count++;
        }
        // if there are some non-prime card in hand,
        // play the largest card in the card in hand which is non-prime
        while (count < n_card_in_hand){ 
            // take the card from hand
            // and check how many factor does it have
            fac_card = n_factor_card_round(card_hand[count]); 
            if (non_prime_count > 0){  
                // if the card is less than 42                                          
                if(card_hand[count] < 42){ 
                    n_card_less_42++;
                    // if the number of factor of that card is greater than 2, 
                    // which means it's non-prime 
                    if(fac_card > 2){                     
                        largest_card = card_hand[count];
                    }  
                // if there is only one card or there is no card less than 42
                // play the largest card in hand  
                } else if (n_card_less_42 == 0 || n_card_less_42 == 1){
                    largest_card = card_hand[count];
                }    
            // if there are all prime card in hand,
            } else if (non_prime_count == 0){
            // play the first one(smallest one)                                    
                largest_card = card_hand[0];                                    
            }                 
            count++;
        } 
        printf("%d", largest_card);
    // not play first 
    } else if (card_played[0] != 0){ 
        // find out all the factors of the first played card in a round                                               
        first_card_round(first_played_card, n_factor_card);
        // and check what card on hand is the cocomposite of the first palyed card 
        legal_play_card(n_card_in_hand, card_hand, card_played, n_factor_card, legal_play);
        // if there is no legal card to play
        // let the legal_play be the card on hand
        if (legal_play[0] == 0){
            for (int i = 0; i < n_card_in_hand; i++){
                legal_play[i] = card_hand[i];
            }
        }        
        // if the first card played in a round is non-prime 
        if (check_first_played_card > 2){
            while (count < n_card_in_hand){ 
                // play the largest number in the legal_play array
                if (legal_play[count] < 42 && legal_play[count] != 0){          
                    largest_card = legal_play[count];
                } else if (legal_play[count] >= 42 && legal_play[count] != 0){
                    largest_card = legal_play[count];
                }
                count++;
            }
        // if the first card played in a round is prime
        } else if (check_first_played_card <= 2){ 
            // play the first one (smallest one) in the legal_play array                              
            largest_card = legal_play[0];
        }    
        printf("%d\n", largest_card);
    }
}

//FUNCTIONS
// READ THE CARDS OF YOUR HAND INTO AN ARRAY
void card_in_hand(int n_card_in_hand, int card_hand[N_CARDS_INITIAL_HAND]){
    int n_card = 0;
    while (n_card < n_card_in_hand){
        scanf("%d", &card_hand[n_card]);
        n_card++;
    }    
}

// READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
void played_card(int n_card_played, int card_played[N_PLAYERS]){
    int count = 0;
    while (count < n_card_played){
        scanf("%d", &card_played[count]);
        count++;
    }
}      

// READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
void history_played(int n_card_in_hand, int his_played_card[N_CARDS]){
    int his_count = 0;
    while (his_count < N_CARDS){
        scanf("%d", &his_played_card[his_count]);
        his_count++;
    }  
}      

// READ THE DISCARDED CARD AND RECEIVED CARD IN DISCARD ROUND INTO AN ARRAY
void discard_rec_card(){                                                        
    int dis_card[N_CARDS_DISCARDED] = {0};
    int rec_card[N_CARDS_DISCARDED] = {0};
    int n_discard = 0;
    int rec_count = 0;
    while (n_discard < N_CARDS_DISCARDED - 1){
        scanf("%d", &dis_card[n_discard]);
        n_discard++;
    }  
    while (rec_count < N_CARDS_DISCARDED - 1){
        scanf("%d", &rec_card[rec_count]);
        rec_count++;
    }
}   
// find out all the factor of the first card in a round
void first_card_round(int card, int n_factor_card[CARD_MIN]){ 
    // find out how many factors does this card have
    int factor_first_card = n_factor_card_round(card);              
    int n_factor = 0;
    int count = 2;
    // if the first card played in this round is not prime
    if (factor_first_card > 2){                                                 
        while (count < card){  
            if (card % count == 0){ 
                // read the factor of the first card in the round into a array                        
                n_factor_card[n_factor] = count;    
                n_factor++;                          
            }
            count++;
        }
    // if the first card played in this round is prime, the only factor is itself
    } else if (factor_first_card <= 2){                                         
        n_factor_card[0] = card;                                  
    }    
}

// find out how many factors does the card have
int n_factor_card_round(int card){                                              
    int n_factor = 0;
    int count = 1;
    while (count <= card){
        if (card % count == 0){
            n_factor++;
        }
        count++;
    }
    return n_factor;      
}

// find out all the legal card to play in each round 
void legal_play_card(int n_card_in_hand, int card_hand[N_CARDS_INITIAL_HAND], int card_played[N_PLAYERS], int n_factor_card[CARD_MIN], int legal_play[CARD_MIN]){
    int hand_card, factor_hand_card;
    int card = 0;
    int fac_card = 0;
    int count = 0;
    int n_legal_card = 0;
    int fac_count = 0;
    // not play first and the first card is no prime
    if (n_factor_card[0] != card_played[0]){                                    
        while (count < n_card_in_hand){
            fac_count = 0;
            while (fac_count < N_CARDS_INITIAL_HAND){
                factor_hand_card = n_factor_card_round(card_hand[count]);
                // if the card in hand is the cocomposite of the first played card
                // then read it in a array (legal_play) 
                if (n_factor_card[fac_count] != 0){
                    if (card_hand[count] % n_factor_card[fac_count] == 0 && factor_hand_card > 2){
                        fac_count = card_hand[count];
                        legal_play[n_legal_card] = fac_count;
                        n_legal_card++;
                    }
                } 
                fac_count = fac_count + 1;
            }
            count++;
        } 
    // not play first and the first card is prime
    } else if (n_factor_card[0] == card_played[0]){                             
        while (count < n_card_in_hand){
            fac_card = n_factor_card_round(card_hand[count]);
            if (fac_card <= 2){
                legal_play[n_legal_card] = card_hand[count];
                n_legal_card++;
            }
            count = count + 1;    
        }                        
    }     
}  
