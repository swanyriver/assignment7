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
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

void demonstrateComponent();


/////////////////////////////////////////////////
////////////Introduction and repetition ////////
////////////////////////////////////////////////
int main(){

   string intro = "";

   do{

     cout << intro;
     demonstrateComponent();

   } while ( swansonInput::yesNo( "Would you like to see that again" ) );

   return 0;

}


/////////////////////////////////////////////////
////////////Exercise Component /////////////////
////////////////////////////////////////////////

void demonstrateComponent(){


}




