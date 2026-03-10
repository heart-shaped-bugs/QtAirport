#include <QDomDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // ui->aircraftTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    // ui->aircraftTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // ui->passengerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnAddAircraft_clicked() {
    // Создаём новый самолёт с временными данными
    Aircraft aircraft;
    aircraft.setId(aircraftList.size() + 1);
    aircraft.setModel(QString("Новая модель"));
    aircraft.setCapacity(100);
    aircraft.setAirline(QString("Новая авиакомпания"));

    // Добавляем в список
    aircraftList.append(aircraft);

    // Обновляем таблицу
    int row = ui->aircraftTable->rowCount();
    ui->aircraftTable->insertRow(row);

    ui->aircraftTable->setItem(row, 0, new QTableWidgetItem(QString::number(aircraft.getId())));
    ui->aircraftTable->setItem(row, 1, new QTableWidgetItem(aircraft.getModel()));
    ui->aircraftTable->setItem(row, 2, new QTableWidgetItem(QString::number(aircraft.getCapacity())));
    ui->aircraftTable->setItem(row, 3, new QTableWidgetItem(aircraft.getAirline()));
}

void MainWindow::on_btnDeleteAircraft_clicked() {
    int row = ui->aircraftTable->currentRow();

    if (row >= 0 && row < aircraftList.size()) {
        aircraftList.removeAt(row);
        ui->aircraftTable->removeRow(row);

        // Обновляем ID у оставшихся самолётов
        for (int i = 0; i < aircraftList.size(); ++i) {
            aircraftList[i].setId(i + 1);
            ui->aircraftTable->setItem(i, 0, new QTableWidgetItem(QString::number(aircraftList[i].getId())));
        }
    }
}

void MainWindow::on_btnEditAircraft_clicked() {
    for (int i = 0; i < aircraftList.size(); ++i) {
        QTableWidgetItem* item = ui->aircraftTable->item(i, 1);
        QString value = item->text();
        aircraftList[i].setModel(value);

        item = ui->aircraftTable->item(i, 2);
        value = item->text();
        aircraftList[i].setCapacity(value.toUInt());

        item = ui->aircraftTable->item(i, 3);
        value = item->text();
        aircraftList[i].setAirline(value);

        ui->aircraftTable->setItem(i, 1, new QTableWidgetItem(aircraftList[i].getModel()));
        ui->aircraftTable->setItem(i, 2,
                                   new QTableWidgetItem(QString::number(aircraftList[i].getCapacity())));
        ui->aircraftTable->setItem(i, 3, new QTableWidgetItem(aircraftList[i].getAirline()));
    }
}

void MainWindow::on_btnSaveAircraft_clicked() {
    // Открываем диалог сохранения файла
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить самолёты", "", "XML файлы (*.xml)");

    if (!fileName.isEmpty()) {
        // Создаём XML документ
        QDomDocument doc;
        QDomElement root = doc.createElement("AircraftList");
        doc.appendChild(root);

        // Сохраняем каждый самолёт
        // Сохраняем каждый самолёт (используем индексацию вместо range-loop)
        for (int i = 0; i < aircraftList.size(); ++i) {
            const Aircraft& aircraft = aircraftList[i];

            QDomElement aircraftElement = doc.createElement("Aircraft");

            QDomElement idElement = doc.createElement("Id");
            idElement.appendChild(doc.createTextNode(QString::number(aircraft.getId())));
            aircraftElement.appendChild(idElement);

            QDomElement modelElement = doc.createElement("Model");
            modelElement.appendChild(doc.createTextNode(aircraft.getModel()));
            aircraftElement.appendChild(modelElement);

            QDomElement capacityElement = doc.createElement("Capacity");
            capacityElement.appendChild(doc.createTextNode(QString::number(aircraft.getCapacity())));
            aircraftElement.appendChild(capacityElement);

            QDomElement airlineElement = doc.createElement("Airline");
            airlineElement.appendChild(doc.createTextNode(aircraft.getAirline()));
            aircraftElement.appendChild(airlineElement);

            root.appendChild(aircraftElement);
        }

        // Записываем в файл
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            doc.save(out, 4);
            file.close();

            QMessageBox::information(this, "Успех", "Данные успешно сохранены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл!");
        }
    }
}

