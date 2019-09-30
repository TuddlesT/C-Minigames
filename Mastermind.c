#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int guess[4];
int answer[4];
int exactMatch;
int partialMatch;
int turns = 13;
char yesno;
char playAgain;
void input();
void individualInput(int peg);
void checkAnswers();
void randomizeAnswer();
char yorn();
char getInput();
int main() {
    turns = 13;
    randomizeAnswer();
    while (answer[0] == answer[1] || answer[0] == answer[2] || answer[0] == answer[3] || answer[1] == answer[2] || answer[1] == answer[3] || answer[2] == answer[3]) {
        randomizeAnswer();
    }

    input();
    
    return 0;
}
void input() {
    turns--;
    if (turns == 0)
    {
        printf("You have ran out of turns! The correct answer was %d%d%d%d. Would you like to play again? (Y/N)\n",answer[0], answer[1], answer[2], answer[3]);
        playAgain = yorn ();
        if (playAgain == 'Y')
        {
            main();
        }
    }
    else
    {
        printf("You have %d turns left\n", turns);
        for (int i = 1; i < 5; i++)
        {
            printf("Enter your guess for peg %d\n", i);
            individualInput(i);
        }
        printf("Your guess is \"%d%d%d%d\", correct? (Y/N)\n", guess[0], guess[1], guess[2], guess[3]);
        yesno = yorn();
        if (yesno == 'Y')
        {
            checkAnswers();
        }
        else if(yesno == 'N')
        {
            turns++;
            input();
        }
    }
}
void individualInput(int peg) {
    int inputGuess = getInput() - '0';
    if (inputGuess > 0 && inputGuess < 7)
    {
        guess[peg-1] = inputGuess;
    }
    else
    {
        printf("Please enter a value from 1 to 6\n");
        fflush(stdin);
        individualInput(peg);
    }
}
void checkAnswers() {
    exactMatch = 0;
    partialMatch = 0;
    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == answer[i])
        {
            exactMatch++;
        }
        else if (guess[i] == answer[0] || guess[i] == answer[1] || guess[i] == answer[2] || guess[i] == answer[3])
        {
            partialMatch++;
        }
    }
    if (exactMatch != 4)
    {
        printf("You got %d exact matches and %d partial matches\n", exactMatch, partialMatch);
        input();
    }
    else
    {
        printf("Cogratulations! You figured out the correct combination. Would you like to play again? (Y/N)");
        playAgain = getchar();
        getchar();
        if(playAgain == 'Y')
        {
            main();
        }
    }
}
void randomizeAnswer() {
    srand (time(NULL));
    for (int i = 0; i < 4; i++)
    {
        answer[i] = rand()%6 + 1;
    }
}
char yorn() {
    char i = getInput();
    if (i == 'Y' || i == 'N')
    {
        return i;
    }
    else
    {
        printf("Please enter Y or N\n");
        return yorn();
    }
}
char getInput() {
    char i = getchar();
    while (i == '\n')
    {
        i = getchar();
    }
    char a = getchar();
    if (a == '\n')
    {
        return i;
    }
    else
    {
        while (i != '\n')
        {
            i = getchar();
        }
        return 0;
    } 
}