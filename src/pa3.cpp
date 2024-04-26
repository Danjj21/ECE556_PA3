//-------------------------------------------------------------------------
// Routing Algorithm
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//
//-------------------------------------------------------------------------
// #include <fstream>
#include <iostream>
#include <string>
// #include <vector>
#include "pa3.h"
#include <chrono>

using namespace std;

int main(int argc, char *argv[]){

    auto start = std::chrono::high_resolution_clock::now();

    if (argc != ){
        std::cout << "Usage: ";
    }


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);


    std::cout << "Duration (s): " << duration.count() <<std::endl;


    return 0;

}