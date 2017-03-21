#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"

class Movie: public Product{
public:
    Movie(std::string category, std::string name, double price, int qty, std::string movie_genre, std::string movie_rating);
    
    ~Movie();
    
    // returns set of keywords
    std::set<std::string> keywords()const ;

    std::string displayString() const;

    void dump(std::ostream& os) const;

private:
    std::string movie_genre;
    std::string movie_rating;


};
#endif