  /* pegJump.cpp

   Author: Husham Alammar, and Joseph Lenaghan
   Program: #3, Peg Jump
   CS 141, Spring 2019
 
   Description:
          This program represents a peg jumping puzzle  A
        move is made by a peg jumping over another peg into an empty
        spot, where the jumped peg is then removed from the board. The
        game ends when there are no more valid moves to make. The object
        is to eliminate as many pegs as possible.
				
		Sample output:
		
			Welcome to the peg jump puzzle! 
			Enter '-' to exit, or '+' for instructions. 

							A B C         
							D E F         
					G H I J K L M     
					N O P * Q R S     
					T U V W X Y Z     
							1 2 3         
							4 5 6         

			1. Enter the peg to move: +

			Welcome to the peg jump puzzle. The board starts out with a 
			single blank position, represented by the '*'.  To make a 
			move, select the letter of a peg.  A peg must be able to 
			jump over an adjacent peg into a blank position for a move 
			to be valid.  The jumped peg is then removed from the board. 
			The game is over when there are no valid moves left. At any 
			point enter '-' to exit, or '+' for instructions. 

			1. Enter the peg to move: E

							A B C         
							D * F         
					G H I * K L M     
					N O P E Q R S     
					T U V W X Y Z     
							1 2 3         
							4 5 6         

			2. Enter the peg to move: w

							A B C         
							D * F         
					G H I W K L M     
					N O P * Q R S     
					T U V * X Y Z     
							1 2 3         
							4 5 6         

			3. Enter the peg to move: 5

							A B C         
							D * F         
					G H I W K L M     
					N O P * Q R S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			4. Enter the peg to move: 2
			*** Invalid move, please retry. *** 
			4. Enter the peg to move: r

							A B C         
							D * F         
					G H I W K L M     
					N O P R * * S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			5. Enter the peg to move: R

							* * *         
							* 1 *         
					* * * * * * *     
					* * * + * * *     
					* * * * * * *     
							* 2 *         
							* * *         

			There is more than one possible move.  Which move do you want? 1

							A B C         
							D R F         
					G H I * K L M     
					N O P * * * S     
					T U V 5 X Y Z     
							1 * 3         
							4 * 6         

			6. Enter the peg to move: -

			Exiting...

			27 pieces remaining. Ouch!
 */

/***
 * Mallavarapu:
 * 1) Some functions are missing comments
 * 2) Comments for functions should explain the parameters and return type
 * ***/


#include <iostream>
#include <cctype>     // For toupper()
using namespace std;


//-------------------------------------------------------------------------------------
void displayInstructions()
{
    cout << endl
         << "Welcome to the peg jump puzzle. The board starts out with a \n"
         << "single blank position, represented by the '*'.  To make a \n"
         << "move, select the letter of a peg.  A peg must be able to \n"
         << "jump over an adjacent peg into a blank position for a move \n"
         << "to be valid.  The jumped peg is then removed from the board. \n"
         << "The game is over when there are no valid moves left. At any \n"
         << "point enter '-' to exit, or '+' for instructions. \n"
         << endl;
}

// function displays board...
void displayBoard(char board[], int pegsInRow, int maxNumberPegs){
  // This will loop checking every peg.
  for ( int i = 0+pegsInRow; i < maxNumberPegs-pegsInRow; i++){
    // The if-else statements check if its a '#' then it will change it to a space, if not then it a peg and and will print out it's charecter.
    if(board[i] == '#'){
      cout << "  ";
    }
    else{
      cout << board[i] << " ";
    }
    // When it hits the end of each row then it will end line and start printing in the next line
    if((i+1) % pegsInRow == 0){
      cout << endl;
    }
  }
}// end displayBoard function...

// user current location returned...
int getLocation(char board[], char userChar){
  
  //This loop will check where the user input char is and return its location integer
  for(int i = 0; i < 121; i++){
    if(board[i] == userChar){
      return i;
    }
  }
}// end getLocation...

