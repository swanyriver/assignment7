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
#include <vector>
#include <iterator>
#include "SwansonLibs/swansonInput.hpp"
#include "SwansonObjects/menu.hpp"
#include "SwansonLibs/swansonString.hpp"

using namespace std;

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

   InventoryItem(string name, float askingPrice );

   /////////////////////////////////////////////////////
   //////////SETTERS///////////////////////////////////
   ///////////////////////////////////////////////////

   //purposefully no setter for name after construction
   //as to maintain inventory integrity
   //if name was desired to be mutable there should be another field
   //that remains constant, IE INV-NUMBER
   void SetAge(int age);
   void SetAskingPrice(float askingPrice);
   void SetColor(string color);
   void Sell(float salePrice);

   /////////////////////////////////////////////////////
   //////////GETTERS///////////////////////////////////
   ///////////////////////////////////////////////////
   string GetName();
   float GetPrice();

   ////because these are not necessarily initialized they return a bool
   // true if there is a value, and returns the value by reference;
   // if no value exist passed in parameter is not modified;
   bool HasColor(string &color);
   bool HasAge (int &age);
   bool IsSold (float &salePrice);

};

////////function prototypes ////
string DisplayItem(InventoryItem item);

int main(){

   vector<InventoryItem*> myStock;

   ////////////////////////////////////
   //////////hard coded inventory /////
   ////////////////////////////////////
   myStock.push_back(new InventoryItem("table",123.45));
   myStock.back()->SetColor("red");
   myStock.back()->SetAge(200);

   myStock.push_back(new InventoryItem("chair",300));

   myStock.push_back(new InventoryItem("lamp",34.56));
   myStock.back()->SetColor("green");
   myStock.back()->SetAge(150);

   myStock.push_back(new InventoryItem("doll",22.11));
   myStock.back()->SetColor("pale white");

   myStock.push_back(new InventoryItem("stool",25.60));
   myStock.back()->SetAge(30);



   ////////////////////////////////////
   //////////Display Items ////////////
   //////////Make a selection//////////
   //////////Set Sale Price ///////////
   ////////////////////////////////////
   while(true) {
      int quit=myStock.size() + 1;
      for(vector<InventoryItem*>::iterator it = myStock.begin();
            it!= myStock.end(); it++){
         cout << distance(myStock.begin(),it) + 1 << ") A " ;
         cout << DisplayItem(**it) << endl;
      }
      cout << quit << ") EXIT INVENTORY" << endl;
      int selection = swansonInput::GetInt
         ("choose an item to make a sale:", 1,myStock.size() + 1);

      if(selection == quit) break;

      InventoryItem *soldItem = myStock.at(selection-1);

      float price;

      if(soldItem->IsSold(price)){
         cout << "that item was already sold for $" << price << endl << endl;
      }  else {

         string prompt =  "how much did the " ;
         prompt +=soldItem->GetName() + " sell for:";

         soldItem->Sell(swansonInput::GetFloat(prompt));
      }

   }



   return 0;

}

/*I would normally like to put this function as a member of the class
 * either as an << overload or as a .ToString() method,  but that would
 * not provide me any opportunities to demonstrate the getter methods
 * so this one is built using the public function interface to generate a string
 */

string DisplayItem(InventoryItem item){
   string output, color;
   int age;
   float price;

   if(item.HasAge(age)){
      output += swansonString::GetString(age) + " years old ";
   }
   if(item.HasColor(color)){
      output += color + " ";
   }
   output += item.GetName();
   price = item.GetPrice();
   if(item.IsSold(price)) output += " was sold for $";
   else output += " is going for $";
   output += swansonString::GetString(price);

   return output;
}

////////////////////////////////////////////////////////
/////////////////class definitions//////////////////////
////////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//////////CONSTRUCTOR///////////////////////////////
///////////////////////////////////////////////////

InventoryItem::InventoryItem(string name, float askingPrice ):
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

void InventoryItem::SetAge(int age){
   mAgeInYears=age;
   mKnownAge=true;
}

void InventoryItem::SetAskingPrice(float askingPrice){
   mAskingPrice = askingPrice;
}

void InventoryItem::SetColor(string color){
   mColor = color;
   mKnownColor = true;
}

void InventoryItem::Sell(float salePrice){
   mSold=true;
   mSalePrice = salePrice;
}


/////////////////////////////////////////////////////
//////////GETTERS///////////////////////////////////
///////////////////////////////////////////////////

string InventoryItem::GetName(){
   return mName;
}

float InventoryItem::GetPrice(){
   return mAskingPrice;
}

////because these are not necessarily initialized they return a bool
// true if there is a value, and returns the value by reference;
// if no value exist passed in parameter is not modified;

bool InventoryItem::HasColor(string &color){
   if(mKnownColor) color = mColor;
   return mKnownColor;
}

bool InventoryItem::HasAge (int &age){
   if(mKnownAge) age = mAgeInYears;
   return mKnownAge;
}

bool InventoryItem::IsSold (float &salePrice){
   if(mSold) salePrice = mSalePrice;
   return mSold;
}




