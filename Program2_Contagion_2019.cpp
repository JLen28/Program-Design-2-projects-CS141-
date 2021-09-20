
/* Prog2Contagion.cpp

   Program #2: Play the game of Contagion against another person
               This is a variation of Ataxx, a version of which can
               be played online at: http://www.classikgames.com/ataxx.html
   Class: CS 141
   Date: 2/11/2019
   Author: Joseph Lenaghan

   Grading Rubric:
     55% Passes Codio run-time tests (some cases below are split into multiple tests)
          5 Handles both upper and lower case user input
          5 Handles making adjacent move for each player
         10 Handles making jump move for each player
          5 Handles pass move 
          2 Error message and retry when source position does not belong to player
          2 Error message and retry when destination position is not empty
          6 Error message and retry when destination is not one or two squares away
            in horizontal, vertical, or diagonal line
         15 Flips opponent pieces adjacent to move destination
          5 When board is filled correctly identifies winner and exits program

     45% Programming Style:
         10 Meaningful Identifier Names.
         10 Comments, header, and meaningful variable names
         10 Functional Decomposition 
         10 Appropriate data and control structures
          5 Code Layout
*/
#include <iostream>
#include <cstdlib>   // for exit() and abs()
using namespace std;

// The 25 board position variables may be global variables, but no other variables may be global.
char  p1, p2, p3, p4, p5,
      p6, p7, p8, p9,p10,
     p11,p12,p13,p14,p15,
     p16,p17,p18,p19,p20,
     p21,p22,p23,p24,p25;


//-----------------------------------------------------------------------------------------
// Display the game instructions
void displayInstructions()
{
    cout << " \n"
         << "Welcome to the 2-player game of Contagion, where the point of the game is    \n"
         << "to capture as much of the board as possible.  On each move you must enter \n"
         << "the row and column position of one of your current pieces (e.g. a1) and   \n"
         << "the row and column of an empty destination, which must be one or two      \n"
         << "squares away.  Moves can be made horizontally, vertically, or diagonally. \n"
         << " \n"
         << "If the destination is one square away, then an additional piece for you   \n"
         << "is placed in the destination square.  If the destination is two squares   \n"
         << "away (a jump move), then the original piece is moved to that destination. \n"
         << "jumping over a single square or any player's piece.                       \n"
         << " \n"
         << "After a piece has been moved, all opponent pieces adjacent to the         \n"
         << "destination are changed to match the piece of the user making the move.   \n"
         << "Player X moves first.     \n"
         << " \n"
         << "A valid first move, for instance, could be: a1 a2  which since it is just \n"
         << "one square away, would put an additional X on square a2.  Alternatively   \n"
         << "if the first move is:  a1 c3  then since it is two squares away, the piece\n"
         << "currently at a1 would be moved to destination c3.                         \n"
         << endl;
}


//-----------------------------------------------------------------------------------------
// Display the board, using the global board variables
// For reference here are the board row, col and board variable values:
//       1  2  3  4  5
//    ----------------
//  A |  1  2  3  4  5
//  B |  6  7  8  9 10
//  C | 11 12 13 14 15
//  D | 16 17 18 19 20
//  E | 21 22 23 24 25
//
void displayBoard()
{
    cout << "    1   2   3   4   5  \n"
         << "  ---------------------\n"
         << "A | " <<  p1 << " | " <<  p2 << " | " <<  p3 << " | " <<  p4 << " | " <<  p5 << " | A \n"
         << "  |---|---|---|---|---| \n"
         << "B | " <<  p6 << " | " <<  p7 << " | " <<  p8 << " | " <<  p9 << " | " << p10 << " | B \n"
         << "  |---|---|---|---|---| \n"
         << "C | " << p11 << " | " << p12 << " | " << p13 << " | " << p14 << " | " << p15 << " | C \n"
         << "  |---|---|---|---|---| \n"
         << "D | " << p16 << " | " << p17 << " | " << p18 << " | " << p19 << " | " << p20 << " | D \n"
         << "  |---|---|---|---|---| \n"
         << "E | " << p21 << " | " << p22 << " | " << p23 << " | " << p24 << " | " << p25 << " | E \n"
         << "  ---------------------\n"
         << "    1   2   3   4   5  \n"
         << endl;
}

