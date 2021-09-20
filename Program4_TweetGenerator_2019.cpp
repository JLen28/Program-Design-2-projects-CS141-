//  prog4TweetGenerator.cpp
//     Generate somewhat random tweets based on a datafile.
//
//  CS 141 Spring 2019
//  Author: Joe Lenaghan and Sam Alammar
//
//  Open up a data file and find a starting point for some set of consecutive words
//  and print the starting word.
//
//  Next find all occurrences in the datafile of those consecutive words, and collect the set
//  of words that immediately follow each of those occurrences.  Choose one of the words
//  in this newly created set and add it to the set of consecutive words, shifting them
//  over by one so the first word gets overwritten by the second, and so on.
//
//  Repeat this process until >=30 words are displayed and an end-of-sentence word is found,
//  or until a displayed word has a newline or a return character at the end of it.
//
#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <vector>
#include <cstring>      // For strlen()
#include <cstdlib>      // For rand()
using namespace std;

//---------------------------------------------------------------------
void getInputWords( vector<string> &allWords)   // List of all the words in the selected input file
{
    // Prompt for and get user choice for which data file to use
    cout << "Menu Options: \n"
         << "  1. Use Trump tweets \n"
         << "  2. Use Dalai Lama tweets \n"
         << "  3. Use Mixed Trump / Dalai Lama tweets \n"
         << "  4. Use small test file \n"
         << "  5. Use tiny test file \n"
         << "Your choice: ";
    int dataSelectionOption;
    cin >> dataSelectionOption;
    
    ifstream inputFileStream;  // declare the input file stream
    // open input file and verify
    switch( dataSelectionOption) {
        case 1: inputFileStream.open("TrumpTweets.txt"); break;
        case 2: inputFileStream.open("DalaiLamaTweets.txt"); break;
        case 3: inputFileStream.open("TrumpLama.txt"); break;
        case 4: inputFileStream.open("Test.txt"); break;
        case 5: inputFileStream.open("tiny.txt"); break;
        default: cout << "Invalid option chosen, exiting program. ";
            exit( -1);
            break;
    }
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file.  Exiting..." << endl;
        exit( -1);
    }
    
    char c = ' ';
    char inputWord[ 81];
    
    // Read a character at a time from the input file, separating out individual words.
    inputWord[ 0] = '\0';
    int index = 0;
    while( inputFileStream.get(c)) {
        if( ! isprint( c) && c != '\r' && c != '\n') {
            continue;   // Skip non-printable characters and get the next one
        }
        if( c != ' ') {
            // If it is not a return or newline, add it to the string.
            // If it is a return or newline character, only add it if there
            //    are already other characters in the string.
            if( (c != '\r' && c != '\n') ||
                ( (c == '\r' || c == '\n') && index > 0)
              ) {
                inputWord[ index++] = c;
            }
        }
        // End the word when encountering a space or a return character.
        if( c == ' ' || c == '\r' || c == '\n'){
            // Null terminate the input word. Store it if its length is > 0 and it is printable.
            inputWord[ index] = '\0';
            if( strlen( inputWord) > 0 && isprint( inputWord[0])) {
                allWords.push_back( string( inputWord));
            }
            // Check for special case where there is a space at the end of the line.  We don't want
            // to lose the end of line character ('\n' or '\r'), so we concatenate it to the
            // last word that was previously stored on the list.  First check to see if this is the case:
            if( (c == '\r' || c == '\n') && strlen( inputWord) == 0) {
                long indexOfLastWord = allWords.size() - 1;
                allWords.at( indexOfLastWord).append("\r");
            }
            
            index = 0;    // Restart the index for the next word
        }
    }//end while( inputFileStream...)
}
// *** Abhinav: Use consistent spacing

//---------------------------------------------------------------------
void checkWords( vector<string> startWords,  // List of first words in sentences
                 vector<string> allWords,    // All words from input file
                 vector<string> wordList,    // List of all words following search phrase
                 string nextWord)            // Nexts word found after search phrase
{
    int debugMenuOption = 0;
    
    do {
        // Prompt for and get user choice for which debug option to use
        cout << " \n"
             << "    >>> Debug menu options: <<<\n"
             << "        1. Display a start word \n"
             << "        2. Display one of all words \n"
             << "        3. Display wordWindow and next words \n"
             << "        4. Exit debugging \n"
             << "    Your choice -> ";
        cin >> debugMenuOption;
        
        int wordIndexValue = 0;    // Used to read user input for debug options below
        
        switch( debugMenuOption) {
            case 1: cout << "    Enter an index value from 0 to " << startWords.size()-1 << " to display a start word: ";
                    cin >> wordIndexValue;
                    cout << "    " << startWords.at( wordIndexValue) << endl;
                    break;
            case 2: cout << "    Enter an index value from 0 to " << allWords.size()-1 << " to display one of all words: ";
                    cin >> wordIndexValue;
                    cout << "    " << allWords.at( wordIndexValue) << endl;
                    break;
            case 3: cout << "    WordWindow and next words are: ";
                    for( int i=0; i<wordList.size(); i++) {
                        cout << wordList.at( i) << " ";
                    }
                    cout << nextWord <<endl;
                    break;
        }//end switch(...)
    }while( debugMenuOption != 4);
}//end debug()
//--------------------------------------------------------------------
//function that creates starting words vector...
 void getStartWords( vector<string> &startWords, vector<string> allWords)
 {
   startWords.push_back(allWords.front()); // first element of allWords needs to be added always...
   
   for(int i = 0; i < allWords.size() - 1; i++)  // this for loop needs to run thru allwords and grab the first element of the text as well as every element after a newline...
   {
     
     int word = allWords.at(i).size();
     char lastLetter = allWords.at(i).at(word-1);
     if((lastLetter == '\n') || (lastLetter == '\r')){
       startWords.push_back(allWords.at(i+1));
     }
   }
 }

