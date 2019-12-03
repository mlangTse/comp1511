// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by MINGLANG XIE (z5228006)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
    struct pokenode *back;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    Pokemon         pokemon;
    int found;
    int current;
    int pokemon_ID;
    int evolve;
};

// Add any other structs you define here.
// Add prototypes for any extra functions you create here.
static void print_evolve(struct pokenode *curr);
static void print_pokemon_detail(struct pokenode *curr);
static Pokedex sort_pokemon(Pokedex pokedex, Pokedex sort);
static int check_upper_lower_case(char *pokemon_name, char *text);
static Pokedex set_all_found(Pokedex pokedex);

// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    new_pokedex->back = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    // Create & initalise pokenode
    struct pokenode *add = malloc(sizeof (struct pokenode));
    struct pokenode *curr = pokedex->head;
    assert(add != NULL);
    add->next = NULL;
    add->pokemon = pokemon;
    add->found = 0;
    add->pokemon_ID = pokemon_id(pokemon);
    add->evolve = DOES_NOT_EVOLVE;
    // add it in the list
    if (pokedex->head == NULL) {
        pokedex->head = add;
        pokedex->head->current = 1;
        pokedex->back = add;
    } else {
        while (curr != NULL) {
            if (curr->pokemon_ID == pokemon_id(add->pokemon)) {
                printf("There's already a Pokemon with pokemon_id %d!\n", 
                        pokemon_id(add->pokemon));
                exit(1);
            }
            curr = curr->next;
        }
        pokedex->back->next = add;
        pokedex->back = add;
        pokedex->back->current = 0;
    }
}

void detail_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->current == 1) {
            print_pokemon_detail(curr);
        }
        curr = curr->next;
    }
    // move the list to the front
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    Pokemon current = NULL;
    if (curr != NULL) {
        while (curr != NULL) {
            if (curr->current == 1) {
                break;
            }
            curr = curr->next;
        }
        current = curr->pokemon;
    } else if (curr == NULL) {
        printf("The Pokedex is empty!\n");
        exit(1);
    }
    return current;
}

void find_current_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->current == 1) {   
            curr->found = 1;
        }
        curr = curr->next;
    }
}

void print_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    char *ptr, *name;
    while (curr != NULL) {
        ptr = pokemon_name(curr->pokemon);
        // if it's currently selected Pokemon
        if (curr->current == 1) {  
            printf("--> ");
            printf("#%03d: ", pokemon_id(curr->pokemon));
        } else {
            printf("    #%03d: ", pokemon_id(curr->pokemon));
        }
        // if the Pokemon have been found
        if (curr->found == 1) {
            printf("%s\n", pokemon_name(curr->pokemon)); 
        } else if (curr->found == 0) {
            for (name = ptr; *name != '\0'; name++) {
                printf("*");
            }    
            printf("\n");        
        }
        curr = curr->next;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    // change the next pokemon to be the current pokemon
    while (curr != NULL) {
        if (curr->current == 1 && curr->next != NULL) {   
            curr->current = 0;
            curr->next->current = 1;
            break;
        }
        curr = curr->next;
    }
}

void prev_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *pre = NULL;
    // change the previous pokemon to be the current pokemon
    while (curr != NULL) {
        // if the current Pokemon is not the first Pokemon in the pokedex
        // the previous Pokemon of the current Pokemon become current Pokemon
        if (curr->current == 1 && curr != pokedex->head) {   
            curr->current = 0;
            pre->current = 1;
            break;
        }
        // store the previous one in previous->head
        pre = curr;
        curr = curr->next;
    }
}

void change_current_pokemon(Pokedex pokedex, int pokemon_id) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *change = pokedex->head;
    // find out which Pokemon ID is the same as provided
    while (change != NULL) {
        if (change->pokemon_ID == pokemon_id) {
            break;
        }
        change = change->next;
    }
    // change that one to be the current pokemon
    while (curr != NULL) {
        if (curr->current == 1) {   
            curr->current = 0;
            change->current = 1;
            break;
        }
        curr = curr->next;
    }
}

