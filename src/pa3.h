#ifndef pa3_h
#define pa3_h

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <variant>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <climits>
#include <deque>
#include <cmath>
#include <random>

//struct declarations
struct Pin{
    char name[20];
    size_t x = 0;
    size_t y = 0;
};


    class STClass
    {
    public:
        int boundary_x;
        int boundary_y;
        int num_pins;
        std::vector<Pin*> pins;

    
        void readInput(std::string inputFile){
           std::string line;
           std::ifstream readfile(inputFile, std::ios::in);
           std::getline(readfile,line);
           sscanf(line.c_str(), "Boundary = (0,0), (%d,%d)", &boundary_x, &boundary_y); //Boundary = (0,0), (100,100)
           std::cout<<"boundary_x: "<<boundary_x<<std::endl;
           std::cout<<"boundary_y: "<<boundary_y<<std::endl;
           std::getline(readfile,line);
           sscanf(line.c_str(), "NumPins = %d", &num_pins);
           std::cout<<"num_pins: "<<num_pins<<std::endl;
           char name1[20] = "test";
           for(auto i = 0; i < num_pins; i++){
                Pin* new_pin = new Pin;
                std::getline(readfile,line);
                sscanf(line.c_str(), "PIN %s (%d,%d)", &new_pin->name, &new_pin->x, &new_pin->y); //PIN p0 (88,34)
               pins.push_back(new_pin);
           }
           outputPins();
        }


    private:

        void outputPins(void){
            for(auto pin: pins){
                std::cout<<"name: "<<pin->name<<" x: "<<pin->x<<" y: "<<pin->y<<std::endl;
            }
        }
    };


#endif
