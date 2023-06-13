#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "userData.h"
using namespace std;
user::user()
{username = "none";
password = "none";}

user::user(string userName1,string password1)
{
    username=userName1;
    password=password1;
}
string user::getUsername()
{
    return username;
}

bool user::validatePassword(string password)
{
    if(this->password.compare(password) == 0){
         return true;
    }
    else{
        return false;
    }
   
}

user userDatabase:: getUser(string username1){
    user temp;
    for (auto user: userList)
  {
    if(user->getUsername() == username1){
        temp = *user;
        }
    }

    return temp;

 
}

bool userDatabase:: verify(string username1, string password1){
  

    for (auto user: userList)
  {

    if(user->getUsername().compare(username1) == 0){//.compare??

    if(user->validatePassword(password1)){
     
            return true;

    }
   
        }
        
    }
    return false;
}
 fileUserDatabase::fileUserDatabase(string filename){
    this->filename = filename;
 }
void fileUserDatabase::load(){
    ifstream fin;
    fin.open(filename);
    string line;
    string username;
    string password; 
     while(getline(fin, line)){
       
        vector<string> tokens = getStringTokens(line, ',');
        user *person = new user(tokens[0], tokens[1]);
        userList.push_back(person);
    }
}
vector<string> fileUserDatabase::getStringTokens(string str, char delim)
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
