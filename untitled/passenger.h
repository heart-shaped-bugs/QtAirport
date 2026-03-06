#ifndef PASSENGER_H
#define PASSENGER_H
#include "QString"

class Passenger {
public:
    Passenger();
    Passenger(int id, const QString &firstName, const QString &lastName, const QString &flightNumber);

    int getId() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getFlightNumber() const;

    void setId(int value);
    void setFirstName(const QString &value);
    void setLastName(const QString &value);
    void setFlightNumber(const QString &value);

private:
    int id;
    QString firstName;
    QString lastName;
    QString flightNumber;
};

#endif // PASSENGER_H
