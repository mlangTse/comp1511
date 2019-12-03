//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the assignment - ask in the course forum.
//
// Assignment 2 19T1 COMP1511: Pokedex
// pokemon.h
//
// Version 1.0.0: Assignment released.

#ifndef _POKEMON_H_
#define _POKEMON_H_

////////////////////////////////////////////////////////////////////////
//                     enum pokemon_type                              //
////////////////////////////////////////////////////////////////////////

// The enum `pokemon_type` provides named constants that can be used.
//
// This is similar in effect to
// #define NONE_TYPE    0
// #define NORMAL_TYPE  1
// #define FIRE_TYPE    2
// ...
//
// Note that you should access the types via the names below, e.g.
// NORMAL_TYPE or FIRE_TYPE, rather than trying to use a numeric value
// directly.
//
// Also note that the types below are not strings, i.e. your code should
// use NORMAL_TYPE, not "NORMAL_TYPE".
typedef enum pokemon_type {
    INVALID_TYPE = -1,
    NONE_TYPE,
    NORMAL_TYPE,
    FIRE_TYPE,
    FIGHTING_TYPE,
    WATER_TYPE,
    FLYING_TYPE,
    GRASS_TYPE,
    POISON_TYPE,
    ELECTRIC_TYPE,
    GROUND_TYPE,
    PSYCHIC_TYPE,
    ROCK_TYPE,
    ICE_TYPE,
    BUG_TYPE,
    DRAGON_TYPE,
    GHOST_TYPE,
    DARK_TYPE,
    STEEL_TYPE,
    FAIRY_TYPE,
    MAX_TYPE
} pokemon_type;


////////////////////////////////////////////////////////////////////////
//                 typedef struct pokemon *Pokemon                    //
////////////////////////////////////////////////////////////////////////

// This typedef declares that the type "Pokemon" is the same as the type
// "pointer to struct pokemon".
//
// The actual definition of `struct pokemon` is not in pokemon.h (this
// file) -- it's in pokemon.c
//
// This means that you cannot directly access any of the fields of the
// pokemon struct -- e.g. "pokemon->pokemon_id" is *invalid*.
//
// If you get the following error:
//
//    error: incomplete definition of type 'struct pokemon'
//
// you must make sure that you are only interacting with Pokemon via the
// functions in pokemon.h (e.g. pokemon_id, pokemon_name, etc).
typedef struct pokemon *Pokemon;


////////////////////////////////////////////////////////////////////////
//                        Pokemon functions                           //
////////////////////////////////////////////////////////////////////////

// Create a new Pokemon, given its pokemon_id, name, height, weight, and
// type(s).
//
// The pokemon_id must be a non-negative integer (i.e. >= 0).
//
// The name must consist only of uppercase letters, lowercase letters,
// spaces (' ') and hyphens ('-').
//
// If the name provided contains any invalid characters, the function
// should print an appropriate error message and exit the program.
//
// The two types provided must be integers representing the type->int
// mapping in pokemon_types.h.
//
// Pokemon can have one or two types. If the Pokemon only has one type,
// `type2` should be NONE_TYPE.
//
// If the type(s) given are invalid, i.e. if `type1` is NONE_TYPE,
// or if `type1` and `type2` are the same type, the function should
// print an appropriate error message and exit the program.
//
// Weight is given in kilograms, and height is given in metres.
//
// Example: new_pokemon(0, "Pikachu", 12, 2.5, ELECTRIC_TYPE, NONE_TYPE)
Pokemon new_pokemon(int pokemon_id, char *name, double height,
    double weight, pokemon_type type1, pokemon_type type2);

// Create a clone of the given Pokemon.
//
// The cloned Pokemon should have all of the same attributes as the
// original Pokemon (e.g. same pokemon_id, same name, ...).
//
// The cloned Pokemon should be entirely separate from the original
// Pokemon, such that later deleting the original Pokemon will not
// affect the cloned Pokemon.
Pokemon clone_pokemon(Pokemon pokemon);

// Return the pokemon_id of a given Pokemon.
int pokemon_id(Pokemon pokemon);

// Return the name of a given Pokemon.
// The returned string has not been allocated with malloc.
// It should not be changed or freed by the caller.
char *pokemon_name(Pokemon pokemon);

// Return the height of a given Pokemon.
double pokemon_height(Pokemon pokemon);

// Return the weight of a given Pokemon.
double pokemon_weight(Pokemon pokemon);

// Return the first type of a given Pokemon.
pokemon_type pokemon_first_type(Pokemon pokemon);

// Return the second type of a given Pokemon.
// If the Pokemon only has one type, returns NONE_TYPE.
pokemon_type pokemon_second_type(Pokemon pokemon);

// Free the memory associated with a given Pokemon.
void destroy_pokemon(Pokemon pokemon);

// Check whether the specified `name` is a valid name for a Pokemon.
// Returns 1 iff name contains only characters permitted for a Pokemon.
// Returns 0 if not.
int pokemon_valid_name(char *name);


////////////////////////////////////////////////////////////////////////
//                      pokemon_type functions                        //
////////////////////////////////////////////////////////////////////////

// Return the pokemon_type value for the given `type_name`.
//
// Example: pokemon_type_from_string("Fire") returns FIRE_TYPE.
//
// Returns INVALID_TYPE if `type_name` is not a valid Pokemon type.
pokemon_type pokemon_type_from_string(char *type_name);

// Return the name of the given pokemon_type value.
//
// Example: pokemon_type_to_string(FIRE_TYPE) returns "Fire".
//
// The returned string has not been allocated with malloc.
// It should not be changed or freed by the caller.
const char *pokemon_type_to_string(pokemon_type type);

#endif // _POKEMON_H_
