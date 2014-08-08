/*
 * ToyLife.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: Brandon
 *
 *      Attempting to test out some ideas for next week Game of Life
 */


#include <iostream>
#include <utility>
#include <set>
#include <map>

using namespace std;

struct cord{
   int x;
   int y;
};

struct cell{
   bool alive;
   cord loc;
   int neighbors;
};

int main(){
   pair <int,int> cord1 (5,1);
   pair <int,int> cord2 (1,4);
   pair <int,int> cord3 (3,1);
   pair <int,int> cord4 (3,1);

   std::map<pair<int,int>,int> neighbors;
   //map<int,int> neighbors;

   neighbors.insert(pair<pair<int,int>,int> (cord1,7));
   neighbors.insert(pair<pair<int,int>,int> (cord2,4));
   neighbors.insert(pair<pair<int,int>,int> (cord3,2));
   neighbors.insert(pair<pair<int,int>,int> (cord4,3));
   neighbors.insert(pair<pair<int,int>,int> (pair<int,int>(3,5),3));

   for(map<pair<int,int>,int>::iterator it=neighbors.begin();
         it!=neighbors.end();it++){
      cout << "cell at " << it->first.first << "/" << it->first.second;
      cout << " has " << it->second << " neighbors" << endl;
   }

   /*
    * I need to learn how to write a custom .less() function object
    * for this to work
    * But storing x,y as first and second in a pair is dangerous
    *
    */
   /*map<cord,int> neighbors2;

   neighbors2.insert(pair<cord,int>(cord{1,1},2));
   neighbors2.insert(pair<cord,int>(cord{5,8},1));
   neighbors2.insert(pair<cord,int>(cord{5,7},3));
   neighbors2.insert(pair<cord,int>(cord{3,1},2));

   cout << "~~~~~~COORD MAP~~~~~~" << endl;

   for(map<cord,int>::iterator it=neighbors2.begin();
         it!=neighbors2.end();it++){
      cout << "cell at " << it->first.x << "/" << it->first.y;
      cout << " has " << it->second << " neighbors" << endl;
   }
*/


}


