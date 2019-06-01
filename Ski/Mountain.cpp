//
//  Mountain.cpp
//  Ski
//
//  Created by Cheling Lim on 31/1/18.
//  Copyright © 2018 Cheling Lim. All rights reserved.
//

#include "Mountain.h"
#include <iostream>
#include <fstream>
#include <cstdlib> //for exit(1)

bool Mountain::isDescending(const int row, const int col, const short elevation)
//map.data[row][col] is the elevation of adjacent area
//elevation is the area which is currently on
//If the adjacent elevation is smaller than current elevation, then it is descending
{
    if(row < 0 | col < 0 | row >= numRow | col >= numCol ) //data[row][col] is the elevation of adjacent area
        return false; //Not Descending as there is not such adjacent area
    else
        return (elevation > data[row][col]);
}

//Private function to be called from findLongestPath()
void Mountain::creatingPath(unsigned int row, unsigned int col, bool bPeak)
{
    int north, south, west, east;
    
    north = row - 1;
    south = row + 1;
    west = col - 1;
    east = col + 1;
    
    if(bPeak){
        path.push_back(data[row][col]);
    }
    
    //Check four directions for a lower area
    //North
    if (isDescending(north, col, data[row][col]))
    {
        path.push_back(data[north][col]);
        creatingPath(north, col, false);
    }
    
    //South
    if(isDescending(south, col, data[row][col]))
    {
        path.push_back(data[south][col]);
        creatingPath(south, col, false);
    }
    
    //West
    if (isDescending(row, west, data[row][col]))
    {
        path.push_back(data[row][west]);
        creatingPath(row, west, false);
    }
    
    //East
    if (isDescending(row, east, data[row][col]))
    {
        path.push_back(data[row][east]);
        creatingPath(row, east, false);
    }
    
    int newLength = static_cast<int>(path.size());
    int oldLength = static_cast<int>(longestSteepestPath.size());
    
    while(true)
    {
        if(newLength < oldLength)
            break;
        
        if(newLength == oldLength) //same length of path
        {
            //check drop
            if((path[0] - path[newLength - 1]) < (longestSteepestPath[0] - longestSteepestPath[oldLength -1]))
                break;
        }
        
        longestSteepestPath.clear();
        for (const auto &element: path)
        {
            longestSteepestPath.push_back(element);
            std::cout << element << ' ';
        }
        std::cout << '\n';
        break;
    }
    
    path.pop_back();
}


Mountain::Mountain(const std::string &filename)
{
    //Read file
    std::ifstream fMap(filename);
    if(!fMap){
        std::cerr << "map.txt cannot be read!";
        exit(1);
    }
    
    //Creating an array to hold all the map data
    fMap >> numRow;
    //std::cout << numRow << "   ";
    fMap >> numCol;
    //std::cout << numColumn << "    ";
    
    short temp;
    
    while(fMap){
        std::vector<short> row;
        
        for(int i = 0; i < numCol; i++)
        {
            fMap >> temp;
            row.push_back(temp);
            //getline(myMap, str);
        }
        data.push_back(row);
    }
}

const std::vector<short>& Mountain::findLongestPath()
{
    for(int row = 0; row < numRow; row++)
    {
        for(int col = 0; col < numCol; col++)
        {
            path.clear();
            creatingPath(row, col, true);
        }
    }
    
    return longestSteepestPath;
}
