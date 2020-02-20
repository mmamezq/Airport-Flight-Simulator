//
//  main.cpp
//  Lab3_HPAir_Backtracking
//
//  Created by Monica Amezquita
//  Data Structures 211
//  Copyright © 2017 Monica Amezquita. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Map.hpp"


using namespace std;

int main()
{
    Map HPAir;
    string flight;
    string request;
    string city;
   cout << "Enter the file name for the flight map: ";
    cin >> flight;
    ifstream inFile(flight.c_str());
    while(inFile.fail()) {
        cout << "File " << flight << " does not exist."
            << "\nEnter the file name for the flight map or press q to quit: ";
        inFile.clear();
        cin.clear();
        cin >> flight;
        if(flight == "q" || flight == "Q"){
            cout << "You have quit the program" << endl;
            exit(1);
        }
        inFile.open(flight.c_str());
    }
    inFile.close();
    
    cout << "Enter the file name for the cities served file: ";
    cin >> city;
    ifstream cityFile(city.c_str());
    while(cityFile.fail()) {
        cout << "File " << city << " does not exist.\n"
        << "Enter the file name for the cities served or press q to quit: ";
        cityFile.clear();
        cin.clear();
        cin >> city;
        if(city == "q" || city == "Q"){
            cout << "You have quit the program" << endl;
            exit(1);
        }
        cityFile.open(request.c_str());
    }
    cityFile.close();
    
    cout << "Enter the file name for the request map: ";
    cin >> request;
    ifstream requestFile(request.c_str());
    while(requestFile.fail()) {
        cout << "File " << request << " does not exist.\n"
        << "Enter the file name for the flight map or press q to quit: ";
        requestFile.clear();
        cin.clear();
        cin >> request;
        if(request == "q" || request == "Q"){
            cout << "You have quit the program" << endl;
            exit(1);
        }
        requestFile.open(request.c_str());
    }
    requestFile.close();
    cout << endl << endl;
    
    HPAir.readFlightMap(city, flight);
    HPAir.flights(request);
    cout << endl;
}