// *** Yuwei: add header for this function to explain its purpose
 char getCurrentLoc(char row, int pos){

   char currentLocation = ' '; // variable to return result

    // row A 1 through 5
    if (row == 'A') {
      switch( pos){
        case 1: currentLocation = p1; break;
        case 2: currentLocation = p2; break;
        case 3: currentLocation = p3; break;
        case 4: currentLocation = p4; break;
        case 5: currentLocation = p5; break;
      }
    }  // row B 1 through 5
    else if (row == 'B') {
      switch( pos){
        case 1: currentLocation = p6; break;
        case 2: currentLocation = p7; break;
        case 3: currentLocation = p8; break;
        case 4: currentLocation = p9; break;
        case 5: currentLocation = p10; break;
      }
    }  // row C 1 through 5
    else if (row == 'C') {
      switch( pos){
        case 1: currentLocation = p11; break;
        case 2: currentLocation = p12; break;
        case 3: currentLocation = p13; break;
        case 4: currentLocation = p14; break;
        case 5: currentLocation = p15; break;
      }
    } // row D 1 through 5
    else if (row == 'D') {
      switch( pos){
        case 1: currentLocation = p16; break;
        case 2: currentLocation = p17; break;
        case 3: currentLocation = p18; break;
        case 4: currentLocation = p19; break;
        case 5: currentLocation = p20; break;
      }
    } // row E 1 through 5
    else if (row == 'E') {
      switch( pos){
        case 1: currentLocation = p21; break;
        case 2: currentLocation = p22; break;
        case 3: currentLocation = p23; break;
        case 4: currentLocation = p24; break;
        case 5: currentLocation = p25; break;
        
      }
    }

    return currentLocation;
  }
// *** Yuwei: add header for this function to explain its purpose
void setNewLoc(char row, int pos, char updatedVal)
{
    // row A 1 through 5
  if (row == 'A') {
      switch( pos){
        case 1: p1 = updatedVal; break;
        case 2: p2 = updatedVal; break;
        case 3: p3 = updatedVal; break;
        case 4: p4 = updatedVal; break;
        case 5: p5 = updatedVal; break;
      }
    }  // row B 1 through 5
   else if (row == 'B') {
      switch( pos){
        case 1: p6 = updatedVal; break;
        case 2: p7 = updatedVal; break;
        case 3: p8 = updatedVal; break;
        case 4: p9 = updatedVal; break;
        case 5: p10 = updatedVal; break;
      }
    }  // row C 1 through 5
   else if (row == 'C') {
      switch( pos){
        case 1: p11 = updatedVal; break;
        case 2: p12 = updatedVal; break;
        case 3: p13 = updatedVal; break;
        case 4: p14 = updatedVal; break;
        case 5: p15 = updatedVal; break;
      }
    } // row D 1 through 5
   else if (row == 'D') {
      switch( pos){
        case 1: p16 = updatedVal; break;
        case 2: p17 = updatedVal; break;
        case 3: p18 = updatedVal; break;
        case 4: p19 = updatedVal; break;
        case 5: p20 = updatedVal; break;
      }
    } // row E 1 through 5
   else if (row == 'E') {
      switch( pos){
        case 1: p21 = updatedVal; break;
        case 2: p22 = updatedVal; break;
        case 3: p23 = updatedVal; break;
        case 4: p24 = updatedVal; break;
        case 5: p25 = updatedVal; break;
        
      }
    }
  
}
// *** Yuwei: add header for this function to explain its purpose  
int countTheX(){
   int globalXScore = 0;
   if ( p1 == 'X'){++globalXScore;}
   if ( p2 == 'X'){++globalXScore;}
   if ( p3 == 'X'){++globalXScore;} 
   if ( p5 == 'X'){++globalXScore;}
   if ( p6 == 'X'){++globalXScore;}
   if ( p7 == 'X'){++globalXScore;}
   if ( p8 == 'X'){++globalXScore;}
   if ( p9 == 'X'){++globalXScore;}
   if ( p10 == 'X'){++globalXScore;}
   if ( p11 == 'X'){++globalXScore;}
   if ( p12 == 'X'){++globalXScore;}
   if ( p13 == 'X'){++globalXScore;}
   if ( p14 == 'X'){++globalXScore;}
   if ( p15 == 'X'){++globalXScore;}
   if ( p16 == 'X'){++globalXScore;} 
   if ( p17 == 'X'){++globalXScore;}
   if ( p18 == 'X'){++globalXScore;}
   if ( p19 == 'X'){++globalXScore;} 
   if ( p20 == 'X'){++globalXScore;}
   if ( p21 == 'X'){++globalXScore;}
   if ( p22 == 'X'){++globalXScore;}
   if ( p23 == 'X'){++globalXScore;}
   if ( p24 == 'X'){++globalXScore;}
   if ( p25 == 'X'){++globalXScore;}
   return globalXScore;
}

