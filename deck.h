#ifndef DECK_H
#define DECK_H

#include <stdio.h>

/**
 * enum kind_e - suit enumeration
 *
 * @SPADE: 0
 * @DIAMOND: 3
 * @HEART: 1
 * @CLUB: 2

 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card.
 *
 * @value: The value of the card, ranging from "Ace" to "King".
 * @kind: The kind or suit of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards.
 *
 * @card: Pointer to the card associated with the node.
 * @prev: Pointer to the previous node in the list.
 * @next: Pointer to the next node in the list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

	/*prototypes*/
void sort_deck(deck_node_t **deck);
int less_than(const card_t *a, const card_t *b);
void cocktail_sort_list(deck_node_t **list);


#endif /*DECK_H*/
