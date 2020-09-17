#include <iostream>
#include <ctime>
using namespace std;



//"CLEAR SCREEN": pushes out old text by looping endline ( DEFAULT = 20 lines ) 
/* 

    TODO: 
    + add to seperate class for other projects

*/
void Clrscrn( int LineCount = 50 )
{

    for( int x = 0 ; x < LineCount ; x++ ) 
    { cout << endl; }
    //hello

}



//PRINT the INTRO MESSAGE and ART
/* 

    TODO: 
    + create ASCII art

*/
void PrintIntro( int Difficulty ) 
{

    //INTRO ASCII ART
    // * ASCII art goes here *

    //INTRO TEXT
    cout
        << "LEVEL: " << Difficulty
        << endl 
        << "You are a veteran treasure hunter trying to decipher an ancient door that guards a mysterious room..." 
        << endl
        << "To break into the hidden chamber and unlock it's secrets you must enter the correct code..." 
        << endl << endl;
    ;

}



//MAIN GAME function
bool PlayGame( int Difficulty )
{

    //CLEAR text
    Clrscrn(5);

    //WELCOME MESSAGE
    PrintIntro( Difficulty );

    //CODE and CLUES DECLARATION and INITIALIZATION
    int CodeNumLimit = Difficulty + 2;

    const int CodeNumA = 1 + rand() % CodeNumLimit;
    const int CodeNumB = 1 + rand() % CodeNumLimit;
    const int CodeNumC = 1 + rand() % CodeNumLimit;

    const int CodeSum = CodeNumA + CodeNumB + CodeNumC;
    const int CodeProduct = CodeNumA * CodeNumB * CodeNumC;

    //PRINT CLUES
    cout 
        << "After studying and working out all the clues you arrive to the following information:"
        << endl 
        << "+ The code is composed of 3 numbers"
        << endl
        << "+ Adding all the numbers together gives you:  " << CodeSum
        << endl
        << "+ Multiplying all the numbers together gives you:  " << CodeProduct
        << endl << endl
    ;

    //DECLARE and GET values for PLAYER INPUT variables
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //PRINT what the program got from the PLAYER GUESS
    cout
        << "You enter the following numbers into the door: " << GuessA << " " << GuessB << " " << GuessC
        << endl << endl
    ;

    //CHECK to see if PLAYER GUESS is correct
    if( GuessSum == CodeSum && GuessProduct == CodeProduct ) 
    {

        cout 
            << "That was CORRECT! The door opens and you are now free to go deeper into the ruins..."
            << endl
        ;

        return true;

    } 
    else 
    {

        cout
            << "Nothing happens... That wasn't correct... Try again..."
            << endl
        ;

        return false;

    }

}



int main()
{

    //GENERATE SEED
    srand( time( NULL ) );

    //CLEAR out ALL old text 
    Clrscrn();

    //START level and END level DIFFUCLTY INITIALIZATION
    int LevelDifficulty = 1;
    const int MaxLevel = 7;

    //PLAY the GAME until all levels are completed
    while( LevelDifficulty <= MaxLevel )
    {

        //PLAY one LEVEL of game
        bool bLeveleComplete = PlayGame( LevelDifficulty );

        //CLEAR ERRORS and BUFFER
        cin.clear();
        cin.ignore();

        //CHECK if the LEVEL is COMPLETE
        if( bLeveleComplete )
        { ++LevelDifficulty; }

    }

    //CLEAR text
    Clrscrn(5);

    //GAME END MESSAGE
    cout 
        << "    *** CONGRATULATIONS! *** "
        << endl << endl
        << "You unlocked all the secret chambers... You truly are a master Treasure Hunter!"
        << endl
        << "Now get that treasure and get out of there!"
        << endl << endl
    ;

    return 0;

}
