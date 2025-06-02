#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabe.h"
void shuffle_card(int* card);
int main(){
    int index, subMultiple, remain, symbol, flag2, cards[4][11], card[44];
    char bakhshname2;
    shuffle_card(card);
    for (int i = 0; i < 5; i++){
        cards[0][i] = card[i];
    }
    zaminBazi(cards, card, flag2);
    Bakhshname(&bakhshname2);
    flag2 = 0;
    zaminBazi(cards, card, flag2);
    rounds(cards, bakhshname2);
}
void shuffle_card(int* card) { /*for shuflling the cards*/
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}