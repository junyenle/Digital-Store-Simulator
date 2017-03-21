
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "book.h"
#include "util.h"
#include <sstream>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string ISBN, string Author) : 
    Product(category, name, price, qty), book_ISBN(ISBN), book_Author(Author)
{

}

Book::~Book()
{

}

set<string> Book::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    keywords.insert(convToLower(book_ISBN));

    set<string> authorwords = parseStringToWords(book_Author);
    
    set<string> allthekeywords = setUnion(authorwords, keywords);

    return allthekeywords;
}

string Book::displayString() const
{
    stringstream doubler;
    doubler << price_;
    string price = doubler.str();

    stringstream inter;
    inter << qty_;
    string qty = inter.str();

    string str;
    str += name_;
    str += "\n";
    str += "Author: ";
    str += book_Author;
    str += " ISBN: ";
    str += book_ISBN;
    str += "\n";
    str += price;
    str += " ";
    str += qty;
    str += " left.";
    return str;
}

void Book::dump(ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << book_ISBN << "\n" << book_Author << endl;
}