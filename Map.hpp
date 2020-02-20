//
//  Map.hpp
//  Lab3_HPAir_Backtracking
//
//  Created by Monica Amezquita
//  Data Structures 211
//  Copyright © 2017 Monica Amezquita. All rights reserved.
//

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Node.hpp"

using namespace std;

typedef int City;

const int MAX_CITIES = 50;
const City NO_CITY = -1;

class Map
{
private:
    string cities[MAX_CITIES];
    bool visited[MAX_CITIES];
   Node<City>* map[MAX_CITIES];
    int numCities;
   // bool adjacency[MAX_CITIES][MAX_CITIES];
    
    
    void unvisitedAll();
    void markVisited(City);
    City getNextCity(City);
    bool isPath(City, City);
    bool isVisited(City);
    City getIndex(string);
    void insertAdjacent(City, City);
    void splitCities(string, string&, string&);
    
public:
    Map();
    
    void readFlightMap(string, string);
    
    void flights(string);
    
};