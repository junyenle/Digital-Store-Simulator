#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates  
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> inter;
    typename std::set<T>::iterator it = s1.begin();
    typename std::set<T>::iterator it2;

    while(it != s1.end())
    {
        for(it2 = s2.begin(); it2 != s2.end(); it2++)
        {
            if(*it == *it2)
            {
                inter.insert(*it);
            }
        }

        it++;
    }

    return inter;

}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> uni;
    typename std::set<T>::iterator it = s1.begin();
    typename std::set<T>::iterator it2 = s2.begin();
    while(it != s1.end())
    {
        uni.insert(*it);
        it++;
    }
    while(it2 != s2.end())
    {
        uni.insert(*it2);
        it2++;
    }

    return uni;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) ;

// trim from end
std::string &rtrim(std::string &s) ;

// trim from both ends
std::string &trim(std::string &s) ;
#endif
