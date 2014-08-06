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
#include <cmath>
#include "SwansonLibs/swansonInput.hpp"
#include "SwansonObjects/menu.hpp"

using namespace std;

class InventoryItem;

int main(){

   string intro = "";
   cout << intro;



   return 0;

}


class InventoryItem{
private:
   const string mName;
   string mColor;
   float mSalePrice, mAskingPrice;
   int mAgeInYears;
   bool mKnownAge, mSold, mKnownColor;

public:

   /////////////////////////////////////////////////////
   //////////CONSTRUCTOR///////////////////////////////
   ///////////////////////////////////////////////////

   InventoryItem(string name, float askingPrice ):
      mName(name), mAskingPrice(askingPrice){
      mKnownAge = false;
      mSold = false;
      mKnownColor = false;
   }

   /////////////////////////////////////////////////////
   //////////SETTERS///////////////////////////////////
   ///////////////////////////////////////////////////

   //purposefully no setter for name after construction
   //as to maintain inventory integrity
   //if name was desired to be mutable there should be another field
   //that remains constant, IE INV-NUMBER

   void SetAge(int age){
      mAgeInYears=age;
      mKnownAge=true;
   }

   void SetAskingPrice(float askingPrice){
      mAskingPrice = askingPrice;
   }

   void SetColor(string color){
      mColor = color;
      mKnownColor = true;
   }

   void Sell(float salePrice){
      mSold=true;
      mSalePrice = salePrice;
   }


   /////////////////////////////////////////////////////
   //////////GETTERS///////////////////////////////////
   ///////////////////////////////////////////////////

   string GetName(){
      return mName;
   }

   float GetPrice(){
      return mAskingPrice;
   }

   ////because these are not necessarily initialized they return a bool
   // true if there is a value, and returns the value by reference;
   // if no value exist passed in parameter is not modified;

   bool HasColor(string &color){
      if(mKnownColor) color = mColor;
      return mKnownColor;
   }

   bool HasAge (int age){
      if(mKnownAge) age = mAgeInYears;
      return mKnownAge;
   }

   bool IsSold (float salePrice){
      if(mSold) salePrice = mSalePrice;
      return mSold;
   }

};