// *** Yuwei: add header for this function to explain its purpose   
int countTheO(){
   int globalOScore = 0;
   if ( p1 == 'O'){++globalOScore;}
   if ( p2 == 'O'){++globalOScore;} 
   if ( p3 == 'O'){++globalOScore;} 
   if ( p4 == 'O'){++globalOScore;}
   if ( p5 == 'O'){++globalOScore;}
   if ( p6 == 'O'){++globalOScore;}
   if ( p7 == 'O'){++globalOScore;}
   if ( p8 == 'O'){++globalOScore;}
   if ( p9 == 'O'){++globalOScore;}
   if ( p10 == 'O'){++globalOScore;}
   if ( p11 == 'O'){++globalOScore;}
   if ( p12 == 'O'){++globalOScore;}
   if ( p13 == 'O'){++globalOScore;}
   if ( p14 == 'O'){++globalOScore;}
   if ( p15 == 'O'){++globalOScore;}
   if ( p16 == 'O'){++globalOScore;} 
   if ( p17 == 'O'){++globalOScore;}
   if ( p18 == 'O'){++globalOScore;}
   if ( p19 == 'O'){++globalOScore;} 
   if ( p20 == 'O'){++globalOScore;}
   if ( p21 == 'O'){++globalOScore;}
   if ( p22 == 'O'){++globalOScore;}
   if ( p23 == 'O'){++globalOScore;}
   if ( p24 == 'O'){++globalOScore;}
   if ( p25 == 'O'){++globalOScore;}

   return globalOScore;
   }

// *** Yuwei: add header for this function to explain its purpose
// 
void flip(char destRow, int destCol , int whosMove){
 if( whosMove == 0){
  if(getCurrentLoc(destRow + 1, destCol + 0) == 'X'){
    setNewLoc(destRow + 1,destCol + 0, 'O');
  }
  if(getCurrentLoc(destRow + 0, destCol + 1)== 'X'){
    setNewLoc(destRow + 0, destCol + 1, 'O');
  }
  if(getCurrentLoc(destRow -1, destCol + 0) == 'X'){
    setNewLoc(destRow - 1, destCol + 0, 'O' );
  }
  if(getCurrentLoc(destRow + 0, destCol - 1) == 'X'){
    setNewLoc(destRow + 0, destCol - 1, 'O');
  }
  if(getCurrentLoc(destRow + 1, destCol + 1) == 'X'){
    setNewLoc(destRow + 1, destCol + 1, 'O' );
  }
  if(getCurrentLoc(destRow + 1, destCol -1) == 'X'){
    setNewLoc(destRow + 1, destCol - 1, 'O');
  }
  if(getCurrentLoc(destRow -1, destCol + 1) == 'X'){
    setNewLoc(destRow - 1, destCol + 1, 'O');
  }
  if(getCurrentLoc(destRow - 1, destCol - 1) == 'X'){
    setNewLoc(destRow - 1, destCol - 1, 'O');
  }
 }
 if(whosMove == 1){ 
  if(getCurrentLoc(destRow + 1, destCol + 0) == 'O'){
    setNewLoc(destRow + 1,destCol + 0, 'X');
  }
  if(getCurrentLoc(destRow + 0, destCol + 1)== 'O'){
    setNewLoc(destRow + 0, destCol + 1, 'X');
  }
  if(getCurrentLoc(destRow -1, destCol + 0) == 'O'){
    setNewLoc(destRow - 1, destCol + 0, 'X' );
  }
  if(getCurrentLoc(destRow + 0, destCol - 1) == 'O'){
    setNewLoc(destRow + 0, destCol - 1, 'X');
  }
  if(getCurrentLoc(destRow + 1, destCol + 1) == 'O'){
    setNewLoc(destRow + 1, destCol + 1, 'X' );
  }
  if(getCurrentLoc(destRow + 1, destCol -1) == 'O'){
    setNewLoc(destRow + 1, destCol - 1, 'X');
  }
  if(getCurrentLoc(destRow -1, destCol + 1) == 'O'){
    setNewLoc(destRow - 1, destCol + 1, 'X');
  }
  if(getCurrentLoc(destRow - 1, destCol - 1) == 'O'){
    setNewLoc(destRow - 1, destCol - 1, 'X');
  }
 }
  


}

