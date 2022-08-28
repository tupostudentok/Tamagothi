#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include <thread>
#include <mutex>
#include <chrono>

#include "Tamagotchi_view.h"


#define OUTPUT "<< OUTPUT >> "

using namespace std;

class TamagotchiView;

class Tamagotchi {
    
private:
    int HEAL_POINTS = 100;
    int FATIGUE_POINTS = 0;
    int HAPPINESS_POINTS = 100;


    string changeScale(int& field){
        map<int, string> processBar {
                    {0, "[                     ]"},
                    {5, "[#                    ]"},
                    {10, "[##                   ]"},
                    {15, "[###                  ]"},
                    {20, "[####                 ]"},
                    {25, "[#####                ]"},
                    {30, "[######               ]"},
                    {35, "[#######              ]"},
                    {40, "[########             ]"},
                    {45, "[#########            ]"},
                    {50, "[##########           ]"},
                    {55, "[###########          ]"},
                    {60, "[############         ]"},
                    {65, "[#############        ]"},
                    {70, "[##############       ]"},
                    {75, "[###############      ]"},
                    {80, "[################     ]"},
                    {85, "[#################    ]"},
                    {90, "[###################  ]"},
                    {95, "[#################### ]"},
                    {100,"[#####################]"}
        };
        map<int, string> :: iterator it;
        it = processBar.find(field);
        if (it != processBar.end()){return it->second;}

    }

public:
    friend void TamagotchiView::printTamagotchi(int& happiness, int& fattigue, int& heal);

    Tamagotchi(){ 
        ifstream data_set ("safekeeping");
        if (data_set.good() == true){
            string line;
            int i = 1;
            while (getline (data_set, line)){
                if (i == 1) {HEAL_POINTS = stoi(line); i = 2;}
                else if (i == 2) {FATIGUE_POINTS = stoi(line); i = 3;}
                else if (i == 3) {HAPPINESS_POINTS = stoi(line); break;}
            }
        }
        data_set.close();           
    }
    void feedTam(){
        HEAL_POINTS += 30;
        HAPPINESS_POINTS += 20;
        if (HEAL_POINTS > 100) HEAL_POINTS = 100;
    }
    void sleepTam(){
        HAPPINESS_POINTS += 30;
        FATIGUE_POINTS -= 20;
        if (FATIGUE_POINTS < 0) FATIGUE_POINTS = 0;
        if (HAPPINESS_POINTS > 100) HAPPINESS_POINTS = 100;
    }
    void walkTam(){
        FATIGUE_POINTS -= 20;
        HAPPINESS_POINTS += 20;
        if (HAPPINESS_POINTS > 100) HAPPINESS_POINTS = 100;
        if (FATIGUE_POINTS < 0) FATIGUE_POINTS = 0;
    }
    void drinkTam(){
        HEAL_POINTS += 20;
        if (HEAL_POINTS > 100) HEAL_POINTS = 100;
    }
    void caressTam(){
        HAPPINESS_POINTS += 30;
        FATIGUE_POINTS -= 10;
        if (FATIGUE_POINTS < 0) FATIGUE_POINTS = 0;
        if (HAPPINESS_POINTS > 100) HAPPINESS_POINTS = 100;
    }
    void help(){
        cout << OUTPUT << endl // вывод справки по пользованию командой
                       << "Список команд: FEED, SLEEP, WALK, DRINK, CARESS, HELP, EXIT" << endl
                       << "FEED - покормить питомца (увеличивает очки здоровья)" << endl
                       << "SLEEP - уложить спать (увеличивает очки здоровья и уменьшает усталость)" << endl
                       << "WALK - погулять (увеличивает очки счастья и уменьшает усталость)" << endl
                       << "DRINK - попить (увеличивает очки здоровья)" << endl
                       << "CARESS - погладить (увеличивает очки счастья и уменьшает усталость)" << endl
                       << "HELP - вызов справки доступных командах" << endl
                       << "EXIT - выход из программы (прогресс автоматически сохраняется)" << endl;
    }
    
    void getTam(){
        
        while(true){
            mutex mutTam;
            TamagotchiView View;
            {             
                lock_guard<mutex> guard(mutTam);
                HEAL_POINTS-=1;
                printf("\rУровень жизни: %d\t", HEAL_POINTS);

                FATIGUE_POINTS+=1;
                printf("Уровень скуки: %d\t", FATIGUE_POINTS);

                HAPPINESS_POINTS-=1;
                printf("Уровень счастья: %d", HAPPINESS_POINTS);
                //View.printTamagotchi(HAPPINESS_POINTS, FATIGUE_POINTS, HEAL_POINTS);

                fflush(stdout);
            }
                this_thread::sleep_for(chrono::seconds(20));
        }

    }
    void exit(){
        ofstream data_set("safekeeping");
        data_set << HEAL_POINTS << endl;
        data_set << FATIGUE_POINTS << endl;
        data_set << HAPPINESS_POINTS <<endl;

        data_set.close();
    }

};
    