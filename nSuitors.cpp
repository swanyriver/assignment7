/***********************************************************
 *
 * * Author: Brandon Swanson
 *
 * * Date Created: 08-5-2014
 *
 * * Last Modification Date: 08-5-2014
 *
 * * Filename:
 *
 *
 * * Overview: Week 7 Exercise Component #
 * *
 * * Input:
 * *
 * * Output:
 * *
 * ***********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "SwansonLibs/swansonInput.hpp"
#include <fstream>

using namespace std;


void showLine ( const vector<int> &suitorLine ,
      vector<int>::iterator selected);

int SelectedSuitor ( int numSuitors , bool displayOn = false );


/////////////////////////////////////////////////
////////////Introduction and repetition ////////
////////////////////////////////////////////////
int main(){

   ///algorithm testing
   const int NUM_TEST = 50;
   ofstream testout;
   testout.open("suitorsTest.txt");

   for(int i = 1; i <= NUM_TEST ; i++){
      testout << i << " suitors = " << SelectedSuitor(i) << " selected" << endl;
   }
   testout.close();
   ///algorithm testing concluded

   string intro = "Here we will determine where you should stand if you you\n"
                  "want to marry the princess with a bizarre counting method"
                  "\nof selection";

   do{

     cout << intro;

     int numSuitors = swansonInput::GetInt("How many suitors are there:",1);

     string prompt = "would you like to output the elimination process \n"
              "Not recommended for large groups of suitors\n"
              "display suitors with elimination highlighted with () ";
     bool displayOn = swansonInput::yesNo(prompt);

     cout << "suitor selected will be standing in position:"
           << SelectedSuitor( numSuitors , displayOn );

   } while ( swansonInput::yesNo( "Would you like to see that again" ) );

   return 0;

}

/////////////////////////////////////////////////
////////////Exercise Component /////////////////
////////////////////////////////////////////////

int SelectedSuitor ( int numSuitors , bool displayOn ) {
   int i = 0;
   vector<int> suitorLine;
   while ( i++ < numSuitors )
      suitorLine.push_back( i );
   vector<int>::iterator eve = suitorLine.begin();
   while ( suitorLine.size() > 1 ) {

      //IMPROVED ALGORITHM //or at least different
      //based off of observations on fellow student

      ////////Lisa Percival's//// code this week.

      //using mod on eve's position relative to the beginning, plus 2, and
      //modded on the current size of the vector.  This formula will always
      //advance her 3 positions (position inclusive counting) and wrap the the
      //begining of the list when needed.
      eve = suitorLine.begin() +
            ((distance(suitorLine.begin(),eve) + 2)%suitorLine.size());

      /*
       * ORIGINAL ALGORITHM
       *
       * int dist = distance( eve , suitorLine.end() );
       * if ( dist < 3 ) {
       *    eve = suitorLine.begin() + (2 - dist) % suitorLine.size();
       * } else {
       *    eve += 2 % suitorLine.size();
       * }
       */

      if ( displayOn )
         showLine( suitorLine , eve );

      //making use of returned iterator
      eve = suitorLine.erase( eve );
   }
   return suitorLine.front();
}

void showLine ( const vector<int> &suitorLine ,
      vector<int>::iterator selected) {

   for ( vector<int>::const_iterator it = suitorLine.begin() ;
         it != suitorLine.end() ; it++ ) {
      if(it==selected) cout << "(" << *it << ") ";
      else cout << *it << " ";
   }
   cout << endl;

}



