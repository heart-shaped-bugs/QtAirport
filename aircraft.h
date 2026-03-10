#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <QString>

class Aircraft {
   public:
    Aircraft();
    Aircraft(int id, const QString& model, int capacity, const QString& airline);

    int getId() const;
    QString getModel() const;
    int getCapacity() const;
    QString getAirline() const;

    void setId(int value);
    void setModel(const QString& value);
    void setCapacity(int value);
    void setAirline(const QString& value);

   private:
    int id;
    QString model;
    int capacity;
    QString airline;
};

#endif
