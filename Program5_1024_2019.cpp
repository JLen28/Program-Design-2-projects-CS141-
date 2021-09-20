//  prog5_1024.cpp
//     Text version of the game 1024, a variant of 2048 available online at:
//        http://gabrielecirulli.github.io/2048/
//     Object of game is to combine number tiles with the same value, accumulating
//     points as the game progresses, to try and create the tile with the value 1024.
//     Each move consists of sliding pieces to the left, up, right or down.
/*  Running program looks like:
 
     Dale Reed
     UIC CS 141, Spring 2019
     Welcome to 1024.
     This program is based off of Gabriele Cirulli's game online at
     bit.ly/great2048
 
     For each move enter a direction as a letter key, as follows:
         W
       A S D
     where A=left,W=up, D=right and S=down.
 
     After a move, when two identical valued tiles come together they
     join to become a new single tile with the value of the sum of the
     two originals. This value gets added to the score.  On each move
     one new randomly chosen value of 2 or 4 is placed in a random open
     square.  User input of x exits the game.
 
     Game ends when you reach 1024.
 
     Score: 0
	 .     4     .     .

	 .     .     .     .

	 .     .     4     .

	 .     .     .     .
 
     1. Your move: a
 
     Score: 0
	 4     .     .     .

	 .     .     .     .

	 4     .     .     .

	 .     .     2     .
 
     2. Your move: a
     .
     .
     .
*/
/***
 * Mallavarapu:
 * 1) The header with the student name is missing.
 * 2) The comments at the functions should explain the parameters as well.
 * 3) The else-if ladder in the main can be broken down into more functional parts.
 * 4) Inconsistent blank lines.
 * ***/
#include <iostream>     // For cin, cout, endl
#include <iomanip>      // used for setting output field size using setw
#include <cstdlib>      // For rand()
using namespace std;    // So we don't need std:: in front of every cin, cout, and endl

const int MaxBoardSize = 12;          // Max number of squares per side
const int MaxTileStartValue = 1024;   // Max tile value to start out on a 4x4 board


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to 1024. \n"
         << "  \n"
         << "For each move enter a direction as a letter key, as follows: \n"
		 << "    W    \n"
		 << "  A S D  \n"
		 << "where A=left,W=up, D=right and S=down. \n"
		 << "  \n"
		 << "After a move, when two identical valued tiles come together they    \n"
		 << "join to become a new single tile with the value of the sum of the   \n"
		 << "two originals. This value gets added to the score.  On each move    \n"
		 << "one new randomly chosen value of 2 or 4 is placed in a random open  \n"
		 << "square.  User input of x exits the game.                            \n"
		 << "  \n"
         << "Game ends when you reach 1024."
         << "  \n";
}//end displayInstructions()


//--------------------------------------------------------------------
// Place a randomly selected 2 or 4 into a random open square on
// the board.
void placeRandomPiece( int board[], int squaresPerSide)
{
    // Randomly choose a piece to be placed (2 or 4)
    int pieceToPlace = 2;
    if( rand()%2 == 1) {
        pieceToPlace = 4;
    }
    
    // Find an unoccupied square that currently has a 0
    int index;
    do {
        index = rand() % (squaresPerSide*squaresPerSide);
    }while( board[ index] != 0);
    
    // board at position index is blank, so place piece there
    board[ index] = pieceToPlace;
}//end placeRandomPiece()
//--------------------------------------------------------------------
//function that will display the board...
void displayAsciiBoard(int board[],int squaresPerSide, int score)
{
     cout << "Score: " << score << endl;
     board[MaxBoardSize * MaxBoardSize];
     for(int i = 0; i < squaresPerSide * squaresPerSide; i++)
     {
         if(i % squaresPerSide == 0 && i != 0)
         {
             cout << endl << endl;
         }
         if(board[i] == 0)
         {
             cout << "     .";
         }
         else
         {
             cout << setw(6) << board[i];
         }
     }
    cout << endl << endl;
}// end dislplayAsciiBoard()



