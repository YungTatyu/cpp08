#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
};

MutantStack::iterator MutantStack::begin() { return this->c.begin(); }

MutantStack::iterator MutantStack::end() { return this->c.end(); }

MutantStack::reverse_iterator MutantStack::rbegin() { return this->c.rbegin(); }

MutantStack::reverse_iterator MutantStack::rend() { return this->c.rend(); }

#endif
