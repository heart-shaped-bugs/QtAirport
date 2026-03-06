/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *btnLoadAircraft;
    QPushButton *btnEditAircraft;
    QPushButton *btnSaveAircraft;
    QPushButton *btnDeleteAircraft;
    QPushButton *btnAddAircraft;
    QTableWidget *aircraftTable;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QTableWidget *passengerTable;
    QPushButton *btnAddPassenger;
    QPushButton *btnDeletePassenger;
    QPushButton *btnEditPassenger;
    QPushButton *btnSavePassenger;
    QPushButton *btnLoadPassenger;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(698, 493);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 621, 371));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMouseTracking(false);
        tabWidget->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        btnLoadAircraft = new QPushButton(tab);
        btnLoadAircraft->setObjectName("btnLoadAircraft");

        gridLayout_2->addWidget(btnLoadAircraft, 1, 4, 1, 1);

        btnEditAircraft = new QPushButton(tab);
        btnEditAircraft->setObjectName("btnEditAircraft");

        gridLayout_2->addWidget(btnEditAircraft, 1, 2, 1, 1);

        btnSaveAircraft = new QPushButton(tab);
        btnSaveAircraft->setObjectName("btnSaveAircraft");

        gridLayout_2->addWidget(btnSaveAircraft, 1, 3, 1, 1);

        btnDeleteAircraft = new QPushButton(tab);
        btnDeleteAircraft->setObjectName("btnDeleteAircraft");

        gridLayout_2->addWidget(btnDeleteAircraft, 1, 1, 1, 1);

        btnAddAircraft = new QPushButton(tab);
        btnAddAircraft->setObjectName("btnAddAircraft");

        gridLayout_2->addWidget(btnAddAircraft, 1, 0, 1, 1);

        aircraftTable = new QTableWidget(tab);
        if (aircraftTable->columnCount() < 4)
            aircraftTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        aircraftTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        aircraftTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        aircraftTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        aircraftTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        aircraftTable->setObjectName("aircraftTable");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(aircraftTable->sizePolicy().hasHeightForWidth());
        aircraftTable->setSizePolicy(sizePolicy1);
        aircraftTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        aircraftTable->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        aircraftTable->setAutoFillBackground(false);
        aircraftTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        aircraftTable->setIconSize(QSize(0, 0));
        aircraftTable->setSortingEnabled(false);
        aircraftTable->setColumnCount(4);
        aircraftTable->horizontalHeader()->setVisible(true);
        aircraftTable->horizontalHeader()->setCascadingSectionResizes(false);
        aircraftTable->horizontalHeader()->setMinimumSectionSize(40);
        aircraftTable->horizontalHeader()->setDefaultSectionSize(150);
        aircraftTable->horizontalHeader()->setHighlightSections(true);
        aircraftTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        aircraftTable->horizontalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(aircraftTable, 0, 0, 1, 5);

        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName("gridLayout");
        passengerTable = new QTableWidget(tab_2);
        if (passengerTable->columnCount() < 4)
            passengerTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        passengerTable->setObjectName("passengerTable");
        passengerTable->setMouseTracking(false);
        passengerTable->setTabletTracking(false);
        passengerTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        passengerTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        passengerTable->setColumnCount(4);
        passengerTable->horizontalHeader()->setDefaultSectionSize(150);

        gridLayout->addWidget(passengerTable, 0, 0, 1, 5);

        btnAddPassenger = new QPushButton(tab_2);
        btnAddPassenger->setObjectName("btnAddPassenger");

        gridLayout->addWidget(btnAddPassenger, 1, 0, 1, 1);

        btnDeletePassenger = new QPushButton(tab_2);
        btnDeletePassenger->setObjectName("btnDeletePassenger");

        gridLayout->addWidget(btnDeletePassenger, 1, 1, 1, 1);

        btnEditPassenger = new QPushButton(tab_2);
        btnEditPassenger->setObjectName("btnEditPassenger");

        gridLayout->addWidget(btnEditPassenger, 1, 2, 1, 1);

        btnSavePassenger = new QPushButton(tab_2);
        btnSavePassenger->setObjectName("btnSavePassenger");

        gridLayout->addWidget(btnSavePassenger, 1, 3, 1, 1);

        btnLoadPassenger = new QPushButton(tab_2);
        btnLoadPassenger->setObjectName("btnLoadPassenger");

        gridLayout->addWidget(btnLoadPassenger, 1, 4, 1, 1);

        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        tabWidget->addTab(tab_2, icon1, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 698, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLoadAircraft->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        btnEditAircraft->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btnSaveAircraft->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnDeleteAircraft->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnAddAircraft->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = aircraftTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = aircraftTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = aircraftTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\274\320\265\321\201\321\202\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = aircraftTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\320\270\320\260\320\272\320\276\320\274\320\277\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\241\320\260\320\274\320\276\320\273\320\265\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = passengerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = passengerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = passengerTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = passengerTable->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\200\320\265\320\271\321\201\320\260", nullptr));
        btnAddPassenger->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnDeletePassenger->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnEditPassenger->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btnSavePassenger->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnLoadPassenger->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\237\320\260\321\201\321\201\320\260\320\266\320\270\321\200\321\213", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
