#include "main_window.h"
using namespace std;

MainWindow::MainWindow(MyDataStore* exds)
{
	ds = exds;
	// main layout
	fullLayout = new QHBoxLayout();

	// left
	leftLayout = new QVBoxLayout();
	searchboxLayout = new QFormLayout();
	searchInput = new QLineEdit();
	searchButton = new QPushButton("Search / Refresh");
	
		// search
	andorSelect = new QComboBox();
	andorSelect->addItem("Products containing ALL keywords");
	andorSelect->addItem("Products containing ANY keywords");
	abcratingSelect = new QComboBox();
	abcratingSelect->addItem("Sort by alphabetical order");
	abcratingSelect->addItem("Sort by highest rating");
		// search connect
	//QObject::connect(andorSelect, SIGNAL(activated(int)), ds, SLOT(setsearchType(int)));
	//QObject::connect(abcratingSelect, SIGNAL(activated(int)), ds, SLOT(setsortType(int)));


	QSignalMapper* mapper = new QSignalMapper();

		// map searchButton to QString
    mapper->setMapping(searchButton, searchInput->text());
	QObject::connect(searchButton, SIGNAL(clicked()), mapper, SLOT(map()));

    //QObject::connect(mapper, SIGNAL(mapped(QString)), ds, SLOT(updatesearch(QString)));

    // display search results
    searchResults = new QListWidget;
    searchboxLayout->addRow(searchButton, searchInput);
	leftLayout->addLayout(searchboxLayout);
	leftLayout->addWidget(andorSelect);
	leftLayout->addWidget(abcratingSelect);
	leftLayout->addWidget(searchResults);

	// middle
	centerLayout = new QVBoxLayout();
	productnameLine = new QFormLayout();
	productqtyLine = new QFormLayout();
	productpriceLine = new QFormLayout();
	productratingLine = new QFormLayout();
	productmiscLine = new QFormLayout();
	productmiscLine2 = new QFormLayout();
	productStatic = new QLabel("Product:");
	dollarStatic = new QLabel("$");
	starsStatic = new QLabel("stars average rating");
	leftStatic = new QLabel("left");
	miscStatic = new QLabel("Misc:");
	productnameDisplay = new QLabel("Laptop");
	productqtyDisplay = new QLabel("17");
	priceDisplay = new QLabel("29.99");
	ratingDisplay = new QLabel("4.8");
	miscDisplay = new QLabel("17 inch screen");
	miscDisplay2 = new QLabel("comes with mouse");

	productnameLine->addRow(productStatic, productnameDisplay);
	productqtyLine->addRow(productqtyDisplay, leftStatic);
	productpriceLine->addRow(dollarStatic, priceDisplay);
	productratingLine->addRow(ratingDisplay, starsStatic);
	productmiscLine->addRow(miscStatic, miscDisplay);
	productmiscLine2->addRow(miscStatic, miscDisplay2);

	// view reviews
	reviewDisplay = new QListWidget();

	centerLayout->addLayout(productnameLine);
	centerLayout->addLayout(productpriceLine);
	centerLayout->addLayout(productqtyLine);
	centerLayout->addLayout(productmiscLine);
	centerLayout->addLayout(productmiscLine2);
	centerLayout->addLayout(productratingLine);
	centerLayout->addWidget(reviewDisplay);


	// right column
	rightLayout = new QVBoxLayout();
	userSelect = new QComboBox();
	// userlist = ds->getUsers();
	/*for(vector<User*>::iterator it = userlist.begin(); it != userlist.end(); it++)
	{
		string name = (*it)->getName();
		QString Qname = QString::fromStdString(name);
		userSelect->addItem(Qname);
	}*/

	creditDisplay = new QLabel("15");
	addtocart = new QPushButton("Add to cart");
	viewcart = new QPushButton("View cart");

	userStatic = new QLabel("User:");
	creditStatic = new QLabel("Credits:");

	userselectLine = new QFormLayout();
	userselectLine->addRow(userStatic, userSelect);
	usercreditLine = new QFormLayout();
	usercreditLine->addRow(creditStatic, creditDisplay);

	rightLayout->addLayout(userselectLine);
	rightLayout->addLayout(usercreditLine);
	rightLayout->addWidget(addtocart);
	rightLayout->addWidget(viewcart);

	reviewsHolder = new QListWidget;
	rightLayout->addWidget(reviewsHolder);

	saveButton = new QPushButton("SAVE");
	rightLayout->addWidget(saveButton);

	quitButton = new QPushButton("QUIT (DISCARD CHANGES)");
	rightLayout->addWidget(quitButton);
	//QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));


// stick it together
	fullLayout->addLayout(leftLayout);

	fullLayout->addLayout(centerLayout);
	fullLayout->addLayout(rightLayout);

	this->setLayout(fullLayout);

}

MainWindow::~MainWindow()
{
	
}