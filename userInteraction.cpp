#include <iostream>
#include <vector>
#include "userInteraction.h"
#include <fstream>
#include <string.h>

using namespace std;

userInteraction::userInteraction(string userFile, string carFile) : verifiedUser("0", "0"), chosen(0.0, 0.0, 0, 0, "none",0), days(0), h(userFile), c(carFile)
{
}
bool userInteraction::getVerifiedUser()
{
    if (verifiedUser.getUsername() == "0")
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
   
    
    cout << "Invoice for user: " << verifiedUser.getUsername() << endl;
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
       std::ofstream ofs("car.txt", std::ofstream::trunc);
        for (auto cars : c.carList){
            ofs << to_string(cars->getrentPrice())<<",";
            ofs << to_string(cars->getMaxpower())<<",";
            ofs << to_string(cars->getMileage())<<",";
            ofs << to_string(cars->getNumber())<<",";
            ofs << cars->getType()<<",";
            ofs << to_string(cars->getAvailability())<<endl;;



        }


       
         ofs.close();


}

  


   
