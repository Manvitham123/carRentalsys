#include <iostream>
#include <vector>
#include "rental.h"
using namespace std;

int main(){
    string again = "yes";
    userInteraction *interact =  new userInteraction("userData.txt", "car.txt");
    interact->LoadCarData();
      interact->LoadUserData();
     
     interact->login();
    while (interact->getVerifiedUser()==false){
       interact->login();
     }
    while(again == "yes" || again == "no"){
        interact->reset();

     interact->loginOptions();
     

    interact->update();
    
    cout << "if you would like to return to the main menu please type yes if not press any character" << endl;
    cin >> again;
  
    
    

    }



    
    return 0;

}