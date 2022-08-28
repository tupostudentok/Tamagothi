#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Tamagotchi;

class TamagotchiView {
    
public:
    friend class Tamagotchi;
    void printTamagotchi(int& happiness, int& fattigue, int& heal){
        if (happiness == 0 || fattigue == 100 || heal == 0)   cout  << " -----------------------------------       " << endl
                                                                    << "|                                   |      " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|      \\   /        \\   /            |   " << endl
                                                                    << "|       \\ /          \\ /              |  " << endl
                                                                    << "|        /\\           /\\               | " << endl
                                                                    << "|       /  \\         /  \\           |    " << endl                                                                                                                                                                                               
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|            _________               |     " << endl
                                                                    << "|           /        \\              |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << " ------------------------------------      " << endl;

        if (happiness == 50 || fattigue == 50 || heal == 50) cout   << " -----------------------------------       " << endl
                                                                    << "|                                   |      " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|       ______       ______            |   " << endl
                                                                    << "|      \\    /      \\    /             |  " << endl
                                                                    << "|       \\  /        \\  /               | " << endl
                                                                    << "|        \\/          \\/             |    " << endl                                                                                                                                
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|            _________               |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << " ------------------------------------      " << endl;

        if (happiness == 90 || fattigue == 10 || heal == 90) cout  << " -----------------------------------       " << endl
                                                                    << "|                                   |      " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                      |   " << endl
                                                                    << "|         /\\           /\\               |  " << endl
                                                                    << "|        /  \\         /  \\               | " << endl
                                                                    << "|       /____\\       /____\\           |    " << endl                                                                                                                                
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|           \\_________/              |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << "|                                    |     " << endl
                                                                    << " ------------------------------------      " << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                        
    }
};