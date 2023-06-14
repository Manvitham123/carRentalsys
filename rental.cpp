#include <iostream>
#include <vector>
#include "rental.h"
using namespace std;

int main(){
    string again = "yes";
    userInteraction *interact =  new userInteraction("userData.txt", "car.txt");
      interact->LoadUserData();
     interact->LoadCarData();
     interact->login();
    while (interact->getVerifiedUser()==false){
       interact->login();
     }
    while(again == "yes"){
        interact->reset();
  

     interact->displayCarOptions();
     while(interact->getChosenType()==false){
             interact->displayCarOptions();


     }
     interact->chooseCar();
     while(interact->getChosenNumber()==false){
         interact->chooseCar();

     }
     interact->setNumberOfDays();
     while(interact->getDays()==0){
          interact->setNumberOfDays();

     }
    
    cout << "would you like to rent another car? yes or no: " << endl;
    cin >> again;
    

    }

    
    return 0;

}