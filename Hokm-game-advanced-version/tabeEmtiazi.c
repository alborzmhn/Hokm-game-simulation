#include "tabeEmtiazi.h"
#include <stdio.h>
char Symbol(int cards[4][11], int player, int index)
{ /*for finding the symbol of a number between 0 and 43*/
    switch (cards[player][index] / 11)
    {
    case 0:
        return 'A'; /*the symbol is A*/
        break;
    case 1:
        return 'B'; /*the symbol is B*/
        break;
    case 2:
        return 'C'; /*the symbol is C*/
        break;
    case 3:
        return 'D'; /*the symbol is D*/
        break;
    }
}
int symbolReverse(char symbol)
{ /*for returning a symbol to a number*/
    int symbolReverse, numberReverse;
    if (symbol == 'A')
    {
        return 0;
    }
    else if (symbol == 'B')
    {
        return 11;
    }
    else if (symbol == 'C')
    {
        return 22;
    }
    else if (symbol == 'D')
    {
        return 33;
    }
}
int findGreatest(int arr[11], int arrSize, int *iGreatest)
{ /*for finding the biggest element of an array*/
    int situation, i;
    for (i = 0; i < arrSize; i++)
    {
        situation = 1;
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[i] < arr[j])
            {
                situation = 0; /*it is not the biggest element so the situation will be 0*/
                break;
            }
        }
        if (situation)
        {                   /*the element is the biggest element*/
            *iGreatest = i; /*the index of the gretest element*/
            return arr[i];
        }
    }
}
int findSmallest(int arr[11], int arrSize, int *iSmallest)
{ /*for finding the smallest element of an array*/
    int situation, i;
    for (i = 0; i < arrSize; i++)
    {
        situation = 1;
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[i] > arr[j] && arr[j] != 0)
            {
                situation = 0; /*it is not the smallest element so the situation will be 0*/
                break;
            }
        }
        if (situation == 1)
        {                   /*the element is the smallest element*/
            *iSmallest = i; /*the index of the smallest element*/
            return arr[i];
        }
    }
}
char Bakhshname(char *pointer)
{
    char bakhshname;
    printf("\nenter the bakhshname : "); /*input the bakhshname from p1*/
    scanf("%c", &bakhshname);
    while (bakhshname != 'A' && bakhshname != 'B' && bakhshname != 'C' && bakhshname != 'D')
    { /*it is a wrong bakhshname*/
        getchar();
        printf("wrong charachter\nenter another bakhshname : ");
        scanf("%c", &bakhshname);
    }
    *pointer = bakhshname;
}
char numToSymbol(int number)
{ /*returning the symbol of a number*/
    int symbol = number / 11;
    switch (symbol)
    {
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'D';
        break;
    }
}
void player4(int cards[4][11], char bakhshname2, int index, char *symbolp4, int *Cardp4, int Cardp3, int Cardp2, int Cardp1, char firstSymbol, int *flagp4)
{
    int iGreatest4, iSmallest4, flag3 = 0, flag4 = 0;
    int symbolp4array[11] = {44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44};
    int cardp4[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (Cardp2 != 0 && Cardp2 > (Cardp1 % 11 + 1) && Cardp2 > Cardp3)
    { /*the card number of his teammate is more than the other two players*/
        for (int i = 0; i < 11; i++)
        {
            if ((cards[3][i] >= symbolReverse(firstSymbol)) && (cards[3][i] < symbolReverse(firstSymbol) + 11))
            { /*searching for the cards matching with the first symbol*/
                if (cards[3][i] < 44)
                { /*checking for this card have been played before or not*/
                    cardp4[i] = (cards[3][i] % 11) + 1;
                    *Cardp4 = findSmallest(cardp4, 11, &iSmallest4); /*finding the smallest card number*/
                    *symbolp4 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        { /*if the p4 didnt have any card matching with the first symbol*/
            if (cardp4[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[3][i] < symbolReverse(bakhshname2)) || (cards[3][i] >= symbolReverse(bakhshname2) + 11))
                { /*searching for the cards with non_bakhshname symbol*/
                    if (cards[3][i] < 44)
                    { /*checking for this card have been played before or not*/
                        symbolp4array[i] = (cards[3][i] / 11);
                        cardp4[i] = (cards[3][i] % 11) + 1;
                        *Cardp4 = findSmallest(cardp4, 11, &iSmallest4);         /*finding the smallest card number*/
                        *symbolp4 = numToSymbol(symbolp4array[iSmallest4] * 11); /*finding the symbol of chosen card*/
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        { /*if the p4 didnt have any card with non_bakhshname symbol*/
            if (cardp4[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[3][i] >= symbolReverse(bakhshname2)) || (cards[3][i] < symbolReverse(bakhshname2) + 11))
                { /*searching for the cards with bakhshname symbol*/
                    if (cards[3][i] < 44)
                    { /*checking for this card have been played before or not*/
                        symbolp4array[i] = (cards[3][i] / 11);
                        cardp4[i] = (cards[3][i] % 11) + 1;
                        *Cardp4 = findSmallest(cardp4, 11, &iSmallest4); /*finding the smallest card number*/
                        *symbolp4 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[3][i] == ((*Cardp4 - 1) + (symbolReverse(*symbolp4))))
                cards[3][i] = 44; /*that means this card have been used and cannot be able to used again*/
        }
        *flagp4 = 1; /*p4 has played his turn*/
    }
    else
    { /*the card number of his teammate isnt more than the other two players*/
        for (int i = 0; i < 11; i++)
        {
            if ((cards[3][i] >= symbolReverse(firstSymbol)) && (cards[3][i] < symbolReverse(firstSymbol) + 11))
            { /*searching for the cards matching with the first symbol*/
                if (cards[3][i] < 44)
                { /*checking for this card have been played before or not*/
                    cardp4[i] = (cards[3][i] % 11) + 1;
                    *Cardp4 = findGreatest(cardp4, 11, &iGreatest4); /*finding the greatest card number*/
                    *symbolp4 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        { /*if the p4 didnt have any card matching with the first symbol*/
            if (cardp4[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[3][i] >= symbolReverse(bakhshname2)) && (cards[3][i] < symbolReverse(bakhshname2) + 11))
                { /*searching for the cards with bakhshname symbol*/
                    if (cards[3][i] < 44)
                    { /*checking for this card have been played before or not*/
                        cardp4[i] = (cards[3][i] % 11) + 1;
                        *Cardp4 = findGreatest(cardp4, 11, &iGreatest4); /*finding the greatest card number*/
                        *symbolp4 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        { /*if the p4 didnt have any card with bakhshname symbol*/
            if (cardp4[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[3][i] < symbolReverse(bakhshname2)) || (cards[3][i] >= symbolReverse(bakhshname2) + 11))
                { /*searching for the cards with non_bakhshname symbol*/
                    if (cards[3][i] < 44)
                    { /*checking for this card have been played before or not*/
                        symbolp4array[i] = (cards[3][i] / 11);
                        cardp4[i] = (cards[3][i] % 11) + 1;
                        *Cardp4 = findSmallest(cardp4, 11, &iSmallest4);         /*finding the smallest card number*/
                        *symbolp4 = numToSymbol(symbolp4array[iSmallest4] * 11); /*finding the symbol of chosen card*/
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[3][i] == ((*Cardp4 - 1) + (symbolReverse(*symbolp4))))
                cards[3][i] = 44; /*that means this card have been used and cannot be able to used again*/
        }
        *flagp4 = 1; /*p4 has played his turn*/
    }
}
void player3(int cards[4][11], char bakhshname2, int index, char *symbolp3, int *Cardp3, int Cardp4, int Cardp2, int Cardp1, char firstSymbol, int *flagp3)
{ /*as the same as p4 job*/
    int iGreatest3, iSmallest3, flag3 = 0, flag4 = 0;
    int symbolp3array[11] = {44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44};
    int cardp3[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (Cardp1 % 11 + 1 != 0 && Cardp1 % 11 + 1 > Cardp2 && Cardp1 % 11 + 1 > Cardp4)
    {
        for (int i = 0; i < 11; i++)
        {
            if ((cards[2][i] >= symbolReverse(firstSymbol)) && (cards[2][i] < symbolReverse(firstSymbol) + 11))
            {
                if (cards[2][i] < 44)
                {
                    cardp3[i] = (cards[2][i] % 11) + 1;
                    *Cardp3 = findSmallest(cardp3, 11, &iGreatest3);
                    *symbolp3 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp3[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[2][i] < symbolReverse(bakhshname2)) || (cards[2][i] >= symbolReverse(bakhshname2) + 11))
                {
                    if (cards[2][i] < 44)
                    {
                        symbolp3array[i] = (cards[2][i] / 11);
                        cardp3[i] = (cards[2][i] % 11) + 1;
                        *Cardp3 = findSmallest(cardp3, 11, &iSmallest3);
                        *symbolp3 = numToSymbol(symbolp3array[iSmallest3] * 11);
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp3[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[2][i] >= symbolReverse(bakhshname2)) || (cards[2][i] < symbolReverse(bakhshname2) + 11))
                {
                    if (cards[2][i] < 44)
                    {
                        symbolp3array[i] = (cards[2][i] / 11);
                        cardp3[i] = (cards[2][i] % 11) + 1;
                        *Cardp3 = findSmallest(cardp3, 11, &iSmallest3);
                        *symbolp3 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[2][i] == ((*Cardp3 - 1) + (symbolReverse(*symbolp3))))
                cards[2][i] = 44;
        }
        *flagp3 = 1;
    }
    else
    {
        for (int i = 0; i < 11; i++)
        {
            if ((cards[2][i] >= symbolReverse(firstSymbol)) && (cards[2][i] < symbolReverse(firstSymbol) + 11))
            {
                if (cards[2][i] < 44)
                {
                    cardp3[i] = (cards[2][i] % 11) + 1;
                    *Cardp3 = findGreatest(cardp3, 11, &iGreatest3);
                    *symbolp3 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp3[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[2][i] >= symbolReverse(bakhshname2)) && (cards[2][i] < symbolReverse(bakhshname2) + 11))
                {
                    if (cards[2][i] < 44)
                    {
                        cardp3[i] = (cards[2][i] % 11) + 1;
                        *Cardp3 = findGreatest(cardp3, 11, &iGreatest3);
                        *symbolp3 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp3[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[2][i] < symbolReverse(bakhshname2)) || (cards[2][i] >= symbolReverse(bakhshname2) + 11))
                {
                    if (cards[2][i] < 44)
                    {
                        symbolp3array[i] = (cards[2][i] / 11);
                        cardp3[i] = (cards[2][i] % 11) + 1;
                        *Cardp3 = findSmallest(cardp3, 11, &iSmallest3);
                        *symbolp3 = numToSymbol(symbolp3array[iSmallest3] * 11);
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[2][i] == ((*Cardp3 - 1) + (symbolReverse(*symbolp3))))
                cards[2][i] = 44;
        }
        *flagp3 = 1;
    }
}
void player2(int cards[4][11], char bakhshname2, int index, char *symbolp2, int *Cardp2, int Cardp4, int Cardp3, int Cardp1, char firstSymbol, int *flagp2)
{ /*as the same as p4 job*/
    int iGreatest2, iSmallest2, flag3 = 0, flag4 = 0;
    int cardp2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int symbolp2array[11] = {44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44};
    if (Cardp4 != 0 && Cardp4 > (Cardp1 % 11 + 1) && Cardp4 > Cardp3)
    {
        for (int i = 0; i < 11; i++)
        {
            if ((cards[1][i] >= symbolReverse(firstSymbol)) && (cards[1][i] < symbolReverse(firstSymbol) + 11))
            {
                if (cards[1][i] < 44)
                {
                    cardp2[i] = (cards[1][i] % 11) + 1;
                    *Cardp2 = findSmallest(cardp2, 11, &iGreatest2);
                    *symbolp2 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp2[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[1][i] < symbolReverse(bakhshname2)) || (cards[1][i] >= symbolReverse(bakhshname2) + 11))
                {
                    if (cards[1][i] < 44)
                    {
                        symbolp2array[i] = (cards[1][i] / 11);
                        cardp2[i] = (cards[1][i] % 11) + 1;
                        *Cardp2 = findSmallest(cardp2, 11, &iSmallest2);
                        *symbolp2 = numToSymbol(symbolp2array[iSmallest2] * 11);
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp2[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[1][i] >= symbolReverse(bakhshname2)) || (cards[1][i] < symbolReverse(bakhshname2) + 11))
                {
                    if (cards[1][i] < 44)
                    {
                        symbolp2array[i] = (cards[1][i] / 11);
                        cardp2[i] = (cards[1][i] % 11) + 1;
                        *Cardp2 = findSmallest(cardp2, 11, &iSmallest2);
                        *symbolp2 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[1][i] == ((*Cardp2 - 1) + (symbolReverse(*symbolp2))))
                cards[1][i] = 44;
        }
        *flagp2 = 1;
    }
    else
    {
        for (int i = 0; i < 11; i++)
        {
            if ((cards[1][i] >= symbolReverse(firstSymbol)) && (cards[1][i] < symbolReverse(firstSymbol) + 11))
            {
                if (cards[1][i] < 44)
                {
                    cardp2[i] = (cards[1][i] % 11) + 1;
                    *Cardp2 = findGreatest(cardp2, 11, &iGreatest2);
                    *symbolp2 = firstSymbol;
                }
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp2[i] != 0)
            {
                flag3 = 1;
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag3 == 0)
            {
                if ((cards[1][i] >= symbolReverse(bakhshname2)) && (cards[1][i] < symbolReverse(bakhshname2) + 11))
                {
                    if (cards[1][i] < 44)
                    {
                        cardp2[i] = (cards[1][i] % 11) + 1;
                        *Cardp2 = findGreatest(cardp2, 11, &iGreatest2);
                        *symbolp2 = bakhshname2;
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cardp2[i] != 0)
            {
                flag4 = 1;
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (flag4 == 0)
            {
                if ((cards[1][i] < symbolReverse(bakhshname2)) || (cards[1][i] >= symbolReverse(bakhshname2) + 11))
                {
                    if (cards[1][i] < 44)
                    {
                        symbolp2array[i] = (cards[1][i] / 11);
                        cardp2[i] = (cards[1][i] % 11) + 1;
                        *Cardp2 = findSmallest(cardp2, 11, &iSmallest2);
                        *symbolp2 = numToSymbol(symbolp2array[iSmallest2] * 11);
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            if (cards[1][i] == ((*Cardp2 - 1) + (symbolReverse(*symbolp2))))
                cards[1][i] = 44;
        }
        *flagp2 = 1;
    }
}
void startingByPlayer2(int cards[4][11], char bakhshname2, int index, char *symbolp2, int *Cardp2, char *firstSymbol, int *flagp2)
{ /*when p2 is starting the round*/
    int submultipleArray2Start[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iGreatest2start, iSmallest2start, flag4 = 0, flag3 = 0;
    int cardp2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 11; i++)
    {
        if ((cards[1][i] < symbolReverse(bakhshname2)) || (cards[1][i] >= symbolReverse(bakhshname2) + 11))
        {
            if (cards[1][i] < 44) /*checking for this card have played before or not*/
            {
                if ((cards[1][i] % 11) + 1 == 10 || (cards[1][i] % 11) + 1 == 11) /*searching for cards with number 10 and 11 from non_bakhshname symbols*/
                {
                    submultipleArray2Start[i] = cards[1][i] / 11;
                    cardp2[i] = (cards[1][i] % 11) + 1;
                    *Cardp2 = findGreatest(cardp2, 11, &iGreatest2start);                  /*finding the greatest number between 10 and 11*/
                    *symbolp2 = numToSymbol(submultipleArray2Start[iGreatest2start] * 11); /*finding the symbol of the chosen card*/
                }
            }
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp2[i] != 0) /*if the p2 didnt have any card with number 10 or 11 from non_bakhshname symbol*/
        {
            flag4 = 1;
            flag3 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag3 == 0)
        {
            if ((cards[1][i] >= symbolReverse(bakhshname2)) && (cards[1][i] < symbolReverse(bakhshname2) + 11))
            {
                if (cards[1][i] < 44) /*checking for this card have played before or not*/
                {
                    if ((cards[1][i] % 11) + 1 == 10 || (cards[1][i] % 11) + 1 == 11) /*searching for cards with number 10 and 11 from non_bakhshname symbols*/
                    {
                        cardp2[i] = (cards[1][i] % 11) + 1;
                        *Cardp2 = findGreatest(cardp2, 11, &iGreatest2start); /*finding the greatest number between 10 and 11*/
                        *symbolp2 = bakhshname2;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp2[i] != 0) /*if the p2 didnt have any card with number 10 or 11 from bakhshname symbol*/
        {
            flag4 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag4 == 0)
        {
            if ((cards[1][i] < symbolReverse(bakhshname2)) || (cards[1][i] >= symbolReverse(bakhshname2) + 11))
            { /*searching for the cards from non_bakhshname symbol*/
                if (cards[1][i] < 44)
                { /*checking for this card have played before or not*/
                    submultipleArray2Start[i] = cards[1][i] / 11;
                    cardp2[i] = (cards[1][i] % 11) + 1;
                    *Cardp2 = findSmallest(cardp2, 11, &iSmallest2start);                  /*finding the smallest card number*/
                    *symbolp2 = numToSymbol(submultipleArray2Start[iSmallest2start] * 11); /*finding the symbol of the chosen card*/
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cards[1][i] == ((*Cardp2 - 1) + (symbolReverse(*symbolp2))))
            cards[1][i] = 44; /*that means this card have been used and cannot be able to used again*/
    }
    *firstSymbol = *symbolp2;
    *flagp2 = 1; /*p2 has started the round*/
}
void startingByPlayer3(int cards[4][11], char bakhshname2, int index, char *symbolp3, int *Cardp3, char *firstSymbol, int *flagp3)
{ /*as the same as starting by p2*/
    int submultipleArray3Start[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iGreatest3start, iSmallest3start, flag3 = 0, flag4 = 0;
    int cardp3[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 11; i++)
    {
        if ((cards[2][i] < symbolReverse(bakhshname2)) || (cards[2][i] >= symbolReverse(bakhshname2) + 11))
        {
            if (cards[2][i] < 44)
            {
                if ((cards[2][i] % 11) + 1 == 10 || (cards[2][i] % 11) + 1 == 11)
                {
                    submultipleArray3Start[i] = cards[2][i] / 11;
                    cardp3[i] = (cards[2][i] % 11) + 1;
                    *Cardp3 = findGreatest(cardp3, 11, &iGreatest3start);
                    *symbolp3 = numToSymbol(submultipleArray3Start[iGreatest3start] * 11);
                }
            }
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp3[i] != 0)
        {
            flag4 = 1;
            flag3 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag3 == 0)
        {
            if ((cards[2][i] >= symbolReverse(bakhshname2)) && (cards[2][i] < symbolReverse(bakhshname2) + 11))
            {
                if (cards[2][i] < 44)
                {
                    if ((cards[2][i] % 11) + 1 == 10 || (cards[2][i] % 11) + 1 == 11)
                    {
                        cardp3[i] = (cards[2][i] % 11) + 1;
                        *Cardp3 = findGreatest(cardp3, 11, &iGreatest3start);
                        *symbolp3 = bakhshname2;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp3[i] != 0)
        {
            flag4 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag4 == 0)
        {
            if ((cards[2][i] < symbolReverse(bakhshname2)) || (cards[2][i] >= symbolReverse(bakhshname2) + 11))
            {
                if (cards[2][i] < 44)
                {
                    submultipleArray3Start[i] = cards[2][i] / 11;
                    cardp3[i] = (cards[2][i] % 11) + 1;
                    *Cardp3 = findSmallest(cardp3, 11, &iSmallest3start);
                    *symbolp3 = numToSymbol(submultipleArray3Start[iSmallest3start] * 11);
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cards[2][i] == ((*Cardp3 - 1) + (symbolReverse(*symbolp3))))
            cards[2][i] = 44;
    }
    *firstSymbol = *symbolp3;
    *flagp3 = 1;
}
void startingByPlayer4(int cards[4][11], char bakhshname2, int index, char *symbolp4, int *Cardp4, char *firstSymbol, int *flagp4)
{ /*as the same as starting by p2*/
    int submultipleArray4Start[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iGreatest4start, iSmallest4start, flag3 = 0, flag4 = 0;
    int cardp4[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 11; i++)
    {
        if ((cards[3][i] < symbolReverse(bakhshname2)) || (cards[3][i] >= symbolReverse(bakhshname2) + 11))
        {
            if (cards[3][i] < 44)
            {
                if ((cards[3][i] % 11) + 1 == 10 || (cards[3][i] % 11) + 1 == 11)
                {
                    submultipleArray4Start[i] = cards[3][i] / 11;
                    cardp4[i] = (cards[3][i] % 11) + 1;
                    *Cardp4 = findGreatest(cardp4, 11, &iGreatest4start);
                    *symbolp4 = numToSymbol(submultipleArray4Start[iGreatest4start] * 11);
                }
            }
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp4[i] != 0)
        {
            flag4 = 1;
            flag3 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag3 == 0)
        {
            if ((cards[3][i] >= symbolReverse(bakhshname2)) && (cards[3][i] < symbolReverse(bakhshname2) + 11))
            {
                if (cards[3][i] < 44)
                {
                    if ((cards[3][i] % 11) + 1 == 10 || (cards[3][i] % 11) + 1 == 11)
                    {
                        cardp4[i] = (cards[3][i] % 11) + 1;
                        *Cardp4 = findGreatest(cardp4, 11, &iGreatest4start);
                        *symbolp4 = bakhshname2;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cardp4[i] != 0)
        {
            flag4 = 1;
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (flag4 == 0)
        {
            if ((cards[3][i] < symbolReverse(bakhshname2)) || (cards[3][i] >= symbolReverse(bakhshname2) + 11))
            {
                if (cards[3][i] < 44)
                {
                    submultipleArray4Start[i] = cards[3][i] / 11;
                    cardp4[i] = (cards[3][i] % 11) + 1;
                    *Cardp4 = findSmallest(cardp4, 11, &iSmallest4start);
                    *symbolp4 = numToSymbol(submultipleArray4Start[iSmallest4start] * 11);
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (cards[3][i] == ((*Cardp4 - 1) + (symbolReverse(*symbolp4))))
            cards[3][i] = 44;
    }
    *firstSymbol = *symbolp4;
    *flagp4 = 1;
}
void zaminBazi(int cards[4][11], int card[44], int flag2) /*for printing the play ground*/
{
    int remain, subMultiple;
    for (int i = 0; i < 32; i++)
    {
        printf(" ");
    }
    printf("P3");
    for (int i = 0; i < 26; i++)
    {
        printf(" ");
    }
    printf(" \n      ");
    for (int i = 0; i < 55; i++)
    {
        printf("-");
    }
    printf("     team 1 : 0\n");
    for (int i = 0; i < 8; i++)
    {
        printf("      |");
        for (int j = 0; j < 53; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("    P2|");
    for (int i = 0; i < 53; i++)
    {
        printf(" ");
    }
    printf("|P4\n");
    for (int i = 0; i < 8; i++)
    {
        printf("      |");
        for (int j = 0; j < 53; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("      ");
    for (int i = 0; i < 55; i++)
    {
        printf("-");
    }
    printf("     team 2 : 0\n");
    for (int i = 0; i < 32; i++)
    {
        printf(" ");
    }
    printf("P1");
    for (int i = 0; i < 26; i++)
    {
        printf(" ");
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\nsymbol | ");
    for (int i = 0; i < 11; i++)
    {
        if (flag2)
        {
            if (i == 5)
            {
                for (int i = 5; i < 11; i++)
                {
                    printf("-  | ");
                }
                break;
            }
        }
        printf("%c  | ", Symbol(cards, 0, i)); /*for showing the symbol of first 5 card*/
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\nnumber | ");
    for (int i = 0; i < 11; i++)
    {
        if (flag2)
        {
            if (i == 5)
            {
                for (int i = 0; i < 6; i++)
                {
                    printf("0  | ");
                }
                break;
            }
        }
        int subMultiple = (cards[0][i] % 11) + 1;
        if (subMultiple / 10 > 0) /*our number have 2 digits so we print with one less space*/
        {
            printf("%d | ", subMultiple); /*for showing the number of first 5 card*/
        }
        else
        {
            printf("%d  | ", subMultiple);
        }
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\n         ");
    for (int i = 0; i < 11; i++)
    {
        printf("%d    ", i);
    }
    if (flag2)
    {
        for (int i = 0, j = 5; i < 5 && j < 10; j++, i++)
        {
            cards[1][i] = card[j]; /*5 cards for p2*/
        }
        for (int i = 0, j = 10; i < 5 && j < 15; j++, i++)
        {
            cards[2][i] = card[j]; /*5 cards for p3*/
        }
        for (int i = 0, j = 15; i < 5 && j < 20; j++, i++)
        {
            cards[3][i] = card[j]; /*5 cards for p4*/
        }
        for (int i = 5, j = 20; i < 9 && j < 24; j++, i++)
        {
            cards[0][i] = card[j]; /*4 cards for p1*/
        }
        for (int i = 5, j = 24; i < 9 && j < 28; j++, i++)
        {
            cards[1][i] = card[j]; /*4 cards for p2*/
        }
        for (int i = 5, j = 28; i < 9 && j < 32; j++, i++)
        {
            cards[2][i] = card[j]; /*4 cards for p3*/
        }
        for (int i = 5, j = 32; i < 9 && j < 36; j++, i++)
        {
            cards[3][i] = card[j]; /*4 cards for p4*/
        }
        for (int i = 9, j = 36; i < 11 && j < 38; j++, i++)
        {
            cards[0][i] = card[j]; /*2 cards for p1*/
        }
        for (int i = 9, j = 38; i < 11 && j < 40; j++, i++)
        {
            cards[1][i] = card[j]; /*2 cards for p2*/
        }
        for (int i = 9, j = 40; i < 11 && j < 42; j++, i++)
        {
            cards[2][i] = card[j]; /*2 cards for p3*/
        }
        for (int i = 9, j = 42; i < 11 && j < 44; j++, i++)
        {
            cards[3][i] = card[j]; /*2 cards for p4*/
        }
    }
    printf("\n\n\n");
}
void zaminBazi2(int cards[4][11], int winnerTeam1, int winnerTeam2, int Cardp2, int Cardp3, int Cardp4, char symbolp2, char symbolp3,
                char symbolp4, int index, int flagp1, int flagp4, int flagp3, int flagp2, int Index[11], int setTeam1, int setTeam2)
{ /*for printing the playground during the round*/
    int symbolflag, numberflag;
    for (int i = 0; i < 32; i++)
    {
        printf(" ");
    }
    printf("P3");
    for (int i = 0; i < 26; i++)
    {
        printf(" ");
    }
    printf("\n      ");
    for (int i = 0; i < 55; i++)
    {
        printf("-");
    }
    printf("    team 1 : %d\n", winnerTeam1); /*printing the point of team 1*/
    printf("      |");
    for (int j = 0; j < 25; j++)
    {
        printf(" ");
    }
    if (flagp3)
    {
        printf("%d%c", Cardp3, symbolp3); /*printing the chosen card of p3*/
    }
    else
    {
        printf("  ");
    }
    for (int j = 0; j < 25; j++)
    {
        printf(" ");
    }
    printf("|    set team 1 : %d\n", setTeam1); /*printing the sets of team 1*/
    for (int i = 0; i < 7; i++)
    {
        printf("      |");
        for (int j = 0; j < 53; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("    P2|");
    if (flagp2)
    {
        printf("%d%c", Cardp2, symbolp2); /*printing the chosen card of p2*/
    }
    else
    {
        printf("  ");
    }
    for (int i = 0; i < 48; i++)
    {
        printf(" ");
    }
    if (flagp4)
    {
        printf("%d%c", Cardp4, symbolp4); /*printing the chosen card of p4*/
    }
    else
    {
        printf("   ");
    }
    printf("|P4\n");
    for (int i = 0; i < 7; i++)
    {
        printf("      |");
        for (int j = 0; j < 53; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("      |");
    for (int j = 0; j < 26; j++)
    {
        printf(" ");
    }
    if (flagp1)
    {
        printf("%d%c", (cards[0][index] % 11) + 1, Symbol(cards, 0, index)); /*printing the chosen card of p1*/
    }
    for (int j = 0; j < 24; j++)
    {
        printf(" ");
    }
    printf("  |    set team 2 : %d\n      ", setTeam2); /*printing the sets of team 2*/
    for (int i = 0; i < 55; i++)
    {
        printf("-");
    }
    printf("    team 2 : %d\n", winnerTeam2); /*printing the points of team 2*/
    for (int i = 0; i < 33; i++)
    {
        printf(" ");
    }
    printf("P1");
    for (int i = 0; i < 25; i++)
    {
        printf(" ");
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\nsymbol |");
    for (int i = 0; i < 11; i++)
    {
        symbolflag = 1;
        for (int j = 0; j < 11; j++)
        {
            if (i == Index[j]) /*printing - instead of cards symbols which have chosen before */
            {
                printf("-  | ");
                symbolflag = 0;
                break;
            }
        }
        if (symbolflag) /*printing the symbol of the rest cards*/
        {
            printf("%c  | ", Symbol(cards, 0, i));
        }
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\nnumber |");
    for (int i = 0; i < 11; i++)
    {
        numberflag = 1;
        for (int j = 0; j < 11; j++)
        {
            if (i == Index[j]) /*printing 0 instead of cards numbers which have chosen before */
            {
                printf("0  | ");
                numberflag = 0;
                break;
            }
        }
        if (numberflag) /*printing the number of the rest cards*/
        {
            int subMultiple = (cards[0][i] % 11) + 1;
            if (subMultiple / 10 > 0) /*our number have 2 digits so we print with one less space*/
            {
                printf("%d | ", subMultiple);
            }
            else
            {
                printf("%d  | ", subMultiple);
            }
        }
    }
    printf("\n        ");
    for (int i = 0; i < 54; i++)
    {
        printf("-");
    }
    printf("\n         ");
    for (int i = 0; i < 11; i++)
    {
        printf("%d    ", i);
    }
    printf("\n\n\nplease press enter\n");
    getchar();
}
void checkingP1(int cards[4][11], int firstSymbol, int *index, int Index[11], int *flagp1, int flagcheck3)
{
    int situation1, situation2, situation3, flag2, flag3, index1;
    printf("\n\nwhich card do you want to play with : ");
    scanf("%d", &index1);
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 11; i++)
        {
            while (index1 == Index[i]) /*which means p1 has played this card before*/
            {
                printf("\nyou have played this cart before.");
                printf("\n\nwhich card do you want to play with : ");
                scanf("%d", &index1);
                situation2 = 0;
            }
        }
        while (index1 < 0 || index1 > 11) /*p1 should choose an index between 0 an 11*/
        {
            printf("\nwrong index");
            printf("\n\nwhich card do you ant to play with : ");
            scanf("%d", &index1);
            situation1 = 0;
        }
        if (flagcheck3)
        {
            for (int i = 0; i < 11; i++)
            {
                if (cards[0][i] < 44)
                {
                    if ((cards[0][i] >= symbolReverse(firstSymbol)) && (cards[0][i] < symbolReverse(firstSymbol) + 11))
                    { /*p1 should play with the first symbol except the time he does not have the card with first symbol*/
                        if (Symbol(cards, 0, index1) != firstSymbol)
                        {
                            printf("\nyou cant play this card now");
                            printf("\n\nplay another card : ");
                            scanf("%d", &index1);
                            situation3 = 0;
                        }
                    }
                }
            }
        }
        if (situation1 == 1 && situation2 == 1 && situation3 == 1)
        {
            break;
        }
    }
    *flagp1 = 1;
    *index = index1;
}
void rounds(int cards[4][11], char bakhshname2, int *setTeam1, int *setTeam2)
{
    int remain, subMultiple, Cardp2 = 0, Cardp3 = 0, Cardp4 = 0, winnerPerson = 1, winnerTeam1 = 0,
                             winnerTeam2 = 0, index, m = 0;
    int Index[11] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    char symbolp2 = ' ', symbolp3 = ' ', symbolp4 = ' ', firstSymbol, space;
    for (int i = 0; i < 11; i++)
    {
        int flagp1 = 0, flagp4 = 0, flagp2 = 0, flagp3 = 0, flagcheck3 = 1;
        zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                   flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
        if (winnerPerson == 1)
        { /*we call the players in order : p1, p2, p3, p4*/
            flagcheck3 = 0;
            checkingP1(cards, firstSymbol, &index, Index, &flagp1, flagcheck3);
            Index[m] = index;
            m++;
            firstSymbol = Symbol(cards, 0, index);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            scanf("%c", &space);
            player2(cards, bakhshname2, index, &symbolp2, &Cardp2, Cardp4, Cardp3, cards[0][index], firstSymbol, &flagp2);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player3(cards, bakhshname2, index, &symbolp3, &Cardp3, Cardp4, Cardp2, cards[0][index], firstSymbol, &flagp3);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player4(cards, bakhshname2, index, &symbolp4, &Cardp4, Cardp3, Cardp2, cards[0][index], firstSymbol, &flagp4);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
        }
        if (winnerPerson == 2)
        { /*we call the players in order : p2, p3, p4, p1*/
            startingByPlayer2(cards, bakhshname2, index, &symbolp2, &Cardp2, &firstSymbol, &flagp2);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player3(cards, bakhshname2, index, &symbolp3, &Cardp3, Cardp4, Cardp2, cards[0][index], firstSymbol, &flagp3);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player4(cards, bakhshname2, index, &symbolp4, &Cardp4, Cardp3, Cardp2, cards[0][index], firstSymbol, &flagp4);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            checkingP1(cards, firstSymbol, &index, Index, &flagp1, flagcheck3);
            Index[m] = index;
            m++;
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            scanf("%c", &space);
        }
        if (winnerPerson == 3)
        { /*we call the players in order : p3, p4, p1, p2*/
            startingByPlayer3(cards, bakhshname2, index, &symbolp3, &Cardp3, &firstSymbol, &flagp3);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player4(cards, bakhshname2, index, &symbolp4, &Cardp4, Cardp3, Cardp2, cards[0][index], firstSymbol, &flagp4);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            checkingP1(cards, firstSymbol, &index, Index, &flagp1, flagcheck3);
            Index[m] = index;
            m++;
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            scanf("%c", &space);
            player2(cards, bakhshname2, index, &symbolp2, &Cardp2, Cardp4, Cardp3, cards[0][index], firstSymbol, &flagp2);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
        }
        if (winnerPerson == 4)
        { /*we call the players in order : p4, p1, p2, p3*/
            startingByPlayer4(cards, bakhshname2, index, &symbolp4, &Cardp4, &firstSymbol, &flagp4);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            checkingP1(cards, firstSymbol, &index, Index, &flagp1, flagcheck3);
            Index[m] = index;
            m++;
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            scanf("%c", &space);
            player2(cards, bakhshname2, index, &symbolp2, &Cardp2, Cardp4, Cardp3, cards[0][index], firstSymbol, &flagp2);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
            player3(cards, bakhshname2, index, &symbolp3, &Cardp3, Cardp4, Cardp2, cards[0][index], firstSymbol, &flagp3);
            zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                       flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
        }
        judge((cards[0][index] % 11) + 1, Cardp2, Cardp3, Cardp4, Symbol(cards, 0, index), symbolp2, symbolp3,
              symbolp4, bakhshname2, &winnerPerson, firstSymbol); /*it determines the winner of each round*/
        if (winnerPerson == 1 || winnerPerson == 3)/*p1 and p3 are in team1*/
        {
            winnerTeam1++;
            printf("\nteam 1 won this round!!! :)\n");
        }
        else /*p1 and p3 are in team1*/
        {
            winnerTeam2++;
            printf("\nteam 2 won this round!!! :)\n");
        }
        if (winnerTeam1 == 6)/*the round is over*/
        {
            if (winnerTeam1 == 6 && winnerTeam2 == 0)
            {
                *setTeam1 = *setTeam1 + 2;
                printf("\nteam 1 won the set with two point.\n");
                winnerTeam1 = 0; /*the round will be begin from the start*/
                winnerTeam2 = 0;
                zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                           flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
                break;
            }
            else
            {
                *setTeam1 = *setTeam1 + 1;
                printf("\nteam 1 won the set.\n");
                winnerTeam1 = 0; /*the round will be begin from the start*/
                winnerTeam2 = 0;
                zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                           flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
                break;
            }
        }
        else if (winnerTeam2 == 6)/*the round is over*/
        {
            if (winnerTeam2 == 6 && winnerTeam1 == 0)
            {
                *setTeam2 = *setTeam2 + 2;
                printf("\nteam 2 won the set.\n");
                winnerTeam1 = 0; /*the round will be begin from the start*/
                winnerTeam2 = 0;
                zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                           flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
                break;
            }
            else
            {
                *setTeam2 = *setTeam2 + 1;
                printf("\nteam 2 won the set.\n");
                winnerTeam1 = 0; /*the round will be begin from the start*/
                winnerTeam2 = 0;
                zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                           flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
                break;
            }
        }
        zaminBazi2(cards, winnerTeam1, winnerTeam2, Cardp2, Cardp3, Cardp4, symbolp2, symbolp3, symbolp4, index, flagp1,
                   flagp4, flagp3, flagp2, Index, *setTeam1, *setTeam2);
        cards[0][index] = 44; /*so we cant choose the same card for the next time*/
    }
}
void judge(int cardp1, int cardp2, int cardp3, int cardp4, char symbolp1, char symbolp2, char symbolp3,
           char symbolp4, int bakhshname, int *winnerPerson, char firstsymbol) /*for determining the winner*/
{
    int winner, i;
    int judgeCards[4] = {0, 0, 0, 0};
    if (symbolp1 == bakhshname || symbolp2 == bakhshname || symbolp3 == bakhshname || symbolp4 == bakhshname)
    { /*if there is at least on bakhshname symbol on the ground, find the biggest number and he is the winner*/
        if (symbolp1 == bakhshname)
        {
            judgeCards[0] = cardp1;
        }
        if (symbolp2 == bakhshname)
        {
            judgeCards[1] = cardp2;
        }
        if (symbolp3 == bakhshname)
        {
            judgeCards[2] = cardp3;
        }
        if (symbolp4 == bakhshname)
        {
            judgeCards[3] = cardp4;
        }
        findGreatest(judgeCards, 4, &i);
        printf("\n\n%d\n\n", i);
        if (i == 0)
        {
            winner = 1;
        }
        if (i == 1)
        {
            winner = 2;
        }
        if (i == 2)
        {
            winner = 3;
        }
        if (i == 3)
        {
            winner = 4;
        }
    }
    else
    { /*if there isnt any bakhshname symbol on the ground find the biggest first symbol number and he is the winner*/
        if (symbolp1 == firstsymbol)
        {
            judgeCards[0] = cardp1;
        }
        if (symbolp2 == firstsymbol)
        {
            judgeCards[1] = cardp2;
        }
        if (symbolp3 == firstsymbol)
        {
            judgeCards[2] = cardp3;
        }
        if (symbolp4 == firstsymbol)
        {
            judgeCards[3] = cardp4;
        }
        findGreatest(judgeCards, 4, &i);
        ;
        if (i == 0)
        {
            winner = 1;
        }
        if (i == 1)
        {
            winner = 2;
        }
        if (i == 2)
        {
            winner = 3;
        }
        if (i == 3)
        {
            winner = 4;
        }
    }
    *winnerPerson = winner; /*put winner in winnerperson*/
}