#include "../headers/Block.h"

template class
Block<int>;

template
std::ostream& operator<< <>(std::ostream& o, const Block<int>& x);

template
void swap <>(Block<int>&, Block<int>&);