//---------------------------------------------------------------------------------------
int main()
{
    bool marked = true;
    int score = 0;
    int squaresPerSide = 4;        // User will enter this value.  Set default to 4
    int currentBoardSize = squaresPerSide * squaresPerSide;
    int board[ MaxBoardSize * MaxBoardSize];          // space for largest possible board
    int previousBoard[ MaxBoardSize * MaxBoardSize];  // space for copy of board, used to see
    int selectedSpace = 0;
                                                      //    if a move changed the board.
    int maxTileValue = MaxTileStartValue;  // 1024 for 4x4 board, 2048 for 5x5, 4096 for 6x6, etc.
    char userInput = ' ';                  // handles user input
    int move = 1;                          // user move counter
    
    displayInstructions();
    // Get the board size, 
    //create and initialize the board with zeroes...                         
    for( int j = 0; j < squaresPerSide * squaresPerSide; j++){
        board[j] = 0;} // initializes the board with values of zero to clear garbage values...
    placeRandomPiece(board, squaresPerSide); // initial random piece placed....
    placeRandomPiece(board, squaresPerSide); // second random piece placed....
    // Infinite loop to run program until user selects exit, board is full, or max tile value is reached
    while( true)
    {
        marked = true;
        // Display the text-based board
        displayAsciiBoard( board, squaresPerSide, score);
        // Make a copy of the board.  After we then attempt a move, the copy will be used to
        // verify that the board changed, which only then allows randomly placing an additional
        // piece on the board and updating the move number.
        for(int i = 0; i < squaresPerSide * squaresPerSide; i++){
            previousBoard[i] = board[i];
        } // end for loop that populates backup board...

        
        // Prompt for and handle user input
        cout << move << ". Your move: ";
        cin >> userInput;
        userInput = toupper(userInput); // userInput made uppercase 
        cout << endl;
            if(userInput == 'X')
            {
                    cout << "Thanks for playing. Exiting program... \n\n";
                    exit( 0);
                    break;
            }
			      //...
            else if(userInput == 'W')
            {
                
                for( int col = 0; col < squaresPerSide; col++) // combining...
                {
                    for(int row = 0; row < squaresPerSide; row++)
                    {
                        int index = (row * squaresPerSide) + col;
                        if(board[index] != 0){
                            for(int i = row + 1; i < squaresPerSide; i++)
                            {
                             int nextNonZero = (i * squaresPerSide) + col;
                             if(board[nextNonZero] != 0 && board[index] == board[nextNonZero])
                             {
                                board[index] = board[index] + board[nextNonZero];
                                board[nextNonZero] = 0;
                                score = score + board[index] + board[nextNonZero];
                                break;
                              }
                             if(board[nextNonZero] != 0 && board[nextNonZero] != board[index] )
                             {
                                 break;                                
                             }
                             
                            }                        
                        }
                    }
                    for(int row2 = 0; row2 < squaresPerSide; row2++) // moving...
                    {
                        int index2 = (row2 * squaresPerSide) + col;
                        if(board[index2] == 0){
                            for(int j = row2 + 1; j < squaresPerSide; j++)                            
                            {
                                int nextNonZero2 =( j * squaresPerSide) + col;
                                if(board[nextNonZero2] != 0 )
                                {
                                    board[index2] = board[nextNonZero2];
                                    board[nextNonZero2] = 0;
                                    break;
                                }
                                
                            }
                       
                        }
                    }
                
                }
            }
            else if(userInput == 'S')
            {
                
                for( int col = 0; col < squaresPerSide; col++) // combining...
                {
                    for(int row = squaresPerSide - 1; row >= 0; row--)
                    {
                        int index = (row * squaresPerSide) + col;
                        for(int i = row - 1; i >= 0; i--)
                            {
                             int nextNonZero = (i * squaresPerSide) + col;
                             if(board[nextNonZero] != 0 && board[index] == board[nextNonZero])
                             {
                                board[index] = board[index] + board[nextNonZero];
                                board[nextNonZero] = 0;
                                score = score + board[index] + board[nextNonZero];
                                break;
                              }
                             if(board[nextNonZero] != 0 && board[nextNonZero] != board[index] )
                             {
                                 break;                                
                             }
                             
                            }            
                    }
                    for(int row2 = squaresPerSide - 1; row2 >= 0; row2--) // moving...
                    {
                        int index2 = (row2 * squaresPerSide) + col;
                        if(board[index2] == 0){
                            for(int j = row2 - 1; j >= 0; j--)                            
                            {
                                int nextNonZero2 =( j * squaresPerSide) + col;
                                if(board[nextNonZero2] != 0 )
                                {
                                    board[index2] = board[nextNonZero2];
                                    board[nextNonZero2] = 0;
                                    break;
                                }
                                
                            }
                       
                        }
                    }
                
                }
            }
            else if(userInput == 'D')
                
            {
                for( int row = 0; row < squaresPerSide; row++) // combining...
                {
                    for(int col = squaresPerSide - 1; col >= 0; col--)
                    {
                        int index = (row * squaresPerSide) + col;
                        if(board[index] != 0)
                        {
                            
                        
                    
                        for(int i = col - 1; i >= 0; i--)
                            {
                             int nextNonZero = (row * squaresPerSide) + i;
                             if(board[nextNonZero] != 0 && board[index] == board[nextNonZero])
                             {
                                board[index] = board[index] + board[nextNonZero];
                                board[nextNonZero] = 0;
                                score = score + board[index] + board[nextNonZero];
                                break;
                              }
                             if(board[nextNonZero] != 0 && board[nextNonZero] != board[index] )
                             {
                                 break;                                
                             }
                             
                            }
                        }
                    }
                    for(int col2 = squaresPerSide - 1; col2 >= 0; col2--) // moving...
                    {
                        int index2 = (row * squaresPerSide) + col2;
                        if(board[index2] == 0){
                            for(int j = col2 - 1; j >= 0; j--)                            
                            {
                                int nextNonZero2 =( row * squaresPerSide) + j;
                                if(board[nextNonZero2] != 0 )
                                {
                                    board[index2] = board[nextNonZero2];
                                    board[nextNonZero2] = 0;
                                    break;
                                }
                                
                            }
                       
                        }
                    }
                
                }
            }
        else if(userInput == 'A')
                
            {
                for( int row = 0; row < squaresPerSide; row++) // combining...
                {
                    for(int col = 0; col < squaresPerSide; col++)
                    {
                        int index = (row * squaresPerSide) + col;
                        if(board[index] != 0)
                        {
                        for(int i = col + 1; i < squaresPerSide; i++)
                            {
                             int nextNonZero = (row * squaresPerSide) + i;
                             if(board[nextNonZero] != 0 && board[index] == board[nextNonZero])
                             {
                                board[index] = board[index] + board[nextNonZero];
                                board[nextNonZero] = 0;
                                score = score + board[index] + board[nextNonZero];
                                 break;
                              }
                             if(board[nextNonZero] != 0 && board[nextNonZero] != board[index] )
                             {
                                 break;                                
                             }
                             
                            }
                        }
                    }
                    for(int col2 = 0; col2 < squaresPerSide; col2++) // moving...
                    {
                        int index2 = (row * squaresPerSide) + col2;
                        if(board[index2] == 0){
                            for(int j = col2 + 1; j < squaresPerSide; j++)                            
                            {
                                int nextNonZero2 =( row * squaresPerSide) + j;
                                if(board[nextNonZero2] != 0 )
                                {
                                    board[index2] = board[nextNonZero2];
                                    board[nextNonZero2] = 0;
                                    break;
                                }
                                
                            }
                       
                        }
                    }
                
                }
            }
            else if( userInput == 'P')
          {
                marked = false;
                int selectedSpace = 0;
                int selectedValue = 0;
                cin >> selectedSpace >> selectedValue;
                for(int i = 0; i < squaresPerSide * squaresPerSide; i++)
                {
                    if(i == selectedSpace)
                    {
                        board[i] = selectedValue;
                    }
                }
              
          }
        
          else if(userInput == 'R')
          {
              cout << "Resetting board" << endl << endl;
              cout << "Enter the size board you want, between 4 and 12: ";
              cin >> squaresPerSide;
              cout << endl;
                  //and set the max tile value depending on board size
              maxTileValue = 1;
              for(int j = 0; j < 10 + squaresPerSide - 4; j++)
              {
                  maxTileValue = maxTileValue * 2;
              }

              cout  << "Game ends when you reach " << maxTileValue << "." << endl;
              for(int i = 0; i < squaresPerSide * squaresPerSide; i++)
              {
                  board[i] = 0;
              }
              placeRandomPiece(board,squaresPerSide);
              placeRandomPiece(board,squaresPerSide);
              move = 1;
              score = 0;
              marked = false;
              
          }

        

                           

                   
                            
                         
                
           else
            {
                    cout << "Invalid input, please retry.";
                    continue;
                    break;
                  }//end switch( userInput)
        int equalSide = 0;
        int moveCounter = 0;
        
        for(int i = 0; i< squaresPerSide * squaresPerSide; i++)
        {
            if(board[i] != previousBoard[i] && marked == true)
            {
                placeRandomPiece(board,squaresPerSide);
                move++;
                break;      
            }
        }
        
        
        for(int i = 0; i < currentBoardSize; i++)
        {
           if(marked == true){
                if (board[i] == 0){
                   moveCounter++;
                }
                if(i % squaresPerSide == 0)
                {
                  if(board[i] == board[i + 1] || board[i] == board[i + squaresPerSide] || board[i] == board[i - squaresPerSide])
                  {
                       moveCounter++; 
                  }
                }                    
                else if(i % squaresPerSide == squaresPerSide - 1)
                {
                 if( board[i] == board[i - 1] || board[i] == board[i + squaresPerSide] || board[i] == board[i - squaresPerSide])
                 {
                   moveCounter++;   
                 }
                }
                else if(board[i] == board[i + 1] || board[i] == board[i-1] || board[i] == board[i + squaresPerSide] || board[i] == board[i - squaresPerSide])
                {
                    moveCounter++;
                }
                if(board[i] == maxTileValue)
                {
                    cout << "Congratulations!  You made it to "<< maxTileValue << " !!!";
                    displayAsciiBoard(board,squaresPerSide, score);
                    return 0;
                }
            }
            
        }
       
        if(marked == true && moveCounter == 0 )
        {
            cout << "No more available moves.  Game is over." << endl;
            displayAsciiBoard(board,squaresPerSide,score);
                return 0;
        }
        
        
        




                   
        // If the move resulted in pieces changing position, then it was a valid move
        // so place a new random piece (2 or 4) in a random open square and update the move number.
        // ...
        
        // See if we're done.  If so, display the final board and break.
        // ...

        //system("clear");   // Clear the screen in UNIX / Codio.  Should be "cls" on windows.
                             //     May not work in default Mac Xcode configuration, or some other environments.
    }//end while( true)

    return 0;
}//end main()