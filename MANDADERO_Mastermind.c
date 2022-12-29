/*Clarissa Mandadero S12 MP*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//gets random numbers
void RandomGenerator(int *number1, int *number2, int *number3, int *number4)
{
    srand(time(NULL));
    *number1 = 1 + rand() % (10 - 1); //min + rand() % (max - min) since secret code can only be from numbers 1 - 9
    *number2 = 1 + rand() % (10 - 1);
    *number3 = 1 + rand() % (10 - 1);
    *number4 = 1 + rand() % (10 - 1);
}


//displays main screen
void MainScreen(int *MainScreenChoice)
{
    system("cls");
    printf("\n==============");
    printf("  MASTERMIND");
    printf("  ==============");
    do
        {
            printf("\n\n              [1] New Game\n              [2] Settings\n              [3] Exit\n");
            printf("\n              Enter input: ");
            scanf("%d", &*MainScreenChoice);
        }
        while (*MainScreenChoice < 1 || *MainScreenChoice > 3); //checks validity of MainScreenChoice
}


//displays settings
void Settings(int *NoOfPlayers, int *NoOfGuesses)
{
    int SettingsChoice = 1;
    
    while(SettingsChoice)
    {//while
        do
        {//do
            system("cls");
            printf("\n==============");
            printf("  SETTINGS");
            printf("  ==============");
            printf("\n\n    The number of players is set to %d.\n", *NoOfPlayers);
            printf("    The number of guesses is set to %d.", *NoOfGuesses);
            printf("\n\n       [1] Change No. of Players");
            printf("\n       [2] Change No. of Guesses");
            printf("\n       [3] Go back to main screen\n");
            printf("\n             Enter input: ");
            scanf("%d", &SettingsChoice);
        }//do
        while(SettingsChoice < 1 || SettingsChoice > 3);//checks validity of SettingsChoice
        
            switch (SettingsChoice)
            {//switch
                case 1:
                    system("cls");
                    printf("\n============");
                    printf(" PLAYER SETTINGS");
                    printf(" ============");
                    printf("\n\nEnter number of players: ");
                    scanf("%d", &*NoOfPlayers);
                    break;
                
                case 2:
                    system("cls");
                    printf("\n===========");
                    printf(" GUESSES SETTINGS");
                    printf(" ===========");
                    printf("\n\nEnter number of guesses: ");
                    scanf("%d", &*NoOfGuesses);
                    break;
                
                case 3:
                    SettingsChoice = 0;//if 3 is entered by the user, then the loop stops and it goes back to main screen
            }//switch
    }//while
}


//used to know the current number of player playing in the game
int getNoOfPlayer(int Players, int j)
{
    int NoOfPlayer;
    NoOfPlayer = j % Players;
    if(NoOfPlayer == 0)
        return Players;
    else
        return NoOfPlayer;
}


//used to know the number of attempt the current player is playing
int getGuessesMade(int j, int NoOfPlayers)
{
    int GuessesMade = 0;
    if(j % NoOfPlayers == 0)
        GuessesMade = j / NoOfPlayers;
   else
        GuessesMade = j / NoOfPlayers + 1;
    return GuessesMade;
}


//correct number and correct position
int getScoreA(int guess1, int guess2, int guess3, int guess4, int number1, int number2, int number3, int number4)
{
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, scoreA;
    
    if(guess1 == number1)
        s1 = 1;
    if(guess2 == number2)
        s2 = 1;
    if(guess3 == number3)
        s3 = 1;
    if(guess4 == number4)
        s4 = 1;
    scoreA = s1 + s2 + s3 + s4;
    return scoreA;
}


//correct number but wrong position
int getScoreB(int guess1, int guess2, int guess3, int guess4, int number1, int number2, int number3, int number4)
{
    
    int scoreB = 0;
            
        if(guess1 == number1 || guess1 == number2 || guess1 == number3 || guess1 == number4)
            scoreB++;
        if(guess1 == number1)//if the guess equates to the number then the number becomes zero to avoid repetition of score
            number1 = 0;
        else if(guess1 == number2)
            number2 = 0;
        else if(guess1 == number3)
            number3 = 0;
        else if(guess1 == number4)
            number4 = 0;
        
    
        if(guess2 == number1 || guess2 == number2 || guess2 == number3 || guess2 == number4)
            scoreB++;
        if(guess2 == number1)
            number1 = 0;
        else if(guess2 == number2)
            number2 = 0;
        else if(guess2 == number3)
            number3 = 0;
        else if(guess2 == number4)
            number4 = 0;
        
    
        if(guess3 == number1 || guess3 == number2 || guess3 == number3 || guess3 == number4)
            scoreB++;
        if(guess3 == number1)
            number1 = 0;
        else if(guess3 == number2)
            number2 = 0;
        else if(guess3 == number3)
            number3 = 0;
        else if(guess3 == number4)
            number4 = 0;
        
    
        if(guess4 == number1 || guess4 == number2 || guess4 == number3 || guess4 == number4)
            scoreB++;
        if(guess4 == number1)
            number1 = 0;
        else if(guess4 == number2)
            number2 = 0;
        else if(guess4 == number3)
            number3 = 0;
        else if(guess4 == number4)
            number4 = 0;
    
    
        return scoreB;
}


//displays result of the game whether there's a winner or it's a draw
void ResultScreen(int scoreA, int number1, int number2, int number3, int number4, int NoOfPlayer, int GuessesMade)
{
    int ExitChoice;
    system("cls");
    if(scoreA == 4)//if the secret code is guessed by a player
    {
        printf("\nCONGRATULATIONS!\nPlayer %d, you won!\n\n", NoOfPlayer);
        printf("Number of guesses: %d\n", GuessesMade);
    }
    
    else//if the number of guesses is maximized and the secret code is not guessed by any player
    {
        printf("\n         DRAW!\n");
    }
    printf("The secret code is %d%d%d%d.\n\n", number1, number2, number3, number4);
    printf("==============================\n");
    printf("\nPress any number to continue\n");
    scanf("%d", &ExitChoice);
}


//displays game
void Game(int *NoOfGuesses, int *NoOfPlayers, int *guess1, int *guess2, int *guess3, int *guess4, int number1, int number2, int number3, int number4)
{
    int j = 1, guess, scoreA = 0, scoreB = 0, GuessesMade = 0;
    system("cls");
    printf("\n==============");
    printf("  MAIN GAME");
    printf("  ==============");
    printf("\n\nEnter 4 numbers from 1 to 9.\nPress [0] to reveal the secret code.\n");//instructions only
  
    
    while(j <= *NoOfGuesses * *NoOfPlayers && scoreA != 4)//loop will only stop once someone wins or when the number of players and guesses is maximized
    {//while
        printf("\n============");
        printf(" Player %d Guess %d", getNoOfPlayer(*NoOfPlayers, j), getGuessesMade(j, *NoOfPlayers));
        printf(" ============\n");
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        *guess4 = guess % 10;
        *guess3 = guess % 100 / 10;
        *guess2 = guess % 1000 / 100;
        *guess1 = guess / 1000;
        
        while(*guess1 < 1 || *guess1 > 9 || *guess2 < 1 || *guess2 > 9 || *guess3 < 1 || *guess3 > 9 || *guess4 < 1 || *guess4 > 9) //checks validity of guess
        {
            if(guess == 0) // cheat code: shows the secret number in the middle of the game
            {
                printf("\n============");
                printf(" Player %d Guess %d", getNoOfPlayer(*NoOfPlayers, j), getGuessesMade(j, *NoOfPlayers));
                printf(" ============\n");
                printf("\nThe secret code is %d%d%d%d.\n", number1, number2, number3, number4);
                printf("\nEnter your guess: ");
                scanf("%d", &guess);
                *guess4 = guess % 10;
                *guess3 = guess % 100 / 10;
                *guess2 = guess % 1000 / 100;
                *guess1 = guess / 1000;
            }
            else
            {
                printf("\n============");
                printf(" Player %d Guess %d", getNoOfPlayer(*NoOfPlayers, j), getGuessesMade(j, *NoOfPlayers));
                printf(" ============\n");
                printf("\nEnter your guess: ");
                scanf("%d", &guess);
                *guess4 = guess % 10;
                *guess3 = guess % 100 / 10;
                *guess2 = guess % 1000 / 100;
                *guess1 = guess / 1000;
            }
        }
        
        scoreA = getScoreA(*guess1, *guess2, *guess3, *guess4, number1, number2, number3, number4);
        scoreB = getScoreB(*guess1, *guess2, *guess3, *guess4, number1, number2, number3, number4) - scoreA;
        
        printf("Number of Exact Matches: %d\nNumber of Correct Digits: %d\n", scoreA, scoreB);
            j++;
    }//while
    
    
    GuessesMade = getGuessesMade(j - 1, *NoOfPlayers);
    ResultScreen(scoreA, number1, number2, number3, number4, getNoOfPlayer(*NoOfPlayers, j - 1), GuessesMade);
}



int main()
{//main
    int NoOfGuesses = 10, NoOfPlayers = 2, MainScreenChoice;
    int number1, number2, number3, number4;
    int guess1, guess2, guess3, guess4;
    
    do
    {//do
    MainScreen(&MainScreenChoice);
    switch(MainScreenChoice)
       {//switch
           case 1:
               RandomGenerator(&number1, &number2, &number3, &number4);
               Game(&NoOfGuesses, &NoOfPlayers, &guess1, &guess2, &guess3, &guess4, number1, number2, number3, number4);
                    break;
           case 2:
               Settings(&NoOfPlayers, &NoOfGuesses);
               break;
           case 3:
               system("cls");
               printf("Exited game\n");
       }//switch
    }//do
    while(MainScreenChoice != 3);//loop will only terminate once the user chooses exit
    return 0;
}//main

