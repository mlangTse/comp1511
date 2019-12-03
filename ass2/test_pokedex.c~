// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.


// Sample data on Ivysaur, the Pokemon with pokemon_id 1.
#define IVYSAUR_ID 1
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

// Sample data on Bulbasaur, the Pokemon with pokemon_id 2.
#define BULBASAUR_ID 2
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// the Pokemon with pokemon_id 24
#define ARBOK_ID 24
#define ARBOK_NAME "Arbok"
#define ARBOK_HEIGHT 3.5
#define ARBOK_WEIGHT 65.0
#define ARBOK_FIRST_TYPE POISON_TYPE
#define ARBOK_SECOND_TYPE NONE_TYPE
// Add your own prototypes here.


// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_next_pokemon(void);
static void test_get_found_pokemon(void);
static void test_prev_pokemon(void);
static void test_get_pokemon_of_type(void);
static void test_search_pokemon(void);


// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_arbok(void);
static int same_pokemon(Pokemon A, Pokemon B);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_prev_pokemon();
    test_get_pokemon_of_type();
    test_get_found_pokemon();
    test_search_pokemon();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur, and from Ivysaur to Bulbasaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(same_pokemon(get_current_pokemon(found_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!

// `test_prev_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// prev_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Bulbasaur, then move to Arbok which is the last Pokemon in Pokedex.
// and call the prev_pokemon function changes the currently selected Pokemon from
// Arbok to Ivysaur
//
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon arbok = create_arbok();

    printf("    ... Adding Bulbasaur, Ivysaur and Arbok to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, arbok);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasau\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to Arbok\n");
    change_current_pokemon(pokedex, ARBOK_ID);

    printf("       --> Checking that the current Pokemon is Arbok\n");
    assert(same_pokemon(get_current_pokemon(pokedex), arbok));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_pokemon_of_type` checks whether the get_pokemon_of_type
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur, Ivysaur and Arbok(using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Ivysaur to be found, and
// then calls the get_pokemon_of_type function to get all of the Pokemon
// which have been found, and it's Posion type (which should be Abork).
//
// then back to the orginal Pokedex, set Ivysaur to be found, and 
// then calls the get_pokemon_of_type function to get all of the Pokemon
// which have been found, and it's grass type (which should be  Ivysaur
// since Arbok is not grass type, and Bulbasaur is not found)
// therefore, there is one Pokemon in new pokedex after called get_pokemon_of_type 
// and the currently selected will be Ivysaur

static void test_get_pokemon_of_type(void) {
    printf("\n>> Testing get_pokemon_of_type\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Ivysaur and Arbok\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon arbok = create_arbok();

    printf("    ... Adding Bulbasaur, Ivysaur and Arbok to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, arbok);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Moving to Arbok\n");
    change_current_pokemon(pokedex, ARBOK_ID);

    printf("       --> Checking that the current Pokemon is Arbok\n");
    assert(same_pokemon(get_current_pokemon(pokedex), arbok));
    
    printf("    ... Setting Arbok to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting Pokemon which is Posion type, and have been found\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, POISON_TYPE);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(type_pokedex) == 1);
    assert(count_found_pokemon(type_pokedex) == 1);
    assert(same_pokemon(get_current_pokemon(type_pokedex), arbok));
    
    printf("    ... Destroying search Pokedex, back to the orginal Pokedex\n");
    destroy_pokedex(type_pokedex);
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting Pokemon which is Grass type, and have been found\n");
    Pokedex type_pokedex2 = get_pokemon_of_type(pokedex, GRASS_TYPE);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(type_pokedex2) == 1);
    assert(count_found_pokemon(type_pokedex2) == 1);
    assert(same_pokemon(get_current_pokemon(type_pokedex2), ivysaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex2);

    printf(">> Passed get_found_pokemon tests!\n");
}

// `test_search_pokemon` checks whether the search_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur, Ivysaur and Arbok(using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Ivysaur to be found, and
// then calls the search_pokemon function to get all of the Pokemon
// which have been found, and contain'SaU' (which should be just the one, Ivysaur).
//
// then back to the orginal Pokedex, set Bulbasaur to be found, and 
// then calls the search_pokemon function to get all of the Pokemon
// which have been found, and contain 'A' (which should be both Bulbasaur and Ivysaur
// since Arbok have not been found, Arbok is not count)
// therefore, there are two Pokemon in new pokedex after called search_pokemon 
// and the currently selected will be Bulbasaur

static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Ivysaur and Arbok\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon arbok = create_arbok();

    printf("    ... Adding Bulbasaur, Ivysaur and Arbok to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, arbok);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting Pokemon which name contain 'SaU'\n");
    char *t = "SaU";
    Pokedex search_pokedex = search_pokemon(pokedex, t);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(search_pokedex) == 1);
    assert(count_found_pokemon(search_pokedex) == 1);
    assert(same_pokemon(get_current_pokemon(search_pokedex), ivysaur));
    
    printf("    ... Destroying search Pokedex, back to the orginal Pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting Pokemon which name contain 'A'\n");
    char *t2 = "A";
    Pokedex search_pokedex2 = search_pokemon(pokedex, t2);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(search_pokedex2) == 2);
    assert(count_found_pokemon(search_pokedex2) == 2);
    assert(same_pokemon(get_current_pokemon(search_pokedex2), bulbasaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex2);

    printf(">> Passed get_found_pokemon tests!\n");
}

////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_arbok(void) {
    Pokemon pokemon = new_pokemon(
            ARBOK_ID, ARBOK_NAME,
            ARBOK_HEIGHT, ARBOK_WEIGHT,
            ARBOK_FIRST_TYPE,
            ARBOK_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the "same", based
// on whether their attributes match (e.g. id, height, weight, etc).
//
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int same_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!
