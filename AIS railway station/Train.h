#pragma once
#include <iostream>
using namespace std;
class Train
{
	string numberTrain;
	string departureTime;
	string arrivalTime;
	string arrivalStation;
public:
	Train() = default;
	Train(string numberTrain, string departureTime, string arrivalTime, string arrivalStation) : numberTrain{ numberTrain }, departureTime{ departureTime }, arrivalTime{ arrivalTime }, arrivalStation{ arrivalStation } {};
	string getNumTrain();
	string getDepTime();
	string getArrTime();
	string getArrStat();
	void setNumTrain(string numberTrain);
	void setDepTime(string departureTime);
	void setArrTime(string arrivalTIme);
	void setArrStat(string arrivalStation);
	void PrintTrain();
};

