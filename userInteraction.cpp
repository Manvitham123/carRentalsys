#include <iostream>
#include <vector>
#include "userInteraction.h"
#include <fstream>
#include <string.h>

using namespace std;

userInteraction::userInteraction(string userFile, string carFile) :  chosen(0.0, 0.0, 0, 0, "none",0), days(0), h(userFile), c(carFile)
{
    verifiedUser = new user("0", "0");
}
bool userInteraction::getVerifiedUser()
{
    if (verifiedUser->getUsername() == "0")
    {
        return false;
    }
    return true;
}

int userInteraction::getDays(){
    return days;
}

bool userInteraction::getChosenNumber()
{
    if (chosen.getNumber() == 0)
    {
        return false;
    }
    return true;
}
bool userInteraction::getChosenType()
{
    if (chosen.getType() == "none")
    {
        return false;
    }
    return true;
}

void userInteraction::login()
{
    string username;
    string password;
    cout << "Enter username:" << endl;
    cin >> username;
    cout << "Enter password:" << endl;
    cin >> password;
    if (h.verify(username, password))
    {
        cout << "log in successful" << endl;
        verifiedUser = h.getUser(username);
    }
    else
    {
        cout << "log in unsuccessful try again" << endl;
    }
}
void userInteraction::LoadUserData()
{
    h.load();
}
void userInteraction::LoadCarData()
{
    c.load();
}

void userInteraction::loginOptions(){
    string num;
    cout<<"Main menu: "<<endl;
    cout<<"enter the corresponding number to preform an action:"<<endl;
    cout<<"1) rent a car" <<endl;
    cout<< "2) view ur current rentals"<<endl;
    cout<< "3) return a rental"<<endl; 
    cout<< "4) exit" <<endl; 
    cin>>num;
    if(stoi(num) == 1){
        displayCarOptions();
    while(getChosenType()==false){
             displayCarOptions();
     }
     chooseCar();
     while(getChosenNumber()==false){
        chooseCar();

     }
  setNumberOfDays();
     while(getDays()==0){
         setNumberOfDays();

     }

    }
    else if (stoi(num)==2){
        displayRented();

    }
    else if(stoi(num) == 3){
        string carN;
      int count = 0;
    for(auto nums: verifiedUser->getCars()){

        car rented  = c.getCar(nums);
        if(rented.getrentPrice() != 0){
          cout << "Rented Car details: " << endl;
    cout << "   Car Id: " << rented.getNumber() << endl;
    cout << "   Car type: " << rented.getType() << endl;
    cout << "   Mileage: " << rented.getMileage() << endl;
    cout << "   Rent price: " << rented.getrentPrice() << endl;
    cout << "   Max power: " << rented .getMaxpower() << endl;
    cout << endl;
        }
        ++count;
    }
    if(count ==0){
        cout<<"no cars rented currently"<<endl;
        returnCar(0);
    }
        cout<<"what car would you like to return? enter number"<<endl;
        cin>>carN;
        try{
            returnCar(stoi(carN));
        }
        catch(...){
             cout<<" "<<endl;
            cout<<"invalid input"<<endl;
            cout<<" "<<endl;
            returnCar(0);
        }
        

    }
    else if(stoi(num)==4){
        return;

    }
    else{
         cout<<"incorrect entry"<<endl;

    }
}
void userInteraction::returnCar(int num){
    
     if(num == 0){
        loginOptions();
     }
    for(auto cars: c.carList){
       
        if(num == cars->getNumber()){
           if(cars->getAvailability() == false){
            cars->setAvailability(true);
            verifiedUser->removeCars(num);
              cout<<"car "<< num << " returned"<<endl;

           }
           else{
            cout<<"car not rented"<<endl;
            loginOptions();
           }
        

        }
    }


}


void userInteraction::displayRented(){
    int count = 0;
    for(auto nums: verifiedUser->getCars()){

        car rented  = c.getCar(nums);
        if(rented.getrentPrice() != 0){
          cout << "Rented Car details: " << endl;
    cout << "   Car Id: " << rented.getNumber() << endl;
    cout << "   Car type: " << rented.getType() << endl;
    cout << "   Mileage: " << rented.getMileage() << endl;
    cout << "   Rent price: " << rented.getrentPrice() << endl;
    cout << "   Max power: " << rented .getMaxpower() << endl;
    cout << endl;
        }
        ++count;
    }
    if(count ==0){
        cout<<"no cars rented currently"<<endl;
    }
    loginOptions();
}

