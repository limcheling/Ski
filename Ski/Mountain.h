//
//  Map.h
//  Ski
//
//  Created by Cheling Lim on 18/1/18.
//  Copyright © 2018 Cheling Lim. All rights reserved.
//

#ifndef Mountain_h
#define Mountain_h

#include <iostream>
#include <string>
#include <vector>

class Mountain{
private:
    std::vector<std::vector <short>> data;
    int numRow = 0, numCol = 0;
    std::vector<short> longestSteepestPath;
    std::vector<short> path;
    
    bool isDescending(const int row, const int col, const short elevation);

    //For a specific area, return the longest and steepest path (&path)
    void creatingPath(unsigned int row, unsigned int col, bool bPeak);

public:
    Mountain(const std::string &filename);
    const std::vector<short>& findLongestPath();
};


#endif /* Mountain_h */
