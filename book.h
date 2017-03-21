#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"

class Book: public Product{
public:
    Book(std::string category, std::string name, double price, int qty, std::string ISBN, std::string Author);
    
    ~Book();
    
    // returns set of keywords
    std::set<std::string> keywords() const;

    std::string displayString() const;

    void dump(std::ostream& os) const;

private:
    std::string book_ISBN;
    std::string book_Author;


};
#endif