void remove_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *pre = NULL;
    struct pokenode *destroy = NULL;
    
    while (curr != NULL) {
        if (curr->current == 1) { 
            break;
        }
        // store the previous one in previous->head
        pre = curr;
        curr = curr->next;
    }
    // if the next pokemon of the current pokemon one is null
    // which means the current Pokemon is the last one in the Pokedex
    // then let the previous Pokemon become current Pokemon
    if (curr->next == NULL) {
        destroy = curr;
        // if there is not only one Pokemon in Pokedex
        if (pre != NULL) {
            pre->next = NULL;
            pre->current = 1;
        // if there is only one Pokemon in Poekdex
        }  else {
            pokedex->head = NULL;
        }
        destroy_pokemon(destroy->pokemon);
        free(destroy);
    // if the previous pokemon of the current pokemon is null
    // which means the current Pokemon is the first one in the Pokedex
    // then let the next Pokemon become the current pokemon
    } else if (pre == NULL) {  
        destroy = curr;
        pre = curr->next;
        curr = pre;
        if (curr != NULL) {
            curr->current = 1;
        }
        pokedex->head = curr;
        destroy_pokemon(destroy->pokemon);
        free(destroy);
    // let the next Pokemon of the current Pokemon become the current pokemon
    } else {
        destroy = curr;
        pre->next = curr->next;
        curr = pre->next;
        curr->current = 1;
        destroy_pokemon(destroy->pokemon);
        free(destroy);
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    struct pokenode *curr = pokedex->head;
    int n_found = 0;
    int rand_id;
    int in_range = 0;
    
    // check are there some Pokemon with id in the ranger
    while (curr != NULL) {
        if (curr->pokemon_ID <= factor - 1) {
            in_range = 1;
        }
        curr = curr->next;
    }
    
    if (in_range == 0) {
        printf("There aren't any Pokemon to find with pokemon_id between 0 and"
               " (%d - 1)!\n", factor);
        exit(1);
    }
    // move the list to the front
    curr = pokedex->head;
    // if the there are some Pokemons in pokedex in the range 'factor' 
    srand((int)seed);
    while (n_found < how_many) {
        for (int i = 0; i < seed; i++) {
            // get a random number
            rand_id = rand() % factor;
            curr = pokedex->head;
            while (curr != NULL) { 
                // if the Pokemon id in pokedex is equal to the random number
                if (curr->pokemon_ID == rand_id) {
                    curr->found = 1;
                    n_found++;
                    break;
                }
                curr = curr->next;
            }
        }
    }
    // if the there is no Pokemon in pokedex in the range 'factor' 
    
}

int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int f_count = 0;
    while (curr != NULL) {
        if (curr->found == 1) {   
            f_count++;
        }
        curr = curr->next;
    }
    return f_count;
}

int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int t_count = 0;
    while (curr != NULL) { 
        t_count++;
        curr = curr->next;
    }
    return t_count;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *curr = pokedex->head;
    int have_f_id = 0;
    int have_t_id = 0;
    int have_id = 0;
    
    while (curr != NULL && have_id != 1) {
        // check is there Pokenon with the ID 'from_id'
        // and 'from_id' can't same as 'to_id'
        if (curr->pokemon_ID == from_id && curr->pokemon_ID != to_id) {
            have_f_id = 1;
        // check is there Pokenon with the ID 'to_id'
        // and 'to_id' can't same as 'from_id'
        } else if (curr->pokemon_ID == to_id && curr->pokemon_ID != from_id) {
            have_t_id = 1;
        }
        have_id = have_f_id * have_t_id;
        curr = curr->next;
    }
    // move the list to the front
    curr = pokedex->head;
    // If there is Pokemon with the ID `from_id` or `to_id`
    if (have_id == 1) {
        while (curr != NULL) {
            // find Pokemon who have form_id
            if (curr->pokemon_ID == from_id) {
                curr->evolve = to_id;
                break;
            }
            curr = curr->next;
        }
    // If there is no Pokemon with the ID `from_id` or `to_id`
    } else if (have_id == 0) {
        printf("Invalid Pokemon Evolution!\n");
        exit(1);
    }
}

