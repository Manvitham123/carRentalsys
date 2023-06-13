#include <iostream>
#include <vector>

using namespace std;




class user{
    public:
        user();
        user(string userName,string password);
      //  string getName();   
        string getUsername(); 
        bool validatePassword(string password);
    private:
       // string name;
        string username;
        string password;
};

class userDatabase{

    public:
    user getUser(string username);
    bool verify(string username, string password);
    virtual void load() = 0;

    protected:
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