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
#include <cstdio>
#include <string>
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

int MaxCallDepth;

void EXEPCallDiver ( int depth );
void CallDiver ( int depth ) throw (int);

int main () {

   string intro =
       "We will trace the call depth of a recursive function"
       "\nI tried out two different implementations, one where int main()"
       "\ncatches the exception, and another where the function itself catches";

   cout << endl << intro << endl;

   do {

      MaxCallDepth = swansonInput::GetInt( "How deep should we go:" , 0, 100);

      /////first method
      int currentDepth = 0;

      try {
         if ( currentDepth == MaxCallDepth )
            throw(currentDepth);

         CallDiver( currentDepth );
      }

      catch (int achievedDepth) {
         cout << endl << "we made it to a depth of " << achievedDepth << endl;
         cout << "exception caught by int main()" << endl;
      }

      cout << endl << endl << "press any key to continue on to method 2";
      getchar();

      try {
         if ( currentDepth == MaxCallDepth ) throw(currentDepth);

         EXEPCallDiver( currentDepth );
      }

      catch (int achievedDepth) {
         cout << endl << "we made it to a depth of " << achievedDepth << endl;
         cout << "exception caught by int main()"
               << "because recusive method never called" << endl;
      }

   } while ( swansonInput::yesNo( "Would you like to see that again" ) );

   return 0;

}

void EXEPCallDiver ( int depth ) {
   try {
      if ( depth == MaxCallDepth )
         throw(depth);

      cout << "At Depth:" << depth << " diving deeper" << endl;

      EXEPCallDiver( ++depth );

      cout << "At Depth:" << depth << " popping calls of stack" << endl;
   }

   catch (int achievedDepth) {
      cout << endl << "we made it to a depth of " << achievedDepth << endl;
      cout << "exception caught by recursive method" << endl;
      cout << "press any key to continue" << endl;
      getchar();
   }

}

void CallDiver ( int depth ) throw (int) {
   if ( depth == MaxCallDepth )
      throw(depth);

   cout << "At Depth:" << depth << " diving deeper" << endl;

   CallDiver( ++depth );

   cout << "At Depth:" << depth << " popping calls of stack" << endl;
   //interesting this line is never reached, the calls still on the stack
   //seem to be aborted

}

