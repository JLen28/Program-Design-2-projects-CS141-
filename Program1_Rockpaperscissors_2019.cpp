/* ------------------------------------------------
   prog1RockPaperScissors.cpp
 
   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141
   Author: Joseph  Lenaghan
	 
	 See the program description page on the course web site at bit.ly/cs141
	 Within Codio you can run the solution by doing the following steps:
   1. Select the Tools / Terminal menu option
	 2. Within the terminal window, type in:  ./solution

   Grading Rubric:
		 55 Execution points
						  Option 1: (Computer always chooses R) and:
					 2		 User input of X immediately exits program
					 3		 User input of x (lower case) immediately exits program
				  10		 Program handles both lower and upper case user input (e.g. 'r' and 'R'); also
					          move number increments each move
				  15		 Score updates correctly for all user inputs: r, p, s
						  Option 2: Computer's move is random and:
					 7		 Predetermined input sequence correctly leads to computer win
				   8		 Predetermined input sequence correctly leads to human win
		         Option 3: 
           2     Correctly displays and updates the graphical score
		       8     Correctly displays and updates the graphical score, with assessment results hidden

		 45 Programming Style (Given only if program runs substantially correctly)
					10 Meaningful identifier names
					10 Comments: Has header.  Comments on each block of code.
					15 Appropriate data and control structures.  Code duplication is avoided.
					10 Code Layout: Appropriate indentation and blank lines.
 
   Having sample program output is not required within this header of your program, though it is helpful.
	 
	 
*/

#include <iostream>    // For cin and cout
#include <cstdlib>     // For rand()
using namespace std;


//-----------------------------------------------------------------------------------------
int main()
{
    // Display Instructions
    cout << "CS 141 Program #1: Rock/Paper/Scissors                                \n"
         << endl
         << "Welcome to the game of Rock/Paper/Scissors where you play against     \n"
         << "the computer.  On each move the computer will choose R, P, or S, then \n"
         << "the user will be prompted for their choice, and then the score will   \n"
         << "be updated.  P beats R, R beats S, and S beats P. The score starts    \n"
         << "at 0.  Add one if the person wins, subtract one if the computer wins. \n"
         << "The game ends if the score reaches -5 or + 5.                         \n"
         << "User input of 'x' or 'X' causes the game to exit.                     \n"
         << endl
         << "Here we go!  \n"
         << endl;
    
    int computerChoiceVersion;
    cout << "Select how the computer chooses its move: \n"
         << "1. Always choose Rock \n"
         << "2. Random guess \n"
         << "3. Random guess with graphical score \n"
         << "Enter your choice: ";
    cin >> computerChoiceVersion;
    cout << endl;
    cout << endl;
// *** Abhinav: Should use consistent indents
//variables defined for userMove and computerMove option 1
 char computerMove = ' ';
 char userMove = ' ';
 int scoreNumber = 0;
 int moveNumber = 1;
 int graphicalScoreNumber = 5; 
  
/* option 1 is defined below
 * 
 * 
 */
if (computerChoiceVersion == 1) {
  computerMove == 'R';
  
  // while loop keeps the game running
  while (scoreNumber > -5 && scoreNumber < 5) {  // *** Abhinav: Should only use single loop
 
  // *** Abhinav: Should keep consistent space between code
  // prompt that displays current move number and prompts user to enter move  
  cout << moveNumber << ". " <<  "Your move: \n";
  cin >> userMove;

        
  // acceptable inputs are made uppercase
  userMove = toupper( userMove);
    
    
  // Instance where user chooses scissors
  if (userMove == 'S') {
   cout << "Computer chose R" << endl;
    moveNumber = moveNumber + 1;
    scoreNumber = scoreNumber - 1;
 cout << "Computer's point. Score: " << scoreNumber << endl << endl;


}
  // Instance where user chooses rock
  if (userMove == 'R') {
   cout << "Computer chose R" << endl;
    moveNumber = moveNumber + 1;
   cout << "Tie. Score: " << scoreNumber << endl << endl;


}
  // Instance where user chooses paper
  if (userMove == 'P') {
   cout << "Computer chose R" << endl;
    moveNumber = moveNumber + 1;
    scoreNumber = scoreNumber + 1;
   cout << "User's point. Score: " << scoreNumber << endl << endl;


}

    
  // if the userMove is lowercase x
  if (userMove == 'x') {
  cout << "Exiting program... \n";
  break;
}
    
    
  // if the userMove is uppercase X
  if (userMove == 'X') {
  cout << "Exiting program... \n";
  break;
}
    
} 
  
 // game 1 win conditions defined  
  if (scoreNumber == 0) {
    cout << "Tie game!" << endl << endl;
}
    
    
  if (scoreNumber > 0 && scoreNumber <= 5) {
    cout << "User Wins!" << endl << endl;
}
    
  if (scoreNumber >= -5 && scoreNumber < 0) {
    cout << "Computer Wins!" << endl << endl;
}   
}  
  
  
  
  
/*  option 2 is defined below
 * 
 * 
 */  
 if (computerChoiceVersion == 2) {
   
 
  // now to create a while loop that will run the game
 while (scoreNumber > -5 && scoreNumber < 5) { // *** Abhinav: Should only use single loop
           
  // Generates a random # 1 through 3 and stores it in randomComputerChoice
  int randomComputerChoice = rand()%3;
        
   
    // prompt that displays current move number and prompts user to enter move  
  cout << moveNumber << ". " <<  "Your move: ";
  cin >> userMove;

   
   // acceptable inputs are made uppercase
  userMove = toupper( userMove);
   
   
 // this piece will handle the game when R is input
  if (userMove == 'R') {
    randomComputerChoice; // case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
      cout <<  "  Tie. Score: " << scoreNumber << endl << endl;
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber + 1;
      cout << "  User's point. Score: " << scoreNumber << endl << endl;
     }  // case 3 
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber - 1;
      cout << "  Computer's point. Score: " << scoreNumber << endl << endl; 
    }
    
  }
      
   
 // this piece will handle the game when S is input
  if (userMove == 'S') {
    randomComputerChoice; // case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber -1;
      cout << "  Computer's point. Score: " << scoreNumber << endl << endl;
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      cout << "  Tie. Score: " << scoreNumber << endl << endl;
     } // case 3 
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber + 1;
      cout << "User's point. Score: " << scoreNumber << endl << endl; 
    }
    
  } 
   
      
 // this piece will handle the game when P is input
  if (userMove == 'P') {
    randomComputerChoice; // case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber + 1;
      cout <<  "User's point. Score: " << scoreNumber << endl << endl;
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      scoreNumber = scoreNumber - 1;
      cout << "  Computer's point. Score: " << scoreNumber << endl << endl;
     } // case 3 
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      cout << "Tie. Score: " << scoreNumber << endl << endl; 
    }
    
  } 


  // if the userMove is lowercase x
  if (userMove == 'x') {
  cout << "Exiting program... \n";
  break;
}
    
    
  // if the userMove is uppercase X
  if (userMove == 'X') {
  cout << "Exiting program... \n";
  break;
} 


   
   
}

