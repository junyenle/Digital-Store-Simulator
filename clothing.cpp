
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "clothing.h"
#include "util.h"
#include <sstream>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) : 
    Product(category, name, price, qty), clothes_size(size), clothes_brand(brand)
{

}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> keywords2 = parseStringToWords(clothes_brand);

    set<string> allthekeywords = setUnion(keywords, keywords2);

    return allthekeywords;
}

string Clothing::displayString() const
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
    str += "Size: ";
    str += clothes_size;
    str += " Brand: ";
    str += clothes_brand;
    str += "\n";
    str += price;
    str += " ";
    str += qty;
    str += " left.";
    return str;
}

void Clothing::dump(ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << clothes_size << "\n" << clothes_brand << endl;
}