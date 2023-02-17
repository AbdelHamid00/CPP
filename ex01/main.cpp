#include "Span.hpp"

void    addRange(int *tab, unsigned size, Span &sp)
{
    for(unsigned i = 0; i < size ; i++)
        sp.addNumber(tab[i]);
}

int main()
{
Span sp = Span(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
// int tab[5] = {1,2,3,4,5};

// addRange(tab, 5, sp);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}