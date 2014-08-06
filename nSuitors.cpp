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

using namespace std;

void demonstrateComponent();


/////////////////////////////////////////////////
////////////Introduction and repetition ////////
////////////////////////////////////////////////
int main(){

   string intro = "Here we will determine where you should stand if you you\n"
                  "want to marry the princess with a bizarre counting method"
                  "\nof selection";

   do{

     cout << intro;
     demonstrateComponent();

   } while ( swansonInput::yesNo( "Would you like to see that again" ) );

   return 0;

}

void showLine ( const vector<int> &suitorLine ,
      vector<int>::iterator selected);

/////////////////////////////////////////////////
////////////Exercise Component /////////////////
////////////////////////////////////////////////

void demonstrateComponent(){

   vector<int> suitorLine;

   int numSuitors = swansonInput::GetInt("How many suitors are there:",1);

   string prompt = "would you like to output the elimination process \n"
            "Not recommended for large groups of suitors\n"
            "display suitors with elimination highlighted with () ";
   bool displayOn = swansonInput::yesNo(prompt);

   int i=0;
   while(i++<numSuitors) suitorLine.push_back(i);

   vector<int>::iterator eve = suitorLine.begin();

   while(suitorLine.size()>1){


      int dist = distance(eve,suitorLine.end());

      if(dist<3){
         eve = suitorLine.begin() + (2-dist)%suitorLine.size();

      }else{
         eve += 2%suitorLine.size();
      }

      if(displayOn) showLine(suitorLine , eve);

      eve = suitorLine.erase(eve);

   }

   cout << "suitor selected will be standing in position:"
         << suitorLine.front();


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



