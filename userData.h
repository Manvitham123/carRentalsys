#include <iostream>
#include <vector>
#include "car.h"

using namespace std;




class user{
    public:
        user();
        user(string userName,string password);
      //  string getName();   
        string getUsername(); 
        string getPassword();
        bool validatePassword(string password);
        void addCars(int n);
        void removeCars(int n);
        vector<int> getCars();
    private:
       // string name;
        string username;
        string password;
        vector<int> rented;
};

class userDatabase{

    public:
    user* getUser(string username);
    bool verify(string username, string password);
    
    virtual void load() = 0;
    vector<user *> userList;
   

};

class fileUserDatabase: public userDatabase{
    public:
    fileUserDatabase(string filename);
    
    void load();
    private:
    vector<string> getStringTokens(string str, char delim);
    private:
    string filename;
};