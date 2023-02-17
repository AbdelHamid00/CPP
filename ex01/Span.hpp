#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
class Span
{
    private:
        std::vector<int> myvector; // we gonna use a vector because it's dynamic and it's possible to add members i run time .
        unsigned size, index;
        std::vector<int>::iterator max, min;
    public:
        Span(void);
        Span(unsigned N);
        ~Span(void);
        Span(Span const&);
        Span& operator=(Span const&);
        void addNumber(int); //add a member if it's possible , if not throw an exeption .
        unsigned shortestSpan(void); //find out the shortest span (span is the distance betweem two numbers in myvector)
        unsigned longestSpan(void); //find out the longest span (span is the distance betweem two numbers in myvector)
};

void print_(std::vector<int> myvector);

#endif