
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "movie.h"
#include "util.h"
#include <sstream>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) : 
    Product(category, name, price, qty), movie_genre(genre), movie_rating(rating)
{

}

Movie::~Movie()
{
    
}

set<string> Movie::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> genre = parseStringToWords(movie_genre);

    set<string> allthekeywords = setUnion(genre, keywords);
    return allthekeywords;
}

string Movie::displayString() const
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
    str += "Genre: ";
    str += movie_genre;
    str += " Rating: ";
    str += movie_rating;
    str += "\n";
    str += price;
    str += " ";
    str += qty;
    str += " left.";
    return str;
}

void Movie::dump(ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << movie_genre << "\n" << movie_rating << endl;
}