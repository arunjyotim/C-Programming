int main()
{
    //declare variables
    int My_dice1;
    int My_dice2;
    int Your_dice1;
    int Your_dice2;
    int My_result;
    int Your_result;
    char quit;


    srand((unsigned)time(NULL));    //See random function with current time


    //Introductory message explaining what the program does and how the game is played.
    printf_s("This program will simulate the dice game Fifty which requires 2 players with each player taking turns to roll 2 die.\n");
    printf_s("The goal of Fifty is to be the first player to reach 50 points.  You get points by rolling doubles.\n");
    printf_s("All doubles except 3s and 6s score 5 points.  Double 6s are worth 25 points and double 3s wipe out the players entire score\n");
    printf_s("and the player must start again at 0.  Non-double rolls are 0 points.\n");
    printf_s("Press q to quit.\n");


    //Ask the players to roll the dice (not sure how to implement this element)


    while (quit != 'q' || My_result < 50 || Your_result < 50)
    {
        printf("Player 1's turn.\n");
        int My_dice1 = rand() % 6 + 1;
        printf("My first throw is %d\n", My_dice1);
        int My_dice2 = rand() % 6 + 1;
        printf("My second throw is %d\n", My_dice2);
        if (My_dice1 == My_dice2)
        {


        }
    }
    


    printf("Player 2's turn\n");
    int Your_dice1 = rand() % 6 + 1;
    printf("My first throw is %d\n", Your_dice1);
    int Your_dice2 = rand() % 6 + 1;
    printf("My second throw is %d\n", Your_dice2);


    My_result = My_dice1 + My_dice2;
    Your_result = Your_dice1 + Your_dice2;


    return 0;
}