#ifndef MWIN_H
#define MWIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QFormLayout>
#include <QComboBox>
#include <QString>
#include <QSignalMapper>

#include "mydatastore.h"
#include "user.h"
#include <string>
#include <vector>

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow(MyDataStore*);
	~MainWindow();

private slots:

private:

// overall layout
	QHBoxLayout* fullLayout;

// left column widgets
	QVBoxLayout* leftLayout;
	QFormLayout* searchboxLayout;
	QLineEdit* searchInput;
	QPushButton* searchButton;
	QComboBox* andorSelect;
	QComboBox* abcratingSelect;
	QSignalMapper* mapper;

	//display searchresults
	QListWidget* searchResults;

// middle column
	QVBoxLayout* centerLayout;
	QFormLayout* productnameLine;
	QFormLayout* productqtyLine;
	QFormLayout* productpriceLine;
	QFormLayout* productratingLine;
	QFormLayout* productmiscLine;
	QFormLayout* productmiscLine2;

	QLabel* productStatic;
	QLabel* dollarStatic;
	QLabel* starsStatic;
	QLabel* leftStatic;
	QLabel* miscStatic;

	QLabel* productnameDisplay;
	QLabel* productqtyDisplay;
	QLabel* priceDisplay;
	QLabel* ratingDisplay;
	QLabel* miscDisplay;
	QLabel* miscDisplay2;

	//display reviews
	QListWidget* reviewDisplay;

// right column
	QVBoxLayout* rightLayout;
	QComboBox* userSelect;
	QLabel* creditDisplay;
	QPushButton* addtocart;
	QPushButton* viewcart;
	QLabel* userStatic;
	QLabel* creditStatic;
	QFormLayout* userselectLine;
	QFormLayout* usercreditLine;
		//placeholder
	QListWidget* reviewsHolder;
	QPushButton* saveButton;
	QPushButton* quitButton;



// data
	std::vector<User*> userlist;
	MyDataStore* ds;

};

#endif