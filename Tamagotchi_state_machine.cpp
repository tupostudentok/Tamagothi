#include "Tamagotchi.h"
#include <iostream>
#include <mutex>
#include <thread>

#define LINE20 "--------------------" // макросы для ввода и вывода конечного автомата  
#define INPUT  "<< INPUT >> "
#define OUTPUT "<< OUTPUT >> "

using namespace std;





int main() {
    printf("\e[8;%d;%d;t", 30, 120); // вывод консоли с размерами 30х120
    fflush(stdout);
    system ("clear");

    enum command_code { FEED, SLEEP, WALK, DRINK, CARESS, HELP, EXIT, INPUT_COMMAND };   
    int  command;
    string line;

    cout << "Привет! Меня зовут Роберт, чем мы будем заниматься? " << endl;

    Tamagotchi Robert;
    thread RoberPoints(&Tamagotchi::getTam, ref(Robert));
    RoberPoints.detach();
    this_thread::sleep_for(chrono::microseconds(1));
    
    mutex mcin;
    command = INPUT_COMMAND; // присвоение начального состояния 
    

    cout << "\nSTART:" << endl; // вывод макросов
    cout << LINE20 << endl;


    cout << OUTPUT << "Для ознакомелнения с командами введите HELP" << endl;
    while(true){
        if (command == INPUT_COMMAND){ // проверка, находится ли программа в начальном состоянии
            mcin.lock();
            cout << INPUT; cin >> line; // ввод пользователем команды
            mcin.unlock();
        }
        if(line == "HELP") { // проверка введена ли команда "помощь"
            command = HELP; 
            Robert.help();
            command = INPUT_COMMAND; // присвоение команде начального состояния
        } 
        if (line == "FEED"){
            command = FEED;
            Robert.feedTam();
            cout << OUTPUT << "Ммм, как вкусно..." << endl;
            command = INPUT_COMMAND;
        }
        if (line == "SLEEP"){
            command = SLEEP;
            Robert.sleepTam();
            cout << OUTPUT << "Zzzzzzzzzz..." << endl;
            command = INPUT_COMMAND;
        }
        if (line == "DRINK"){
            command = DRINK;
            Robert.drinkTam();
            cout << OUTPUT << "Я не напился..." << endl;
            command = INPUT_COMMAND;
        }
        if (line == "WALK"){
            command = WALK;
            Robert.walkTam();
            cout << OUTPUT << "Ура, наконец-то гулять!!!" << endl;
            command = INPUT_COMMAND;
        }
        if (line == "CARESS"){
            command = CARESS;
            Robert.caressTam();
            cout << OUTPUT << "Неееет, не надо меня гладить, неееет... А вообще прикольно." << endl;
            command = INPUT_COMMAND;
        }
        if (line == "EXIT"){
            command = EXIT;
            Robert.exit();
            cout << OUTPUT << "Прощай... Только приходи почаще! Без тебя мне совсем скучно..." << endl;
            break;
        }

    }
    
    cout << LINE20 << endl; // вывод макроса 
    cout << "STOP:" << endl;

    
    return 0;
}