// This function will look at every side and update the possible moves/counter as necessary
void lookAround(char board[], int currentLocation, int possibleDest[4], int middlePeg[4] , int& possibleCount){
  
  possibleCount = 0;
  
  // The if-else statements check surrounding possible moves in order of top, left, right, and bottom.
  // When the surrounding space is free and the middle space is not free space then it will go through the statement.
  if((board[currentLocation-22] == '*') && (board[currentLocation-11] != '*')){
    // The array possibleDest will update with the location of the free space. We use possibleCount to go through the possibleDest array.
    possibleDest[possibleCount] = currentLocation-22;
    // Just as possibleDest, middlePeg will do the same towards the peg in between user's input peg and the potential jump free space.
    middlePeg[possibleCount] = currentLocation-11;
    // possibleCount will increments, this is used to both go through the array and check possible outcome can come depending on what the count will be (will be used in availableMoves function as well).
    possibleCount++;
  }
  if((board[currentLocation-2] == '*') && (board[currentLocation-1] != '*')){
    possibleDest[possibleCount] = currentLocation-2;
    middlePeg[possibleCount] = currentLocation-1;
    possibleCount++;
  }
  if((board[currentLocation+2] == '*') && (board[currentLocation+1] != '*')){
    possibleDest[possibleCount] = currentLocation+2;
    middlePeg[possibleCount] = currentLocation+1;
    possibleCount++;
  }
  if((board[currentLocation+22] == '*') && (board[currentLocation+11] != '*')){
    possibleDest[possibleCount] = currentLocation+22;
    middlePeg[possibleCount] = currentLocation+11;
    possibleCount++;
  }
} // end of lookAround function...

// Functions check if there are any available moves left....
void availableMoves(char board[], int possibleDest[4], int middlePeg[4], int& possibleCount, int& endLoop, int pegsInRow, int maxNumberPegs){
  // This for loop will look through every peg and check if every peg has any possible moves, endLoop will be the variable to decide if the while loop in main() should stop (break).
  for(int k = 0+pegsInRow; k < maxNumberPegs-pegsInRow; k++){
    if((board[k] != '#') && (board[k] != '*')){
      lookAround(board, k, possibleDest, middlePeg, possibleCount);
      
      // When the current peg has more than one possible move then endLoop wont end the while loop and it will stop the for loop since there is a peg with possible moves.
      if(possibleCount > 0){
        endLoop = 0;
        break;
      }
      // If none the pegs in the board have a possible move then endLoop will end the while loop.
      else{
        endLoop = 1;
      }
    }
  }
} // end function to check moves...

// possible jumps are detected then jump if the requirements are met...
void possibleJump(char board[], char userChar, int& round, int& endLoop, int pegsInRow, int maxNumberPegs){
  // The first 3 variables are required to check possible surrounding moves for the peg's current location.
  int possibleDest[4] = {};
  int middlePeg[4] = {};
  int possibleCount;
  
  // This variable will call the function and will look into where the location of the user's input and store it into the variable as a current location.
  int currentLocation = getLocation(board, userChar);
  
  //This will call the function to look at the surrounding pegs and check if there's any possible jumps.
  lookAround(board, currentLocation, possibleDest, middlePeg, possibleCount);
  
  // checks to see if error message triggered if there are no possible moves...
  if(possibleCount == 0){
    cout << "*** Invalid move, please retry. ***" << endl;
  }
  // else if there is one possible move then it will jump to it.
  else if(possibleCount == 1){
    // The first value of possibleDest will always the location of the only possible move and it's value will be changed to the user's input.
    board[possibleDest[0]] = userChar;
    // The peg between the current location and the destination will be changed to free space.
    board[middlePeg[0]] = '*';
    // The previous location (and also called the current location) will be changed to free space.
    board[currentLocation] = '*';

  } // end else if..
  
  // If its not just 1 possible move then the following will trigger (meaning its more than one possible move).
  else{
    // Variable will be assigned to handle where the user wants to move its peg to.
    int move = 0;
    
    // The following loop will display a board specifically made to see where the possible moves are.
    for ( int i = 0+pegsInRow; i < maxNumberPegs-pegsInRow; i++){
      // All '#' chars will be spaces when displayed.
      if(board[i] == '#'){
        cout << "  ";
      }
      // The user's current location will be changed to a '+' to indicate the user's input peg.
      else if(board[i] == userChar){
        cout << "+ ";
      }
      // The following 4 if-else statements will check if i's location is the same as the possible move's location is, and will print a number from the 1st possible move to the last one. 
      else if(i == possibleDest[0]){
        cout << "1 "; 
      }
      else if(i == possibleDest[1]){
        cout << "2 ";
      }
      else if(i == possibleDest[2]){
        cout << "3 ";
      }
      else if(i == possibleDest[3]){
        cout << "4 ";
      }
      // else if it's none of the given if statements then it be displayed as '*'.
      else{
        cout << "* ";
      }
      
      // This works the same as displayBoard function's code
      if((i+1) % pegsInRow == 0){
        cout << endl;
      }
    }// end the for statement...
    
    //possible move detected... initiates an option to select moves... then it stores the integer given in moves...
    cout << "There is more than one possible move.  Which move do you want? ";
    cin >> move;
    cout << endl;
    
    // The following basically works as the same as the previous valid jump 3-line codes, but using the given move variable this time to change the right board pegs.
    board[possibleDest[move - 1]] = userChar;
    board[middlePeg[move - 1]] = '*';
    board[currentLocation] = '*';
  } // end else statement...
  // This will check if there are more than 0 possible moves.
  if(possibleCount > 0){
    
    //After "jumping" it will display the board and increment the round.
    displayBoard(board, pegsInRow, maxNumberPegs);
    round++;
    
    // This will a function to check if there are any moves available at all, and if there isn't then the while loop will break.
    availableMoves(board, possibleDest, middlePeg, possibleCount, endLoop, pegsInRow, maxNumberPegs);
  }// end if...
  
} // end possible jumps function...


