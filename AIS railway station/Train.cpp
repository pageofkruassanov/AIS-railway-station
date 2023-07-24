#include "Train.h"

string Train::getNumTrain()
{
    return numberTrain;
}

string Train::getDepTime()
{
    return departureTime;
}

string Train::getArrTime()
{
    return arrivalTime;
}

string Train::getArrStat()
{
    return arrivalStation;
}

void Train::setNumTrain(string numberTrain)
{
    this->numberTrain = numberTrain;
}

void Train::setDepTime(string departureTime)
{
    this->departureTime = departureTime;
}

void Train::setArrTime(string arrivalTIme)
{
    this->arrivalTime = arrivalTIme;
}

void Train::setArrStat(string arrivalStation)
{
    this->arrivalStation = arrivalStation;
}

void Train::PrintTrain()
{
    cout << "Номер поезда: " << numberTrain << endl;
    cout << "Время отъезда: " << departureTime << endl;
    cout << "Время прибытия: " << arrivalTime << endl;
    cout << "Станция прибытия: " << arrivalStation << endl;
}
