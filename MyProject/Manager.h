#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Manager {
public:
    // Function to read data from binary files
    virtual void readBinaryFiles(string filename);

    // Function to write data to binary files
    virtual void writeBinaryFiles() = 0;

    // Function to read data from text files
    virtual void readTextFiles(string filename);

    // Function to write data to text files
    virtual void writeTextFiles() = 0;

    // Display object
    virtual void printInfo();
};
