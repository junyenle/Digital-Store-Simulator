#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <QString>

#include "product.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "util.h"
#include "datastore.h"

class MyDataStore: public DataStore{
    Q_OBJECT

public:
    MyDataStore();
    
    ~MyDataStore();

    void addProduct(Product* p);

    void addUser(User* u);


    User* findUser(std::string username);

    Product* findProduct(std::string productname);

    // helpers
    bool userExists(std::string username);
    bool productExists(std::string productname);

    int hitmapSize();

    // debug function
    //void clearCarts();
    std::string printallReviews();

    std::string viewReviews(int hitnumber);

    std::vector<User*> getUsers();

public slots:
    void addReview(Review* r);

    // -0 = alpha, 1 = rating
    void sort();

    // dump into database
    void dump(std::ostream& ofile);

    void addtoCart(User* u, int hitindex);

    std::string viewCart(User* u);

    void buyCart(User* u);

    void setsearchType(int type); 

    void setsortType(int type);

    // 0 = AND, 1 = OR
    void search();

    void updatesearch(QString);




private:

    // product names to ids
    std::map<std::string, int> namestoids;

    // product ids to product*
    std::map<int, Product*> productmap;

    // user to their cart
    std::map<User*, std::vector<Product*> > usermap;

    // username to user (so we can find a User* given the user's name)
    std::map<std::string, User*> userfinder;

    // keys to product ids
    std::map<std::string, std::set<int> > keymap;

    //hitmap contains Product* of all hits for the most recent search
    std::vector<Product*> hitmap;

    // map of products to reviews
    std::map<Product*, std::vector<Review*> > reviewmap;

    // vector of orphaned reviews
    std::vector<Review*> orphanage;

    // id counter (used to create users, as well as to count users)
    unsigned int idcount_;

    //QT STUFF
    // 0 = AND, 1 = OR
    int searchType;

    // 0 = alpha, 1 = ratings
    int sortType;

    std::string rawterms_;
};

#endif