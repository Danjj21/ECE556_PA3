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

    if (argc != 3){
        std::cout << "Usage: [executable file name] [input file name] [output file name]";
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    STClass st;

    st.readInput(inputFile);

    // st.run();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    // st.outputSolution(outputFile);

    std::cout << "Duration (s): " << duration.count() <<std::endl;


    return 0;

}