void MainWindow::on_btnLoadAircraft_clicked() {
    // Открываем диалог открытия файла
    // QString fileName = QFileDialog::getOpenFileName(this, "Загрузить самолёты", "", "XML файлы (*.xml)");
    QString fileName =
        QFileDialog::getOpenFileName(this, "Загрузить самолёты", "", "XML файлы (*.xml);;All files (*)");

    if (!fileName.isEmpty()) {
        // Очищаем текущие данные
        aircraftList.clear();
        ui->aircraftTable->setRowCount(0);

        // Читаем файл
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QDomDocument doc;
            if (doc.setContent(&file)) {
                QDomElement root = doc.documentElement();
                QDomNodeList aircraftNodes = root.elementsByTagName("Aircraft");

                for (int i = 0; i < aircraftNodes.count(); ++i) {
                    QDomElement aircraftElement = aircraftNodes.at(i).toElement();

                    Aircraft aircraft;
                    aircraft.setId(aircraftElement.firstChildElement("Id").text().toInt());
                    aircraft.setModel(aircraftElement.firstChildElement("Model").text());
                    aircraft.setCapacity(aircraftElement.firstChildElement("Capacity").text().toInt());
                    aircraft.setAirline(aircraftElement.firstChildElement("Airline").text());

                    aircraftList.append(aircraft);

                    // Добавляем в таблицу
                    int row = ui->aircraftTable->rowCount();
                    ui->aircraftTable->insertRow(row);

                    ui->aircraftTable->setItem(row, 0,
                                               new QTableWidgetItem(QString::number(aircraft.getId())));
                    ui->aircraftTable->setItem(row, 1, new QTableWidgetItem(aircraft.getModel()));
                    ui->aircraftTable->setItem(row, 2,
                                               new QTableWidgetItem(QString::number(aircraft.getCapacity())));
                    ui->aircraftTable->setItem(row, 3, new QTableWidgetItem(aircraft.getAirline()));
                }
            }

            file.close();
            QMessageBox::information(this, "Успех", "Данные успешно загружены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        }
    }
}

void MainWindow::on_btnAddPassenger_clicked() {
    Passenger passenger;

    passenger.setId(passengerList.size() + 1);
    passenger.setFirstName(QString("Имя"));
    passenger.setLastName(QString("Фамилия"));
    passenger.setFlightNumber(QString("A-118"));

    passengerList.append(passenger);

    int row = ui->passengerTable->rowCount();
    ui->passengerTable->insertRow(row);

    ui->passengerTable->setItem(row, 0, new QTableWidgetItem(QString::number(passenger.getId())));
    ui->passengerTable->setItem(row, 1, new QTableWidgetItem(passenger.getFirstName()));
    ui->passengerTable->setItem(row, 2, new QTableWidgetItem(passenger.getLastName()));
    ui->passengerTable->setItem(row, 3, new QTableWidgetItem(passenger.getFlightNumber()));
}

void MainWindow::on_btnDeletePassenger_clicked() {
    int row = ui->passengerTable->currentRow();

    if (row >= 0 && row < passengerList.size()) {
        passengerList.removeAt(row);
        ui->passengerTable->removeRow(row);

        for (int i = 0; i < passengerList.size(); ++i) {
            passengerList[i].setId(i + 1);
            ui->passengerTable->setItem(i, 0,
                                        new QTableWidgetItem(QString::number(passengerList[i].getId())));
        }
    }
}

void MainWindow::on_btnEditPassenger_clicked() {
    for (int i = 0; i < passengerList.size(); ++i) {
        QTableWidgetItem* item = ui->passengerTable->item(i, 1);
        QString value = item->text();
        passengerList[i].setFirstName(value);

        item = ui->passengerTable->item(i, 2);
        value = item->text();
        passengerList[i].setLastName(value);

        item = ui->passengerTable->item(i, 3);
        value = item->text();
        passengerList[i].setFlightNumber(value);

        ui->passengerTable->setItem(i, 1, new QTableWidgetItem(passengerList[i].getFirstName()));
        ui->passengerTable->setItem(i, 2, new QTableWidgetItem(passengerList[i].getLastName()));
        ui->passengerTable->setItem(i, 3, new QTableWidgetItem(passengerList[i].getFlightNumber()));
    }
}

void MainWindow::on_btnSavePassenger_clicked() {
    // Открываем диалог сохранения файла
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить пассажиров", "", "XML файлы (*.xml)");

    if (!fileName.isEmpty()) {
        // Создаём XML документ
        QDomDocument doc;
        QDomElement root = doc.createElement("PassengerList");
        doc.appendChild(root);

        // Сохраняем каждого пассажира (используем индексацию)
        for (int i = 0; i < passengerList.size(); ++i) {
            const Passenger& passenger = passengerList[i];

            QDomElement passengerElement = doc.createElement("Passenger");

            QDomElement idElement = doc.createElement("Id");
            idElement.appendChild(doc.createTextNode(QString::number(passenger.getId())));
            passengerElement.appendChild(idElement);

            QDomElement firstNameElement = doc.createElement("FirstName");
            firstNameElement.appendChild(doc.createTextNode(passenger.getFirstName()));
            passengerElement.appendChild(firstNameElement);

            QDomElement lastNameElement = doc.createElement("LastName");
            lastNameElement.appendChild(doc.createTextNode(passenger.getLastName()));
            passengerElement.appendChild(lastNameElement);

            QDomElement flightNumberElement = doc.createElement("FlightNumber");
            flightNumberElement.appendChild(doc.createTextNode(passenger.getFlightNumber()));
            passengerElement.appendChild(flightNumberElement);

            root.appendChild(passengerElement);
        }

        // Записываем в файл
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            doc.save(out, 4);
            file.close();

            QMessageBox::information(this, "Успех", "Данные успешно сохранены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл!");
        }
    }
}

