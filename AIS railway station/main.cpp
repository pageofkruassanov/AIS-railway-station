#include <iostream>
#include <vector>
#include "Train.h"
#include <conio.h>


int main()
{
    setlocale(0, "Rus");
    // menu data:

    const int sizeMenu = 5;
    const string menu[sizeMenu] = { "Добавить поезд в систему", "Удалить поезд из системы", "Вывести информация про все поезда", "Вывести информацию о поезде", "Выйти из системы"};
    int arrow = 0;
    bool isMenu = 1;

    // main data:
    const int sizePlus = 100;
    int sizeVector = sizePlus;
    int currentSize = 0;
    vector<Train> trains;
    trains.reserve(sizeVector);

    while (isMenu) {
        system("cls");
        for (int i = 0; i < sizeMenu; i++) {
            if (arrow == i) {
                cout << "->" << menu[i] << endl;
            }
            else {
                cout << "  " << menu[i] << endl;
            }
        }

        char button = _getch();
        switch (button) {
        case 'w': {
            if (arrow == 0)
                arrow = 4;
            else
                --arrow;
            break;
        }
        case 's': {
            if (arrow == 4)
                arrow = 0;
            else
                ++arrow;
            break;
        }
        // ENTER:
        case 13: {
            //add train:
            if (arrow == 0) {
                system("cls");
                if (currentSize == sizeVector) {
                    trains.resize(sizeVector + sizePlus);
                    sizeVector += sizePlus;
                }
                string numberTrain;
                string departureTime;
                string arrivalTime;
                string arrivalStation;
                cout << "Введите номер поезда: ";
                cin >> numberTrain;
                cout << endl << "Введите время отъезда поезда: ";
                cin >> departureTime;
                cout << endl << "Введите время прибытия поезда: ";
                cin >> arrivalTime;
                cout << endl << "Введите станцию прибытия поезда: ";
                cin >> arrivalStation;
                Train tempTrain(numberTrain, departureTime, arrivalTime, arrivalStation);
                trains.push_back(tempTrain);
                cout << endl << "-----------------" << endl << "Поезд успешно добавлен!" << endl;
                ++currentSize;
                system("pause");
            }
            // delete train:
            else if (arrow == 1) {
                system("cls");
                if (currentSize == 0) {
                    cout << "Список поездов пуст!" << endl;
                    system("pause");
                }
                else {
                    string numberTrain;
                    cout << "Введите номер поезда для удаления: ";
                    cin >> numberTrain;
                    int result;
                    for (int i = 0; i < currentSize; i++) {
                        result = numberTrain.compare(trains[i].getNumTrain());
                        if (result == 0) {
                            cout << "Поезд " << trains[i].getNumTrain() << " удален успешно!";
                            trains.erase(trains.begin() + i);
                            --currentSize;
                            system("pause");
                            break;
                        }
                    }
                    if (result != 0) {
                        cout << endl << "Поезд с таким номер не найден!" << endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
            // show all trains:
            else if (arrow == 2) {
                system("cls");
                if (currentSize == 0) {
                    cout << "Список поездов пуст!" << endl;
                    system("pause");
                }
                else {
                    for (int i = 0; i < currentSize; i++) {
                        cout << "---------------" << endl;
                        trains[i].PrintTrain();
                        cout << "---------------" << endl;
                    }
                    system("pause");
                }
            }
            // show one train:
            else if (arrow == 3) {
                system("cls");
                if (currentSize == 0) {
                    cout << "Список поездов пуст!" << endl;
                    system("pause");
                }
                else {
                    string numberTrain;
                    cout << "Введите номер поезда для поиска: ";
                    cin >> numberTrain;
                    int result;
                    for (int i = 0; i < currentSize; i++) {
                        result = numberTrain.compare(trains[i].getNumTrain());
                        if (result == 0) {
                            trains[i].PrintTrain();
                            system("pause");
                            break;
                        }
                    }
                    if (result != 0) {
                        cout << endl << "Поезд с таким номер не найден!" << endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
            // exit:
            else if (arrow == 4) {
                isMenu = 0;
                system("cls");
            }
            break;
        }
        // ESC
        case 27: {
            system("cls");
            isMenu = 0; 
            break;
        }
        }
    }
    return 0;
}