//-------------------------------------------------------------------------------------
int main()
{
  //Variable declarations
  char board[] = {
          '#','#','#','#','#','#','#','#','#','#','#',
          '#','#','#','#','#','#','#','#','#','#','#',
          '#','#','#','#','A','B','C','#','#','#','#',
          '#','#','#','#','D','E','F','#','#','#','#',
          '#','#','G','H','I','J','K','L','M','#','#',
          '#','#','N','O','P','*','Q','R','S','#','#',
          '#','#','T','U','V','W','X','Y','Z','#','#',
          '#','#','#','#','1','2','3','#','#','#','#',
          '#','#','#','#','4','5','6','#','#','#','#',
          '#','#','#','#','#','#','#','#','#','#','#',
          '#','#','#','#','#','#','#','#','#','#','#'
        };

  cout << "Welcome to the peg jump puzzle! \n"
       << "Enter '-' to exit, or '+' for instructions. "
       << endl;
  
  // The following variables are initialized.
  int pegsInRow = 11;
  int maxNumberPegs = 121;
  char userInput = ' ';
  int moveNumber = 1;
  int numberOfPeg = 0;
  int endLoop = 0;
  
  // initial board displayed..
  displayBoard(board, pegsInRow, maxNumberPegs);
    
  // Main loop to play the game
  while(true){
    
    // Prompt for and get move
    cout << moveNumber << ". " << "Enter the peg to move: ";
    cin >> userInput;
    userInput = toupper(userInput);
    
    // Check for '-' to exit, and '+' for displaying instructions
    if (userInput == '+'){
      
      displayInstructions();
      continue;
    }
    else if (userInput == '-'){
      
      cout << "Exiting..." << endl << endl;
      break;
    }
    // If its none of the above then it's probably a peg, the following will operate to validate and give the proper operation depending on the user input.
    else{
      
      // This function will be called to check if its a possible jump and then jump, ask for which possible destination to jump from, or invalid input.
      possibleJump(board, userInput, moveNumber, endLoop, pegsInRow, maxNumberPegs);
      
      // After the function's operation is done if there aren't any other possible move from any of the current pegs then it will end the while loop (break from it).
      if(endLoop == 1){
        break;
      }
    } // end of else statement...

  }// end of while...
  
 // current number of pegs checked and increments...
  for(int i = 0+pegsInRow; i< maxNumberPegs-pegsInRow; i++){
    if((board[i] != '#') && (board[i] != '*')){
      numberOfPeg++;
    }
  } // end peg check...

  // Display appropriate message depending on number of remaining pegs
  if(numberOfPeg >= 5){
    cout << numberOfPeg << " pieces remaining. Ouch!" << endl << endl;
  } 
  else if(numberOfPeg == 4){
    cout << numberOfPeg << " pieces remaining. Needs Improvement." << endl << endl;
  }
  else if(numberOfPeg == 3){
    cout << numberOfPeg << " pieces remaining. OK." << endl << endl;
  }
  else if(numberOfPeg == 2){
    cout << numberOfPeg << " pieces remaining. Good!" << endl << endl;
  }
  else{
    cout << numberOfPeg << " pieces remaining. Excellent!" << endl << endl;
  } // end error checks...

  return 0; // keep C++ happy...
}//end main()