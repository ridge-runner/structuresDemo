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
	
	deal(deck); // deal cards to stdout. Check that deck is complete.
	puts("\n ---------------------------------------");
	
	shuffle(deck); // randomize cards.
	deal(deck);

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
* shuffle()
* Loops through the cards randomly swapping cards.
* NOTE: Rerun this function around seven times for a better result.
*/

void shuffle(Card* const deck) {
	// loop through the deck randomly swapping cards.
	for (int k = 0; k < 7; k++) { // repeating seven times randomizes better.

		for (size_t i = 0; i < CARDS; ++i ) {
			size_t j = rand() % CARDS; 
			Card temp = deck[i];
			deck[i] = deck[j];
			deck[j] = temp;
		}//end for
	}//end for
}//shuffle()

/*
* deal()
* Deals the cards, revealing them via stdout.
*/

void deal(const Card* const deck) {
	// loop through the deck. 
	// The printf func %5s is spaces, %-8s separates
	// the card names. The ternary expression checks to 
	// see if a row of four cards have been laid down.
	// if false (0), the \n is added.
	for (size_t i = 0; i < CARDS; ++i ) {
		printf("%5s of %-8s%s", deck[i].face, deck[i].suit,
			(i + 1) % 4 ? "  " : "\n" );
	}
}

