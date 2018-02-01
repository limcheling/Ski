//
//  main.cpp
//  Ski
//
//  Created by Cheling Lim on 18/1/18.
//  Copyright © 2018 Cheling Lim. All rights reserved.
//

#include <iostream>
#include "Mountain.h"
#include <vector>

//const std::string FILENAME{"smallMap.txt"};
const std::string FILENAME{"map.txt"};

int main () {
    
    Mountain map(FILENAME);
 
    const std::vector<short>& longestSteepestPath = map.findLongestPath();
    
    std::cout << " \nAnswer(Path):  ";
    for (const auto &element: longestSteepestPath)
        std::cout << element << ' ';
    
    std::cout << " \nEmail:  " << longestSteepestPath.size() << longestSteepestPath[0]  - longestSteepestPath[longestSteepestPath.size()-1] <<  "@redmart.com\n";
    return 0;
}


