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
    int x = 0;
    int y = 0;
};


    class STClass
    {
    public:
        int boundary_x;
        int boundary_y;
        int num_pins;
        int min_y = 0;
        int max_y = 0;
        int min_x = 0;
        int max_x = 0;
        int center_x;
        int center_y;
        long wirelength = 0;
        std::vector<Pin*> pins;
        std::vector<std::pair<int,int>> Vline;
        std::vector<int> Vline_x;
        std::vector<std::pair<int,int>> Hline;

    
        void read(std::string inputFile){
           std::string line;
           std::ifstream readfile(inputFile, std::ios::in);
           std::getline(readfile,line);
           sscanf(line.c_str(), "Boundary = (0,0), (%d,%d)", &boundary_x, &boundary_y); //Boundary = (0,0), (100,100)
           std::cout<<"boundary_x: "<<boundary_x<<std::endl;
           std::cout<<"boundary_y: "<<boundary_y<<std::endl;

            min_y = boundary_y;
            min_x = boundary_x;

           std::getline(readfile,line);
           sscanf(line.c_str(), "NumPins = %d", &num_pins);
           std::cout<<"num_pins: "<<num_pins<<std::endl;
           char name1[20] = "test";
           for(auto i = 0; i < num_pins; i++){
                Pin* new_pin = new Pin;
                std::getline(readfile,line);
                sscanf(line.c_str(), "PIN %s (%d,%d)", &new_pin->name, &new_pin->x, &new_pin->y); //PIN p0 (88,34)
                if (new_pin->x < min_x){
                    min_x = new_pin->x;
                }
                if (new_pin->x > max_x){
                    max_x = new_pin->x;
                }
                if (new_pin->y < min_y){
                    min_y= new_pin->y;
                }
                if (new_pin->y > max_y){
                    max_y = new_pin->y;
                }
               pins.push_back(new_pin);
           }
           center_x = (max_x - min_x) / 2;
           center_y = (max_y - min_y) / 2;

        //    outputPins();
        }

        void run() {
            for(auto pin: pins){
                Vline.emplace_back(std::make_pair(pin->y, center_y));
                Vline_x.emplace_back(pin->x);
                wirelength += abs(pin->y - center_y);
            }
            Hline.emplace_back(std::make_pair(min_x, max_x));
            wirelength += max_x - min_y;

        }

        void outputSolution(std::string outputFile) {
            std::string print_op = outputFile;
            std::ofstream outFile(print_op, std::ios::out);

            outFile << "NumRoutedPins = "<<num_pins<<"\n";
            outFile << "WireLength = "<<wirelength<<"\n";

            for (int i = 0; i < Vline.size(); i++){ //V-line (50,30) (50,90) 
                outFile << "V-line ("<<Vline_x[i] <<","<<Vline[i].first<<") ("<<Vline_x[i] <<","<<Vline[i].second<<")\n";
            } //H-line (20,30) (50,30)
            outFile << "H-line ("<<min_x<<","<<center_y<<") ("<<max_x<<","<<center_y<<")\n";


        }

    private:

        void outputPins(void){
            for(auto pin: pins){
                std::cout<<"name: "<<pin->name<<" x: "<<pin->x<<" y: "<<pin->y<<std::endl;
            }
        }
    };


#endif