void show_evolutions(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *show_evolve = pokedex->head;
    struct pokenode *current = NULL;
    // check the evolution of a pokemon also can evolve into the other Pokemon
    int flag = 0;
    
    while (curr != NULL) {
        // if this Pokemon is current Pokemon
        if (curr->current == 1) {
            print_evolve(curr);
            current = curr;
            // print the evolve Pokemon of the current Pokemon
            while (show_evolve != NULL) {
                if (show_evolve->pokemon_ID == current->evolve) {
                    printf("--> ");
                    print_evolve(show_evolve);
                    current = show_evolve;
                    flag = 1;
                } 
                // go back to the front list, to check is there any Pokemon
                // that's the current Pokemon's evolution
                if (flag == 1) {
                    show_evolve = pokedex->head;
                    flag = 0;
                } else {
                    show_evolve = show_evolve->next;
                }
                
            }
            printf("\n");
        }
        curr = curr->next;
    }
}

// get next evolution of currently selected Pokemon
// if the Pokemon have no evolution, return it DOES_NOT_EVOLVE,
// else return a Pokemon ID of its evolution
int get_next_evolution(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int pokemon_ID = DOES_NOT_EVOLVE;
    
    if (curr == NULL) {
        printf("The Pokedex is empty!\n");
        exit(1);
    }
    while (curr != NULL) {
        if (curr->current == 1) {
            if (curr->evolve != DOES_NOT_EVOLVE) {
                pokemon_ID = curr->evolve;
                break;
            } else if (curr->evolve == DOES_NOT_EVOLVE) {
                return DOES_NOT_EVOLVE;
            }
        }
        curr = curr->next;
    }
    return pokemon_ID;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    // create a new pokedex
    Pokedex new = new_pokedex();
    struct pokenode *curr = pokedex->head;
    int first_type, second_type;
    if (type != NONE_TYPE && type != INVALID_TYPE && type != MAX_TYPE) {
        while (curr != NULL) {
            first_type = pokemon_first_type(curr->pokemon);
            second_type = pokemon_second_type(curr->pokemon);
            // if one of the type is the same of the given type 
            // and the Pokemon have been found
            // then add it to the new Pokedex
            if ((first_type == type || second_type == type) && curr->found == 1) {
                Pokemon new_pokemon = clone_pokemon(curr->pokemon);
                add_pokemon(new, new_pokemon);
            }        
            curr = curr->next;
        }
    } else {
        printf("Invalid type");
    }
    // set all Pokemon have been found
    new = set_all_found(new);
    return new;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    // new pokedex
    Pokedex new = new_pokedex();
    Pokedex sort = new_pokedex();
    // find out all the Pokemon have been found
    while (curr != NULL) {
        if (curr->found == 1) {
            Pokemon sort_new = clone_pokemon(curr->pokemon);
            add_pokemon(sort, sort_new);
        }
        curr = curr->next;
    }
    new = sort_pokemon(new, sort);
    destroy_pokedex(sort);
    return new;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex new = new_pokedex();
    struct pokenode *curr = pokedex->head;
    char *p_name, *flag, *ch_text;
    char *t = text;
    
    while (curr != NULL) { 
        p_name = pokemon_name(curr->pokemon);
        ch_text  = t;
        if (curr->found == 1) {
            for (char *ch_name = p_name; *ch_name != '\0'; ch_name++) {
                flag = ch_name;
                // if there is one letter equal to the first letter in 'text'
                if (check_upper_lower_case(ch_name, ch_text)) {
                    for (ch_text = t; *ch_text != '\0'; ch_text++) {
                        // then chack the remain letter
                        if (check_upper_lower_case(ch_name, ch_text)) {
                            ch_name++;
                        } else {
                            ch_name = flag;
                            ch_text  = t;
                            break;
                        }
                    }
                }
                // if 'ch_text' is '\0', which means 'ch_text' went to the end
                // and that will only happen while 
                // the Pokemon's name have the same word as the given text
                if (*ch_text == '\0') {
                    // store matched Pokemon in the new Pokedex
                    Pokemon new_pokemon = clone_pokemon(curr->pokemon);
                    add_pokemon(new, new_pokemon);
                    break;
                }
            }
        }
        curr = curr->next;
    }  
    // set all Pokemon have been found
    new = set_all_found(new);
    return new;
}

