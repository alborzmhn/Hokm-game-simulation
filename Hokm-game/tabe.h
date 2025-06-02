char numToSymbol(int number);
void judge(int cardp1, int cardp2, int cardp3, int cardp4, char symbolp1, char symbolp2, char symbolp3, 
char symbolp4,int bakhshname, int *winnerPerson, char firstsymbol);
void player4(int cards[4][11], char bakhshname2, int index, char *symbolp4, int *Cardp4, char firstSymbol, int *flagp4);
void player3(int cards[4][11], char bakhshname2, int index, char *symbolp3, int *Cardp3, char firstSymbol, int *flagp3);
void zaminBazi(int cards[4][11], int card[44], int flag2);
void rounds(int cards[4][11], char bakhshname2);
int symbolReverse(char symbol);
char Symbol(int cards[4][11],int player, int index);
int findGreatest(int arr[11], int arrSize, int *iGreatest);
char Bakhshname(char *pointer);
void startingByPlayer2(int cards[4][11],char bakhshname2,int index,char *symbolp2,int *Cardp2,char *firstSymbol,int *flagp2);
void startingByPlayer3(int cards[4][11],char bakhshname2,int index,char *symbolp3,int *Cardp3,char *firstSymbol,int *flagp3);
void startingByPlayer4(int cards[4][11],char bakhshname2,int index,char *symbolp4,int *Cardp4,char *firstSymbol,int *flagp4);
void zaminBazi2(int cards[4][11], int winnerTeam1, int winnerTeam2, int Cardp2, int Cardp3, int Cardp4,
char symbolp2, char symbolp3, char symbolp4, int index, int flagp1,int flagp4,int flagp3,int flagp2, int Index[11]);
int findSmallest(int arr[11], int arrSize, int *iSmallest);
void player2(int cards[4][11], char bakhshname2, int index, char *symbolp2, int *Cardp2, char firstSymbol, int *flagp2);
void checkingP1(int cards[4][11], int firstSymbol, int *index, int Index[11], int *flagp1, int flagcheck3);