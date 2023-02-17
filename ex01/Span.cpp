#include "Span.hpp"
 
Span::Span(void) : size(0), index(0)
{
        // std::cout << "Span Constractor called" << std::endl;
}
Span::Span(unsigned N) : myvector(std::vector<int>(N, 0)), size(N), index(0)
{
        // std::cout << "Span initilizator called" << std::endl;
}
Span::~Span(void)
{
        // std::cout << "Span deconstractor called" << std::endl;
}
Span::Span(Span const& ass)
{
        // std::cout << "Span Copy Constractor called" << std::endl;
        *this = ass;
}
Span& Span::operator=(Span const& ass)
{
        this->myvector = ass.myvector;
        this->size = ass.size;
        this->index = ass.index;
        this->min = this->myvector.begin() + (ass.min - ass.myvector.begin());
        this->max = this->myvector.begin() + (ass.max - ass.myvector.begin());
        return(*this);
}

void Span::addNumber(int n)
{
        if(index == size)
                throw  std::range_error("can't add more element ");
        std::vector<int>::iterator it = this->myvector.begin();
        *(it + index) = n;
        if (!index)
                {this->min = it; this->max = it;}
        else {
                if (*this->min > n){this->min = it + this->index;}
                else if (*this->max < n){this->max = it + this->index;}
        }
        index++;
}

unsigned abs_(int a)
{
        unsigned b = a;
        if (a < 0)
                b = -a;
        return(b);
}

unsigned positive_value(int a, int b)
{
        if ((a < 0 && b > 0) || (a > 0 && b < 0))
                return(abs_(a) + abs_(b));
        return(abs_(a) > abs_(b) ? abs_(a) - abs_(b) : abs_(b) - abs_(a));
}

unsigned Span::shortestSpan(void) 
{
        std::vector<int> vtmp = this->myvector; 
        if (this->index <= 1)
                throw std::range_error("there's not enough elements disponible in the vector to get the shortest span");
        int tmp;
        for(unsigned i = 0; i < this->index - 1 ; i++)
        {
                for(std::vector<int>::iterator it = vtmp.begin() ; it < vtmp.begin() + this->index - i - 1 ; it++)
                {
                        if (*it > *(it + 1))
                        {
                                tmp = *it;
                                *it = *(it + 1);
                                *(it + 1) = tmp;
                        }
                }
        }   
        std::vector<int>::iterator it1 = vtmp.begin() , it2 = vtmp.begin() + 1;
        for(std::vector<int>::iterator it = vtmp.begin() + 1 ; it < vtmp.begin() + this->index ; it++)
        {
                if (positive_value(*it1, *it2) > positive_value(*(it - 1), *it))
                {
                        it1 = it - 1;
                        it2 = it;
                }
        }
        return (positive_value(*it1, *it2));
}

unsigned Span::longestSpan(void)
{
        if (this->index <= 1)
                throw std::range_error("there's not enough elements disponible in the vector to get the longest span");
        return (positive_value(*this->max, *this->min));
}