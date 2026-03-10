#include "passenger.h"

Passenger::Passenger() : id(0) {}

Passenger::Passenger(int id, const QString& firstName, const QString& lastName, const QString& flightNumber)
    : id(id), firstName(firstName), lastName(lastName), flightNumber(flightNumber) {}

int Passenger::getId() const { return id; }

QString Passenger::getFirstName() const { return firstName; }

QString Passenger::getLastName() const { return lastName; }

QString Passenger::getFlightNumber() const { return flightNumber; }

void Passenger::setId(int value) { id = value; }

void Passenger::setFirstName(const QString& value) { firstName = value; }

void Passenger::setLastName(const QString& value) { lastName = value; }

void Passenger::setFlightNumber(const QString& value) { flightNumber = value; }
