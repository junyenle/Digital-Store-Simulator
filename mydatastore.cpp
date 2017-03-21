#include <string>
#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
#include <vector>
#include <sstream>
#include <QString>
#include "product.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "util.h"
#include "mydatastore.h"
#include "msort.h"

using namespace std;

// taken from amazon.cpp
// since my hitmap apparently needs to be in alphabetical order..
struct prodalpha {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};

struct prodrating{
    bool operator()(Product* p1, Product* p2){
        return(p1->getRating() > p2->getRating());
    }
};

MyDataStore::MyDataStore()
{
    idcount_ = 0;
    searchType = 0;
    sortType = 0;
    rawterms_ = "";
}

MyDataStore::~MyDataStore()
{

    //clearCarts();
    
    for(map<int, Product*>::iterator it = productmap.begin(); it != productmap.end(); it++)
    {
        delete it->second;
    }
    

    for(map<string,User*>::iterator it = userfinder.begin(); it != userfinder.end(); it++)
    {
        delete it->second;
    }

}

// how are we going to do this?
void MyDataStore::updatesearch(QString input)
{
    rawterms_ = input.toStdString();

    // test cout
    cout << input.toStdString() << endl;
    cout << "search updated"<< endl;
    cout << "string is: " << rawterms_ << endl;
    cout << input.toStdString() << endl;
    search();
    return;
}

void MyDataStore::addProduct(Product* p)
{
    namestoids.insert(make_pair(p->getName(), idcount_));
    productmap.insert(make_pair(idcount_, p));
    
    string productname = p->getName();
    set<string> productkeys = p->keywords();

    for(set<string>::iterator it = productkeys.begin(); it != productkeys.end(); it++)
    {
        if(keymap.find(*it)==keymap.end())
        {
            set<int> productids;
            productids.insert(idcount_);
            keymap.insert(make_pair(*it, productids));
        }
        else
        {
            (keymap.find(*it))->second.insert(idcount_);
        }
    }

    idcount_++;
    return;
}

void MyDataStore::setsearchType(int type)
{
    searchType = type;
    cout << "search type changed to " << searchType << endl;
    return;
}

void MyDataStore::addUser(User* u)
{
    vector<Product*> cart;
    usermap.insert(make_pair(u, cart));
    userfinder.insert(make_pair(u->getName(), u));
    std::map<std::string, User*> userfinder;

    return;
}

bool MyDataStore::productExists(string productname)
{
    if(namestoids.find(productname) == namestoids.end())
    {
        return false;
    }
    return true;
}

// debug function
string MyDataStore::printallReviews()
{
    string str;
    for(map<Product*, vector<Review*> >::iterator it = reviewmap.begin(); it != reviewmap.end(); it++)
    {
        vector<Review*> vec = it->second;
        for(vector<Review*>::iterator it2 = vec.begin(); it2 != vec.end(); it2++ )
        {
            str += (*it2)->reviewText;
            str += "\n";
        }
    }

    for(vector<Review*>::iterator it3 = orphanage.begin(); it3 != orphanage.end(); it3++)
    {
        str += (*it3)->reviewText;
        str += "\n";
    }

    return str;

}

Product* MyDataStore::findProduct(string productname)
{
    int key = namestoids.find(productname)->second;
    return(productmap.find(key)->second);
}

void MyDataStore::addReview(Review* r)
{
    // detect orphan
    if(!productExists(r->prodName))
    {
        // push back to orphanage vector
        orphanage.push_back(r);
    }

    else
    {
        Product* p = findProduct(r->prodName);
        // first review for a product
        if(reviewmap.find(p) == reviewmap.end())
        {
            vector<Review*> tempvec;
            tempvec.push_back(r);
            reviewmap.insert(make_pair(p, tempvec));
        }
        // not first review
        else
        {
            (reviewmap.find(p)->second).push_back(r);
        }

        p->updateRating((double)r->rating);

    }

    return;

}