//---------------------------------------------------------------------
int main()
{
    vector<string> allWords;   // List of all input words
    vector<string> startWords; // List of words that start sentences, to use
                               //   in starting generated tweets.

    cout << "Welcome to the tweet generator. " << endl << endl;
    
    getInputWords( allWords);
    // This function will get all the starting words from allWords and add it into the vector startWords.
    getStartWords( startWords, allWords);
    
    // Allow looping to give more than one tweet
    int wordWindowWidth = 0;
    char userInput = ' ';
    
    // Main loop
    while( userInput != 'X') {
      cout << endl;
      cout << "Enter x to exit, or d/c to debug/continue followed by word window size: ";
      cin >> userInput;
      userInput = toupper( userInput);    // fold user input into upper case

      if( userInput == 'X') {
          break;   // Exit program
      }
      // *** Abhinav: Use consistent spacing

      cin >> wordWindowWidth; // Read in the wordWindowWidth to be used in both the "continue" and the "debug" modes

      int rando = rand() % startWords.size(); // this chooses a random # in the startWords index for "random" selection...
      string chosenStartWord = startWords.at(rando); // rando integer is used to find the position in startWords that corresponds to the "random" integer... 

      vector<string> wordList;   // Stores the list of consecutive words that are searched for
      wordList.push_back(chosenStartWord);

       for (int i = 0; i < allWords.size() - wordWindowWidth; ++i) // creating the wordList...
       {
         if( allWords.at(i) == chosenStartWord){      // Find the selected startWord within the allWords list.
           // Another for loop was made to add every consecutive word depending on the size of wordWindowWidth.
           for(int j = 1; j < wordWindowWidth; j++){
             wordList.push_back(allWords.at(i + j));  // Store the chosen number of consecutive starting words
         }
           break;
         }
       }
      
      // wordCounter will be used to keep a check on the number of words used.
      int wordCounter = 0;
      // Inner while loop that will keep going on adding random words till a certain check is met.
      while( true) {
        
        // The vector followWords will be used to store the next possible words in the sequence.
        vector<string> followWords;
        
        // This will be used to check what the last letter of the last word in wordList is for later use.
        int firstWindowWord = wordList.at(0).size();
        char lastLetterFirstWord = wordList.at(0).at(firstWindowWord-1);
        
        /* Search for adjacent wordWindow words in allWords and find all the words that
           follow the sequence of that word sequence.  
           Here, we will initiate a variable that will keep checking the window width of an instance of spotting the required words in allWords.*/
        int width = 0;
        
        // The first loop will check through allWords, trying to find a match with wordList.
        for (int i = 0; i < allWords.size() - wordList.size(); i++)
        {
          // The second loop will go look through if every word in wordList match up with allWords, and increment width as neccesary.
          // If it they don't match up at any point then it will break off the 2nd loop.
          for(int j = 1; j < wordList.size() + 1; j++){
            if(allWords.at(i + j) == wordList.at(j - 1)){
              width++;
            }
            else{
              break;
            }
          } // end of 2nd for loop
          
          // Check to see if the width is the same size as wordList, and if it is then it will add the next word in allWords to followWords.
          if(width == wordList.size()){
            followWords.push_back(allWords.at(i+ width + 1));
          }
          
          // Keep reseting width to 0 before the next loop
          width = 0;
        } // end of first for loop


        // Choose one followWord word at random and call it nextWord.
        int thirdRando = rand() % followWords.size();
        string nextWord = followWords.at(thirdRando);

        // If in checkWordsMode then allow displaying single word values using the checkWords(...) function, then exit the program.
        if( userInput == 'D'){
          checkWords( startWords, allWords, wordList, nextWord);
          return 0;
        }

        // Display the first word in the wordWindow & increment wordCounter.
        cout << " " << wordList.at(0);
        wordCounter++;

        // If the first word in the wordWindow ends in a return, then we're done with our output for this tweet.
        if ((lastLetterFirstWord == '\n') || (lastLetterFirstWord == '\r')){  
          break;
        }  

        // If there have been >= 30 words and the word ends with '.', '.' or '!' or '?', then we're done with output for this tweet
        if ((wordCounter >= 30) && ((lastLetterFirstWord == '.') ||(lastLetterFirstWord == ',' )||(lastLetterFirstWord == '!' )||(lastLetterFirstWord == '?'))){
            break;
        }

        // Shift words "left" to prepare for next round, shifting nextWord into the "right" of the wordWindow words.
        wordList.erase(wordList.begin());
        wordList.push_back(nextWord);


      }//end while( true)
        
    }// end while( userInput != 'x')
  
  cout << endl << endl;
    
    return 0;
}//end main()

