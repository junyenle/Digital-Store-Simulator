#include <vector>
#include <iostream>
#include <string>


// test comparator, strings alphabetical
struct stringalpha
{    
    bool operator()(const std::string& lhs, const std::string& rhs)
    {
        return lhs <= rhs;
    }
};

// test comparator, strings by length
struct stringlength
{
    bool operator()(const std::string& lhs, const std::string& rhs)
    {
        return lhs.size() <= rhs.size();
    }
};

// test comparator, ints by value
struct intcomp
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs <= rhs;
    }
};

// test comparator, ints by value, but multiples of 5 prioritized
struct intcomp2
{
    bool operator()(const int& lhs, const int& rhs)
    {
        if(lhs % 5 == 0)
        {
            return 1;
        }
        if(rhs % 5 == 0)
        {
            return 0;
        }
        return lhs <= rhs;
    }
};


template <class It, class Comparator>
void stitch(It builder, It left_move, It left_done, It right_move, It right_done, Comparator comp)
{
    

    // while both mini lists are not empty
    // stitch the builder by performing comparisons
    // and then incrementing iterators
    while(left_move != left_done && right_move != right_done)
    {
        if(comp(*left_move, *right_move))
        {
            *builder = *left_move;
            std::advance(left_move, 1);
            std::advance(builder, 1);
        }
        else
        {
            *builder = *right_move;
            std::advance(right_move, 1);
            std::advance(builder, 1);
        }
    }

    // we don't really care in what order the
    // next two while loops are executed
    // because only one of the conditions 
    // will be true anyways
    while(left_move != left_done)
    {
        *builder = *left_move;
        std::advance(left_move, 1);
        std::advance(builder, 1);
    }

    while(right_move != right_done)
    {
        *builder = *right_move;
        std::advance(right_move, 1);
        std::advance(builder, 1);
    }

    return;
}

template <class T, class Comparator>
void mergeSort(std::vector<T>& myArray, Comparator comp)
{

    // builder is an iterator to the beginning of the array which 
    // we will use a an anchor point to reconstruct the sorted vector
    typename std::vector<T>::iterator builder = myArray.begin();

    // vector of size one / zero
    if(myArray.size() <= 1)
    {
        return;
    }

    // find middle iterator
    typename std::vector<T>::iterator mid = myArray.begin();
    std::advance(mid, std::distance(myArray.begin(), myArray.end())/2);

    // split the vector into left and right
    std::vector<T> lhs(myArray.begin(), mid);
    std::vector<T> rhs(mid, myArray.end());

    // call mergeSort on both sides
    mergeSort(lhs, comp);
    mergeSort(rhs, comp);

    // stitch together
    stitch(builder, lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), comp);

    return;
}