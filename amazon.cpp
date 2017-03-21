#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <QApplication>
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

#include "product.h"
#include "mydatastore.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "msort.h"
#include "main_window.h"

using namespace std;


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    /****************
     * You may modify this allocation and type if you need
     ****************/

    QApplication app(argc, argv);
    MyDataStore* ds = new MyDataStore;



    // Instantiate the individual section and product parsers we want
    ProductSectionParser* productSectionParser = new ProductSectionParser;
    productSectionParser->addProductParser(new ProductBookParser);
    productSectionParser->addProductParser(new ProductClothingParser);
    productSectionParser->addProductParser(new ProductMovieParser);
    UserSectionParser* userSectionParser = new UserSectionParser;
    ReviewSectionParser* reviewSectionParser = new ReviewSectionParser;

    // Instantiate the parser
    DBParser parser;
    parser.addSectionParser("products", productSectionParser);
    parser.addSectionParser("users", userSectionParser);
    parser.addSectionParser("reviews", reviewSectionParser);

    // Now parse the database to populate the DataStore
    if( parser.parse(argv[1], *ds) ) {
        cerr << "Error parsing!" << endl;
        return 1;
    }

    // not to grader:
    // QApplication  construction moved up to before mydatastore construction
    // since mydatastore has been converted into a QObject

    /*******************************
     * Create your main widget here and show it
     */

    MainWindow mainWindow(ds);
    mainWindow.show();
    return app.exec();


}

