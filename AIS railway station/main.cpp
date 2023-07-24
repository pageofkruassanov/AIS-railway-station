#include <iostream>
#include <vector>
#include "Train.h"
#include <conio.h>


int main()
{
    setlocale(0, "Rus");
    // menu data:

    const int sizeMenu = 5;
    const string menu[sizeMenu] = { "�������� ����� � �������", "������� ����� �� �������", "������� ���������� ��� ��� ������", "������� ���������� � ������", "����� �� �������"};
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
                cout << "������� ����� ������: ";
                cin >> numberTrain;
                cout << endl << "������� ����� ������� ������: ";
                cin >> departureTime;
                cout << endl << "������� ����� �������� ������: ";
                cin >> arrivalTime;
                cout << endl << "������� ������� �������� ������: ";
                cin >> arrivalStation;
                Train tempTrain(numberTrain, departureTime, arrivalTime, arrivalStation);
                trains.push_back(tempTrain);
                cout << endl << "-----------------" << endl << "����� ������� ��������!" << endl;
                ++currentSize;
                system("pause");
            }
            // delete train:
            else if (arrow == 1) {
                system("cls");
                if (currentSize == 0) {
                    cout << "������ ������� ����!" << endl;
                    system("pause");
                }
                else {
                    string numberTrain;
                    cout << "������� ����� ������ ��� ��������: ";
                    cin >> numberTrain;
                    int result;
                    for (int i = 0; i < currentSize; i++) {
                        result = numberTrain.compare(trains[i].getNumTrain());
                        if (result == 0) {
                            cout << "����� " << trains[i].getNumTrain() << " ������ �������!";
                            trains.erase(trains.begin() + i);
                            --currentSize;
                            system("pause");
                            break;
                        }
                    }
                    if (result != 0) {
                        cout << endl << "����� � ����� ����� �� ������!" << endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
            // show all trains:
            else if (arrow == 2) {
                system("cls");
                if (currentSize == 0) {
                    cout << "������ ������� ����!" << endl;
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
                    cout << "������ ������� ����!" << endl;
                    system("pause");
                }
                else {
                    string numberTrain;
                    cout << "������� ����� ������ ��� ������: ";
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
                        cout << endl << "����� � ����� ����� �� ������!" << endl;
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