void MainWindow::on_btnLoadPassenger_clicked() {
    // Открываем диалог открытия файла
    QString fileName =
        QFileDialog::getOpenFileName(this, "Загрузить пассажиров", "", "XML файлы (*.xml);;All files (*)");

    if (!fileName.isEmpty()) {
        // Очищаем текущие данные
        passengerList.clear();
        ui->passengerTable->setRowCount(0);

        // Читаем файл
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QDomDocument doc;
            if (doc.setContent(&file)) {
                QDomElement root = doc.documentElement();
                QDomNodeList passengerNodes = root.elementsByTagName("Passenger");

                for (int i = 0; i < passengerNodes.count(); ++i) {
                    QDomElement passengerElement = passengerNodes.at(i).toElement();

                    Passenger passenger;
                    passenger.setId(passengerElement.firstChildElement("Id").text().toInt());
                    passenger.setFirstName(passengerElement.firstChildElement("FirstName").text());
                    passenger.setLastName(passengerElement.firstChildElement("LastName").text());
                    passenger.setFlightNumber(passengerElement.firstChildElement("FlightNumber").text());

                    passengerList.append(passenger);

                    // Добавляем в таблицу
                    int row = ui->passengerTable->rowCount();
                    ui->passengerTable->insertRow(row);

                    ui->passengerTable->setItem(row, 0,
                                                new QTableWidgetItem(QString::number(passenger.getId())));
                    ui->passengerTable->setItem(row, 1, new QTableWidgetItem(passenger.getFirstName()));
                    ui->passengerTable->setItem(row, 2, new QTableWidgetItem(passenger.getLastName()));
                    ui->passengerTable->setItem(row, 3, new QTableWidgetItem(passenger.getFlightNumber()));
                }
            }

            file.close();
            QMessageBox::information(this, "Успех", "Данные успешно загружены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        }
    }
}
