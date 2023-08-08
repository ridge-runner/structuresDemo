/*
* SHUFFLER PROGRAM
* A demo of structures
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// structure definitions
struct card {
	const char* face; // def pointer face
	const char* suit; // def pointer suit
};

typedef struct card Card; // new name for struct card

// func prototypes

void fillDeck(Card* const deck, const char* faces[], const char* suits[]);

void shuffle(Card* const deck);

void deal(const Card* const deck);

int main(void) {

	Card deck[CARDS]; // define array of Cards

	// init faces array of pointers
	const char* faces[] = { "Ace", "Deuce", "Three", "Four", "Five",
							"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	// init suits array of pointers
	const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	srand(time(NULL)); //randomize

	fillDeck(deck, faces, suits); // load the deck with cards.
	shuffle(deck); // randomize cards.
	deal(deck); // deal all 52 cards to stdout.

	return 0;
}

/*
* fillDeck()
* place arrays of strings into Card Structures
* 
*/

void fillDeck(Card* const deck, const char* faces[], const char* suits[]) {

	// loop through the deck. The mod (%) fills the array values in order. Once the 
	// iterator var becomes > FACES. The card faces are cycled through again.
	// This continues until the deck is built.
	
	for (size_t i = 0; i < CARDS; ++i) {
			deck[i].face = faces[i % FACES];
			deck[i].suit = suits[i / FACES];
	}
}

/*
* shuffle(Card* const deck)
* Loops through the cards randomly swapping cards.
* NOTE: Rerun this function around seven times for a better result.
*/

void shuffle(Card* const deck) {
	// loop through the deck randomly swapping cards.
	for (size_t i = 0; i < CARDS; ++i ) {
		size_t j = rand() % CARDS; 
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

/*
* deal()
* Deals the cards, revealing them via stdout.
*/

void deal(const Card* const deck) {
	// loop through the deck
	for (size_t i = 0; i < CARDS; ++i ) {
		printf("%5s of %-8s%s", deck[i].face, deck[i].suit,
			(i + 1) % 4 ? "  " : "\n" );
	}
}
