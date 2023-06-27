#include <iostream>
#include <vector>
#include "userData.h"



using namespace std;


class userInteraction{
    public:
    userInteraction(string userFile, string carFile);
   void LoadUserData(); 
   void LoadCarData();
    void login();
    vector<car> displayCarOptions();
    vector<string> carRentalDetails(double number);
    void loginOptions();
    void displayRented();
    void chooseCar();
    void setNumberOfDays();
    void invoice();
    bool getVerifiedUser();
   bool getChosenType();
   bool getChosenNumber();
   int getDays();
   void reset();
   void update();
   void returnCar(int num);
 
   
    




    private:
    user *verifiedUser;
    car chosen;
    int days; 
    fileUserDatabase h;
    fileCarDatabase c;

};
