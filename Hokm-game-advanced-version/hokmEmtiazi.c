#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabeEmtiazi.h"
void shuffle_card(int *card);
int main()
{
    int index, subMultiple, remain, symbol, flag2, cards[4][11], card[44], setTeam1 = 0, setTeam2 = 0;
    char bakhshname2;
    for (int i = 0; i < 5; i++) /*for playing 5 sets*/
    {
        flag2 = 1;
        shuffle_card(card); /*for shuffling the cards*/
        for (int i = 0; i < 5; i++)
        { /*5 cards for p1*/
            cards[0][i] = card[i];
        }
        zaminBazi(cards, card, flag2);
        Bakhshname(&bakhshname2); /*choosing the bakhshname by p1*/
        flag2 = 0;
        zaminBazi(cards, card, flag2);
        rounds(cards, bakhshname2, &setTeam1, &setTeam2); /*playing the round*/
    }
}
void shuffle_card(int *card)
{ /*for shuffling the cards*/
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}
