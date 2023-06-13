#include <iostream>
#include <vector>
#include "rental.h"
using namespace std;

int main(){

    userInteraction *interact =  new userInteraction("userData.txt", "car.txt");
    interact->LoadUserData();
     interact->LoadCarData();
    interact->login();
    while (interact->getVerifiedUser()==false){
       interact->login();
     }
     interact->displayCarOptions();
     while(interact->getChosenType()==false){
             interact->displayCarOptions();


     }
     interact->chooseCar();
     while(interact->getChosenNumber()==false){
         interact->chooseCar();

     }
     interact->setNumberOfDays();



    
    return 0;

}