string MyDataStore::viewReviews(int hitnumber)
{
    string str;
    Product* p = hitmap[hitnumber-1];
    vector<Review*> reviews = reviewmap.find(p)->second;
    str += p->getName();
    str += "\n";
    str += "Average rating: ";
    stringstream stream;
    stream << p->getRating();
    str += stream.str();
    str += "\n";
    str += "------------------\n";
    for(vector<Review*>::iterator it = reviews.begin(); it != reviews.end(); it++)
    {
        stringstream ss;
        ss <<(*it)->rating;
        string temp = ss.str();
        str += "I rate you a ";
        str += temp;
        str += "\n";
        str += "wrote ";
        str += (*it)->username;
        str += "\n";
        str += "on ";
        str += (*it)->date;
        str += ":\n";
        str += (*it)->reviewText;
        str += "\n\n";
    }

    return str;

}


vector<User*> MyDataStore::getUsers()
{
    vector<User*> vec;
    for(map<User*, vector<Product*> >::iterator it = usermap.begin(); it != usermap.end(); it++)
    {
        vec.push_back(it->first);
    }    

    return vec;
}


// helper accessor
bool MyDataStore::userExists(string username)
{
    if(userfinder.find(username)==userfinder.end())
    {
        return false;
    }
    return true;
}

// helper accessor
int MyDataStore::hitmapSize()
{
    return hitmap.size();
}

// cart clearer
// debug function
/*
void MyDataStore::clearCarts()
{
    for(map<User*, vector<Product*> >::iterator it = usermap.begin(); it != usermap.end(); it++)
    {
        it->second.clear();
    }
    return;
}
*/


User* MyDataStore::findUser(string username)
{

    return userfinder.find(username)->second;
}

// 0 = AND, 1 = OR


void MyDataStore::search()
{

    cout << "search called " << endl;


    vector<string> terms;
    stringstream ss;
    ss.str(rawterms_);
    string term;
    while(ss >> term)
    {
        term = convToLower(term);
        terms.push_back(term);
    }
    // guard against empty search
    if(terms.size() == 0)
    {
        hitmap.clear();
        return;
    }


    cout << "TERM DETECTED! we searched for " << endl;
    for(vector<string>::iterator it = terms.begin(); it != terms.end(); it++)
    {
        cout << *it << endl;
    }
    // clear hitmap so each search returns individual results
    hitmap.clear();



    // AND SEARCH
    if(searchType==0)
    {
        //empty vector
        //vector<Product*> dummy;

        // checking first term
        vector<string>::iterator it = terms.begin();
        
        // if you didn't find it anywhere
        if(keymap.find(*it) == keymap.end())
        {
            hitmap.clear();
        }

        // running intersection set
        set<int> andset = (keymap.find(*it))->second;
        it++;

        // subsequent terms
        while(it != terms.end())
        {
            // each term's product id set
            // IF FOUND
            if(keymap.find(*it)!=keymap.end())
            {
                // this particular term's set
                set<int> foundset = (keymap.find(*it))->second;
                // update the intersection
                andset = setIntersection(andset, foundset);
            }       
            // IF NOT FOUND
            else
            {
                hitmap.clear();
            }

            it++;
        }

        // we need a vector!
        vector<Product*> searchresult;

        // push the andset into the searchresult vector
        for(set<int>::iterator setit = andset.begin(); setit != andset.end(); setit++)
        {
            searchresult.push_back(productmap.find(*setit)->second);
        }  

        
        //create hitmap
        for(vector<Product*>::iterator it = searchresult.begin(); it != searchresult.end(); it++)
        {
            hitmap.push_back(*it);
        }

        //sort
        sort();

    }

    // OR SEARCH
    else
    {
        vector<string>::iterator it = terms.begin();
        
        // running union set
        set<int> orset;

        // searching first keyword
        if(keymap.find(*it) != keymap.end())
        {
            set<int> tempset = (keymap.find(*it))->second;
            orset = setUnion(orset, tempset);
        }
        it++;

        // subsequent terms
        while(it != terms.end())
        {
            // each term's product id set
            if(keymap.find(*it)!=keymap.end())
            {
                // this particular term's set
                set<int> foundset = (keymap.find(*it))->second;

                // update orset
                orset = setUnion(orset, foundset);
            }
            it++;
        }

        // we need a vector, not a set
        vector<Product*> searchresult;

        // we need a vector, not a set
        for(set<int>::iterator setit = orset.begin(); setit != orset.end(); setit++)
        {
            searchresult.push_back(productmap.find(*setit)->second);
        }   

        
        //create hitmap
        for(vector<Product*>::iterator it = searchresult.begin(); it != searchresult.end(); it++)
        {
            hitmap.push_back(*it);
        }

        // alphabetical sort
        sort();
      
    }

}

