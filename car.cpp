#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "car.h"
using namespace std;

double car::getMaxpower(){
return maxPower;
}
double car::getrentPrice(){
return rentPrice;
}
int car::getMileage(){
return mileage;
}
int car::getNumber(){
return number;
}

string car::getType(){
return type;
}

void car::setType(string t){
  this->type = t;

}
car::car(){
}
car::car(double rentPrice, double maxPower, int mileage, int number, string type)
{
    this->rentPrice=rentPrice;
     this->maxPower=maxPower;
      this-> mileage=mileage;
       this->number=number;
       this->type = type;
    
}



fileCarDatabase::fileCarDatabase(string filename){
    this->filename = filename;
 }

void fileCarDatabase::load(){
    ifstream fin;
    fin.open(filename);
    string line;
   // double rentPrice1 = 0;
    //double maxPower1 = 0;
    //int mileage1 = 0;
    //int number1 = 0;
    //string type1 = "";
    int count = 0;
  
    while(getline(fin, line)){
        
        vector<string> tokens = getStringTokens(line, ',');
        car *temp = new car(stod(tokens[0]), stod(tokens[1]), stoi(tokens[2]), stoi(tokens[3]), tokens[4]);
        carList.push_back(temp);
        for(auto s: typeList){
          if(s ==  tokens[4]){
            ++count;

          }

        }
        if(count==0){
          typeList.push_back( tokens[4]);
        }
        else{
          count = 0;
        }

        }
       // car *temp = new car(rentPrice1,  maxPower1,  mileage1, number1, type1);
        //carList.push_back(temp);
        



        }
 
        
    
vector<string> fileCarDatabase::getStringTokens(string str, char delim)
{
  vector<string> tokens;
  stringstream ss(str);
  string temp;
  while (getline(ss, temp, delim))
  {
    tokens.push_back(temp);
  }
  return tokens;
}
