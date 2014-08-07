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


/*
 * Tested with following bash command ./bin 2>log.txt 0<inputTest.txt
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

class ItemNotFound{};
ItemNotFound myNoItem;


int getProductID ( int ids[] , string names[] , int numProducts ,
      string target ) throw (ItemNotFound) {
   for ( int i = 0 ; i < numProducts ; i++ ) {
      if ( names[i] == target )
         return ids[i];
   }
   throw myNoItem; // Not found
}

/////////////////////////////////////////////////
////////////Introduction and repetition ////////
////////////////////////////////////////////////
int main () {

   int productIds[] = {4, 5, 8, 10, 13};
   string products[] = {"computer","flash drive",
                           "mouse","printer","camera"};


   string prompt = "Enter a product name and I can look up its ID number or"
         " \"EXIT\" to quit\nEnter product name now:";



   while(true) {

      string productName = swansonInput::GetString(prompt);
      if(productName=="EXIT") exit(1);

      try{
         int productId = getProductID(productIds,products,5,productName);
         cerr << "Product ID for " << productName
               << " is:" << productId << endl;
      }catch (ItemNotFound){
         cerr << productName << " was not found" << endl;
      }

   }

   return 0;

}

