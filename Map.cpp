//
//  Map.cpp
//  Lab3_HPAir_Backtracking
//
//  Created by Monica Amezquita
//  Data Structures 211
//  Copyright © 2017 Monica Amezquita. All rights reserved.
//
#include "Map.hpp"
#include "Stack.hpp"


void Map::unvisitedAll()
{
    for (int index = 0; index < MAX_CITIES; index++)
    {
        visited[index] = false;
    }
}

void Map::markVisited(City city)
{
    visited[city] = true;
}

City Map::getNextCity(City origin)
{
    City dest = NO_CITY;
    Node<City>* cityPtr = map[origin];
    while (cityPtr != nullptr && visited[cityPtr->getItem()])
        cityPtr = cityPtr->getNext();
    if (cityPtr != nullptr)
    {
        dest = cityPtr->getItem();
        markVisited(dest);
    }
    return dest;
}

bool Map::isPath(City originCity, City destinationCity)
{
    ArrayStack<City> cityStack;
    unvisitedAll(); //this will clear all of the marks from previous searches
    
    cityStack.push(originCity);
    markVisited(originCity);
    
    City topCity = cityStack.peek();
    while(!cityStack.isEmpty() && (topCity != destinationCity)) {
        City nextCity = getNextCity(topCity);
        if(nextCity == NO_CITY) {
            cityStack.pop();
        } else {
            cityStack.push(nextCity);
            markVisited(nextCity);
        }
        
        if(!cityStack.isEmpty()) {
            topCity = cityStack.peek();
        }
        
        return !cityStack.isEmpty();
    }
    return 0;
}
bool Map::isVisited(City city)
{
    return visited[city];
}
City Map::getIndex(string cityName)
{
    City city = 0;
    while (city < numCities && cities[city] != cityName)
        city++;
    if (city >= numCities)
        city = NO_CITY;
    return city;
}
void Map::insertAdjacent(City origin, City dest)
{
    Node<City>* cityPtr = new Node<City>(dest, map[origin]);
    map[origin] = cityPtr;
}
void Map::splitCities(string, string&, string&){} // probably not needed


Map::Map() : numCities(0)
{
    for (int index = 0; index < MAX_CITIES; index++)
    {
        cities[index] = "";
        visited[index] = false;
        map[index] = nullptr;
     
    }
}

void Map::readFlightMap(string city, string flightMap)
{
    ifstream cityFile(city.c_str());
    ifstream mapFile(flightMap.c_str());
    string cityName;
    int i = 0;
    
    //READ IN CITY FILE
    getline(cityFile, cityName);
    cities[i] = cityName;
    numCities++;
    while(!cityFile.eof()) {
        getline(cityFile, cityName);
        i++;
        cities[i] = cityName;
        numCities++;
    }
    
    
    ifstream pathsIn(flightMap.c_str());
    string destCity;
    int addfrom, addTo;
    while (getline(pathsIn, cityName, ','))
    {
        //cout << "From city " << cityName;
        getline(pathsIn, destCity);
        while (destCity.length() > 0 && destCity.at(0) == ' ')
            destCity = destCity.substr(1, destCity.length());
        //cout << " to " << destCity << endl;
        addfrom = getIndex(cityName);
        addTo = getIndex(destCity);
        insertAdjacent(addfrom, addTo);
    }
}

void Map::flights(string file)
{
    ifstream requestFile(file.c_str());
    string origin, destination;
    int originIndex, destIndex;
    bool path;
    
    while(getline(requestFile, origin, ',')) {
        originIndex = getIndex(origin);
        getline(requestFile, destination);
        while (destination.length() > 0 && destination.at(0) == ' ')
            destination = destination.substr(1, destination.length());
        destIndex = getIndex(destination);
        
        cout << "\nRequest is to fly from " << origin << " to " << destination << endl;
        
        if(originIndex == -1 || destIndex == -1) {
            if( originIndex == -1 && destIndex!=-1)
                cout << "Sorry. HPAir does not serve " << origin << ".'"<< endl;
            else if(destIndex == -1 && originIndex != -1)
                cout << "Sorry. HPAir does not serve " << destination << "." << endl;
            else
                cout << "Sorry. HPAir neither serves "<<origin << " nor " << destination << "."  <<  endl;
        }
        
        else
        {
            path = isPath(originIndex, destIndex);
            if(path)
                cout << "HPAir flies from " << origin << " to " << destination << "." << endl;
            else
                cout << "Sorry. HPAir does not fly from " << origin << " to " << destination << "." << endl;
        }
    }
    
}