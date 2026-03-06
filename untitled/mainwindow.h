#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "aircraft.h"
#include "passenger.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QVector<Aircraft> aircraftList;
    QVector<Passenger> passengerList;

private slots:
    // Слоты для самолётов
    void on_btnAddAircraft_clicked();
    void on_btnDeleteAircraft_clicked();
    void on_btnEditAircraft_clicked();
    void on_btnSaveAircraft_clicked();
    void on_btnLoadAircraft_clicked();

    // Слоты для пассажиров
    void on_btnAddPassenger_clicked();
    void on_btnDeletePassenger_clicked();
    void on_btnEditPassenger_clicked();
    void on_btnSavePassenger_clicked();
    void on_btnLoadPassenger_clicked();

};
#endif // MAINWINDOW_H
