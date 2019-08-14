#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

int main(void)
{
    unsigned int deck[SUITS][FACES] = {0};

    srand(time(NULL));

    shuffle(deck);

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, face, suit);
}

void shuffle(unsigned int wDeck[][FACES])
{
    size_t row = 0;
    size_t column = 0;

    //initialize the deck
    for(row = 0; row < SUITS; ++row){
        for(column = 0; column < FACES; ++column){
            wDeck[row][column] = column;
        }
    }

    //shuffle the deck
    for(row = 0; row < SUITS; ++row){
        for(column = 0; column < FACES; ++column){
            int random_1 = rand() % FACES;
            int random_2 = rand() % SUITS;
            int temp = 0;
            temp = wDeck[row][column];
            wDeck[row][column] = wDeck[random_2][random_1];
            wDeck[random_2][random_1] = temp;
        }
    }
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    int sum = 0;
    while(sum != 52){
        int random_row = rand() % SUITS;
        int random_column = rand() % FACES;
        if(wDeck[random_row][random_column] != -1){
            printf("%5s of %-8s\n", wFace[random_column], wSuit[random_row]);
            wDeck[random_row][random_column] = -1;
            sum++;
        }
    }
}