void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *free_list = pokedex->head;
    while (curr != NULL) {
        free_list = curr;
        destroy_pokemon(free_list->pokemon);
        curr = curr->next;
        free(free_list);
    }
    free(curr);
    free(pokedex);
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

// print out the evolution's information, such as ID, name, type
static void print_evolve(struct pokenode *curr) {
    int first_type, second_type;
    first_type = pokemon_first_type(curr->pokemon);
    second_type = pokemon_second_type(curr->pokemon);
    // if the Pokemon have been found
    if (curr->found == 0) {
        printf("#%03d ", curr->pokemon_ID);
        printf("???? ");
        printf("[????] ");
    // if the Pokemon haven't been found
    } else if (curr->found == 1) {
        printf("#%03d ", curr->pokemon_ID);
        printf("%s ", pokemon_name(curr->pokemon));
        printf("[%s", pokemon_type_to_string(first_type));
        if (second_type > 0) {
            printf(" %s", pokemon_type_to_string(second_type));
        }
        printf("]");
    }
}

// print the detail of current Pokemon, such as Pokemon's ID, name, height, 
// weight, and type
// if the Pokemon have not been found, 
// replace the Pokemon's name by the same amount of *
// the replace height, weight, and type by "--"
static void print_pokemon_detail(struct pokenode *curr) {
    int first_type, second_type;
    char *name = pokemon_name(curr->pokemon);
    first_type = pokemon_first_type(curr->pokemon);
    second_type = pokemon_second_type(curr->pokemon);
    // if the pokemon be found
    printf("Id: %03d\n", pokemon_id(curr->pokemon));
    if (curr->found == 1) {
        printf("Name: %s\n", pokemon_name(curr->pokemon));
        printf("Height: %.1lfm\n", pokemon_height(curr->pokemon));
        printf("Weight: %.1lfkg\n", pokemon_weight(curr->pokemon));
        printf("Type: %s ", pokemon_type_to_string(first_type));
        if (second_type > 0) {
            printf("%s", pokemon_type_to_string(second_type));
        }
        printf("\n");
    // if the pokemon not be found
    } else if (curr->found == 0) {
        printf("Name: ");
        for (char *ptr = name; *ptr != '\0'; ptr++) {
            printf("*");
        }    
        printf("\n");
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    }  
}

// sort Pokemon base on the Pokemon ID
static Pokedex sort_pokemon(Pokedex pokedex, Pokedex sort) {
    struct pokenode *sort_curr = sort->head;
    int count = 0;
    int largest_id = 0;
    // find the largest Pokemon ID
    while (sort_curr != NULL) {
        if (sort_curr->pokemon_ID > largest_id) {
            largest_id = sort_curr->pokemon_ID;
        }
        sort_curr = sort_curr->next;
    }   
    sort_curr = sort->head;
    
    // count go from 0 .. the largest Pokemon ID, 
    // so the Pokedex will be sorted by ascending order
    while (count <= largest_id) {
        sort_curr = sort->head;
        while (sort_curr != NULL) {
            // if the Pokemon ID is the same as 'count'
            if (sort_curr->pokemon_ID == count) {
                // copy 'sort_curr->pokemon' to 'pokedex'
                Pokemon new_pokemon = clone_pokemon(sort_curr->pokemon);
                add_pokemon(pokedex, new_pokemon);
                break;
            }
            sort_curr = sort_curr->next;
        }
        count++;
    }
    // set all Pokemon have been found
    pokedex = set_all_found(pokedex);
    return pokedex;
}

// check the UpperCase/LowerCase of Pokemon name's letter is the 
// same as giving text's letter
static int check_upper_lower_case(char *pokemon_name, char *text) {
    if (*pokemon_name + 'a' - 'A' == *text || 
        *pokemon_name + 'A' - 'a' == *text ||
        *pokemon_name == *text) {
        return 1;
    } else {
        return 0;
    }
}

// set all the Pokemon to be found
static Pokedex set_all_found(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        curr->found = 1;
        curr = curr->next;
    }
    return pokedex;
}
