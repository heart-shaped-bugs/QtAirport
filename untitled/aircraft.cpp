#include "aircraft.h"

Aircraft::Aircraft(): id(0), capacity(0){}

Aircraft::Aircraft(int id, const QString &model, int capacity, const QString &airline):
    id(id), model(model), capacity(capacity), airline(airline){

}

int Aircraft::getId() const {
    return id;
}

QString Aircraft::getModel() const {
    return model;
}

int Aircraft::getCapacity() const {
    return capacity;
}

QString Aircraft::getAirline() const {
    return airline;
}

void Aircraft::setId(int value) {
    id = value;
}

void Aircraft::setModel(const QString &value) {
    model = value;
}

void Aircraft::setCapacity(int value) {
    capacity = value;
}

void Aircraft::setAirline(const QString &value) {
    airline = value;
}
