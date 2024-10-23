#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
};

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() {
  return this->c.rend();
}

#endif