// wind conditions for game 2 defined  
  if (scoreNumber == 0) {
    cout << "Tie game!" << endl << endl;
}
    
    
  if (scoreNumber > 0 && scoreNumber <= 5) {
    cout << "User Wins!" << endl << endl;
}
    
  if (scoreNumber >= -5 && scoreNumber < 0) {
    cout << "Computer Wins!" << endl << endl;
}    
} 

  
  
  
/* option 3 defined below
 * 
 * 
 */
 if (computerChoiceVersion == 3) {
   

   
   // while loop runs game for option 3 until win condition is reached
   while (graphicalScoreNumber > 0 && graphicalScoreNumber < 10) { // *** Abhinav: Should only use single loop
     
     int randomComputerChoice = rand()%3; // Generates a random # 1 through 3 and stores it in randomComputerChoice
  
   
   
   // *** Abhinav: Should only loop rather than repeated code
    // prompt that displays current move number and prompts user to enter move  
  cout << moveNumber << ". " <<  "Your move: ";
  cin >> userMove;
  cout << endl;

   
   // acceptable inputs are made uppercase
  userMove = toupper( userMove);
   
   
 // this piece will handle the game when R is input
  if (userMove == 'R') {
    randomComputerChoice;
   // case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
     cout << "  Tie. "<< endl;
     cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
     cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;
    
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      graphicalScoreNumber = graphicalScoreNumber + 1;
     cout <<  "User's point." << endl;
     cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
     cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;
     } // case 3  
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      graphicalScoreNumber = graphicalScoreNumber - 1;
     cout << "  Computer's point." << endl;
     cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
     cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;
    }
    
  }

      
   
 // this piece will handle the game when S is input
 else if (userMove == 'S') {
    randomComputerChoice;
   //case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
      cout << "  Computer's point." << endl;
      graphicalScoreNumber = graphicalScoreNumber -1;
     cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
     cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;;
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      cout << "  Tie. "<< endl;
      cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
      cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;
     } // case 3  
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      graphicalScoreNumber = graphicalScoreNumber + 1;
      cout <<  "User's point." << endl;
      cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
      cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;; 
    }
    
  } 
   
   

      
 // this piece will handle the game when P is input
 else if (userMove == 'P') {
    randomComputerChoice;
   //case 1
    if (randomComputerChoice == 0) {
      cout << "  Computer Chose R" << endl;
      moveNumber = moveNumber + 1;
      graphicalScoreNumber = graphicalScoreNumber + 1;
      cout <<  "User's point." << endl;
      cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
      cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;;
    } // case 2
    if (randomComputerChoice == 2) {
      cout << "  Computer Chose S" << endl;
      moveNumber = moveNumber + 1;
      graphicalScoreNumber = graphicalScoreNumber - 1;
      cout << "  Computer's point." << endl;
      cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
      cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;;
     } // case 3
    if (randomComputerChoice == 1) {
      cout << "  Computer Chose P" << endl;
      moveNumber = moveNumber + 1;
      cout << "  Tie. "<< endl;
      cout << " -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
      cout << "----------------------------------" << endl;
for ( int dot = 0; dot < graphicalScoreNumber ; dot++) {

   cout << "...";

}
   cout << "..^";
   cout << endl;; 
    }
    
  } 


  // if the userMove is lowercase x
  if (userMove == 'x') {
  cout << "Exiting program... \n";
  break;
}
    
    
  // if the userMove is uppercase X
  if (userMove == 'X') {
  cout << "Exiting program... \n";
  break;
} 
       
     
}
 // win conditions for option 3
 cout << endl; 
 if (graphicalScoreNumber == 5) {
   cout << "Tie game!" << endl << endl;
} 
 if ((graphicalScoreNumber >= 0) && (graphicalScoreNumber <= 4) ) {
   cout << "Computer Wins!" << endl << endl;
}
if ((graphicalScoreNumber >= 6) && (graphicalScoreNumber <= 10)) {
  cout << "User Wins!" << endl << endl;
}    
   
} 
  



  
  

    
    cout << "Ending program..." << endl;
    return 0;   // Keep C++ happy
}//end main()
