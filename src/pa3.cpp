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

    if (argc != 3 ){
        std::cout << "Usage: ./pa3 <input_file_name> <output_file_name> ";
        exit(1);
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];
    STClass st;
    st.read(input_file);
    st.run();
    st.output_solution();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    // st.outputSolution(outputFile);

    std::cout << "Duration (s): " << duration.count() <<std::endl;


    return 0;

}