//-----------------------------------------------------------------------------------------
int main() {
    // Set initial values for the global board variables to all be blank
    p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16=p17=p18=p19=p20=p21=p22=p23=p24=p25= ' ';
    // Set corner starting positions
    p1=p25= 'X';
    p5=p21= 'O';

    // Variables to store user input for current row and column, and destination row and column
    char currentRow;
    int currentCol;
    char destRow;
    int destCol;
    int currentMoveNumber = 1;
    int whosMove = 0;
    int xScore = countTheX();
    int oScore = countTheO();
    
    cout << "Welcome to the 2-player game of Contagion. \n"
         << endl;

    // Main loop to play game
    while( true) {
    
        // Display board and handle first character of user input
        displayBoard();
        if (currentMoveNumber % 2 != 0){
          cout << currentMoveNumber << ". " << "Enter 'i' for instructions, 'x' to exit, or move for X: ";
          whosMove = 1;
          ++currentMoveNumber;
        }
        else if(currentMoveNumber % 2 == 0 ){
          cout << currentMoveNumber << ". " << "Enter 'i' for instructions, 'x' to exit, or move for O: ";
          whosMove = 0;
          ++currentMoveNumber;
          
        }     
        cin >> currentRow;
        currentRow = toupper(currentRow);
        cout << endl;
        // Check to see if user input was 'i' for instructions or 'x' to exit
        if( currentRow == 'I') {
            displayInstructions();
            continue;       // Loop back up to retry move
        } // if statement that checks for 'I'
        else if( currentRow == 'X') {
            displayBoard();         
            if ( xScore > oScore ){
             cout << endl << "X Wins!" << endl;
              }
            else if ( oScore > xScore ){
              cout << endl << "O Wins!" << endl;
              }
            else if ( oScore == xScore ){
             cout << endl << "Tie game." << endl;
             }
             cout << endl;
             cout << "Exiting program... \n"
                 << endl;        
 
            break;  // Break out of enclosing loop, to exit the game. 
        }// end of the else if statement containing 'X'
         if (currentRow == 'P' || currentRow == 'p'){
          
        }// pass move handled
        else {
               cin >> currentCol; // current col read
               cin >> destRow; // destination row read
               cin >> destCol; // destination column
               currentRow = toupper(currentRow); // uppercase current row
               destRow = toupper(destRow); // uppercase destination row
               char currentLoc = getCurrentLoc(currentRow,currentCol); // call to function stored as current location
               char destLoc = getCurrentLoc(destRow, destCol); // call to function stored as destined location
               int rowDiff = abs(currentRow - destRow);
               int colDiff = abs(currentCol - destCol);
               // Error messages checked first to prevent placement of piece regardless of error...
               if (                (currentLoc == ' ') ||
                  (whosMove == 1 && currentLoc == 'O') ||
                  (whosMove == 0 && currentLoc == 'X')
                  ){ 
              
                            cout << "*** Invalid move.  Current piece must belong to you. Please retry." << endl;
                            currentMoveNumber = currentMoveNumber - 1;
                            continue;                                           
              } // if statement checks to see whos turn it is and which pieces can move accordingly...
              if( destLoc != ' '){
                
                            cout << "*** Invalid move.  Destination must be empty. Please retry." << endl;
                            currentMoveNumber = currentMoveNumber - 1;
                            continue;                                                          
              }// destination must be empty....
              if( (rowDiff == 0 && colDiff == 1) ||
                   (rowDiff == 1 && colDiff == 0) ||
                   (rowDiff == 1 && colDiff == 1) 
                   ){
                            setNewLoc(destRow,destCol,currentLoc);
                            flip(destRow,destCol,whosMove);
               } // if statement typical adjacent move....
               else if( (rowDiff == 0 && colDiff == 2) ||
                        (rowDiff == 2 && colDiff == 0) ||
                        (rowDiff == 2 && colDiff == 2) 
                        ){
                            setNewLoc(destRow,destCol,currentLoc);
                            setNewLoc(currentRow,currentCol,' ');
                            flip(destRow,destCol,whosMove);
              } // else if statement for jump moves....
              else { 
                          cout << "*** Invalid move.  A move must be one or two squares away. Please retry." << endl;
                          currentMoveNumber = currentMoveNumber - 1;               
                          continue;             
              }// move is too many squares away....
        } // end the else statement
      
      //clunky way of checking if the board is filled
          if((p1 != ' ') && 
            (p2 != ' ' ) &&
            (p3 != ' ' ) &&
            (p4 != ' ' ) &&
            (p5 != ' ' ) &&
            (p6 != ' ' ) &&
            (p7 != ' ' ) &&       
            (p8 != ' ' ) &&
            (p9 != ' ' ) &&
            (p10 != ' ') &&
            (p11 != ' ') &&
            (p12 != ' ') &&
            (p13 != ' ') &&
            (p14 != ' ') &&
            (p15 != ' ') &&
            (p16 != ' ') &&
            (p17 != ' ') &&
            (p18 != ' ') &&
            (p19 != ' ') &&
            (p20 != ' ') &&
            (p21 != ' ') &&
            (p22 != ' ') &&
            (p23 != ' ') &&
            (p24 != ' ') &&
            (p25 != ' ')
            ){
              displayBoard();
              int endXScore = countTheX();
              int endOScore = countTheO();
            
              if ( endXScore > endOScore )
              {
              cout << endl << "X Wins!" << endl;
              }
              else if ( endOScore > endXScore )
              {
              cout << endl << "O Wins!" << endl;
              }
              else if ( endOScore == endXScore ){
              cout << endl << "Tie game." << endl;
              }
              cout << endl;
              cout << "Exiting program... \n"
                   << endl;
              break;
    
  }           
    } //end while( true)
  
       

// *** Yuwei: no need to have so many empty lines within your code  
  



    return 0;
} // end main()