void MyDataStore::setsortType(int type)
{
    sortType = type;

    cout << "sort type changed to " << sortType << endl;
    return;
}

void MyDataStore::sort()
{
    int type = sortType;
    if(type == 0)
    {
        prodalpha compalpha;
        mergeSort(hitmap, compalpha);
    }

    else
    {
        prodrating comprating;
        mergeSort(hitmap, comprating);
    }

    return;
}


void MyDataStore::addtoCart(User* u, int hitindex) // hitindex is the number seen by user
{
    // add Product* from hitmap to User's cart in usermap
    (usermap.find(u)->second).push_back(hitmap[hitindex-1]);

    return;
}

void MyDataStore::dump(ostream& ofile)
{
    ofile << "<products>\n";
    for(unsigned int i = 0; i < idcount_; i++)
    {
        productmap.find(i)->second->dump(ofile);
    }
    ofile << "</products>\n";


    ofile << "<users>\n";
    for(map<string, User*>::iterator it = userfinder.begin(); it != userfinder.end(); it++)
    {
        it->second->dump(ofile);
    }
    ofile << "</users>\n"; 

    ofile << "<reviews>\n";
    for(map<Product*, vector<Review*> >::iterator it = reviewmap.begin(); it != reviewmap.end(); it++)
    {
        for(vector<Review*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            (*it2)->dump(ofile);
        }
    }
    for(vector<Review*>::iterator it3 = orphanage.begin(); it3 != orphanage.end(); it3++)
    {
        (*it3)->dump(ofile);
    }
    ofile << "</reviews>\n"; 

    return;
}


string MyDataStore::viewCart(User* u)
{
    int count = 1;
    string str;
    for(vector<Product*>::iterator it = (usermap.find(u))->second.begin(); it < (usermap.find(u))->second.end(); it++)
    {
        stringstream ss;
        ss << count;
        string countstring = ss.str();

        str += "Item ";
        str += countstring;
        str += "\n";
        str += ((*it)->displayString());
        str += "\n\n";
        count ++;
    }
    return str;
}




void MyDataStore::buyCart(User* u)
{
    // it's easier to work with "cart" than "usermap.find......"
    vector<Product*> cart = usermap.find(u)->second;
    // get initial cart size
    int size = cart.size();
    for(int i = 0; i < size; i++)
    {
        //enough qty and money
        if((cart[i]->getQty()) > 0 && (u->getBalance()) >= (cart[i]-> getPrice()))
        {
            // subtract from cart
            cart[i]->subtractQty(1);
            // subtract user's money
            u->deductAmount(cart[i]->getPrice());
        }
        //not enough qty or money
        else
        {   
            // leave in cart for next try
            cart.push_back(cart[i]);
        }

    }

    // delete the elements covered
    for(int i = 0; i < size; i++)
    {
        cart.erase(cart.begin());
    }

    // update user's cart in usermap to the updated cart
    usermap.find(u)->second = cart;

}