vector<car> userInteraction::displayCarOptions()
{
    string carType;
    cout << " " << endl;
    cout << "Available car type options: " << endl;
    for (auto types : c.typeList)
    {
        cout << types << endl;
    }
    cout << " " << endl;

    cout << "what car type would you like?:" << endl;
    cin >> carType;
    vector<car> filteredCars;
    for (auto cars : c.carList)
    {
        if (cars->getType() == carType && cars->getAvailability())
        {
            filteredCars.push_back(*cars);
            cout << "Car Id: " << cars->getNumber();
            cout << " Car type: " << cars->getType();
            cout << " Mileage: " << cars->getMileage();
            cout << " Rent price: " << cars->getrentPrice();
            cout << " Max power: " << cars->getMaxpower() << endl;
            chosen.setType(carType);
        }
    }

    if (filteredCars.size() == 0)
    {
        cout << "car type unavailable" << endl;
    }
    return filteredCars;
}
// vector<string> userInteraction::carRentalDetails(double number){

//}
void userInteraction::chooseCar()
{
    int number;
    string num;
    cout << "which car would you like? enter car number:" << endl;
    cin >> num;

    try
    {
        number = stoi(num);
        int count = 0;

        for (auto cars : c.carList)
        {
            
            if (cars->getNumber() == number && number != 0)
            {
                if(cars->getAvailability() == true){
                cars->setAvailability(false);
                this->chosen = *cars;

                }
                else{
                    cout<<"car unavailable try again"<<endl;
                }
                
                count++;
               
            }
        }
        if (count == 0)
        {
            cout << "car number does not exsist please try again:" << endl;
        }
    }
    catch (...)
    {
        cout << "Incorrect input please try again" << endl;
    }
}
void userInteraction::setNumberOfDays()
{
    string day;
    cout << "how many days would you like to rent the car:" << endl;
    cin >> day;
    try{
        if(stoi(day) > 0){
        days = stoi(day);
        invoice();}
        else{
            cout<<"invalid input try again"<<endl;
        }
    }
    catch (...)
    {
        cout << "Incorrect input please try again" << endl;
    }
    
}

void userInteraction::invoice()

{
   
    verifiedUser->addCars(chosen.getNumber());
    cout << "Invoice for user: " << verifiedUser->getUsername() << endl;
    cout << endl;
    cout << "Car details: " << endl;
    cout << "   Car Id: " << chosen.getNumber() << endl;
    cout << "   Car type: " << chosen.getType() << endl;
    cout << "   Mileage: " << chosen.getMileage() << endl;
    cout << "   Rent price: " << chosen.getrentPrice() << endl;
    cout << "   Max power: " << chosen.getMaxpower() << endl;
    cout << endl;
    cout << "days to be rented: " << days << endl;
    cout << endl;
    cout << "Total: " <<"$" <<chosen.getrentPrice() * days  <<endl;
}

void userInteraction::reset(){
     chosen = car(0.0, 0.0, 0, 0, "none",0);
      days = 0;
       


}


void userInteraction::update(){

    std::ofstream ofs("car.txt", std::ofstream::trunc);
        for (auto cars : c.carList){
            ofs << to_string(cars->getrentPrice())<<",";
            ofs << to_string(cars->getMaxpower())<<",";
            ofs << to_string(cars->getMileage())<<",";
            ofs << to_string(cars->getNumber())<<",";
            ofs << cars->getType()<<",";
            ofs << to_string(cars->getAvailability())<<endl;
            }
         ofs.close();

         std::ofstream ifs("userData.txt", std::ofstream::trunc);
        for (auto users : h.userList){
            ifs << users->getUsername()<<",";
            ifs << users->getPassword();
            if(users->getCars().size()!=0){

                for(auto cars: users->getCars()){
                    
                     ifs <<","<<to_string(cars) ;
                        

                }

                
            }
            ifs<<" "<<endl;
           }
         ifs.close();


}