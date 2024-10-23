#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T> int &easyfind(T &container, int target) {
  typename T::iterator result =
      std::find(container.begin(), container.end(), target);

  if (result != container.end())
    return *result;
  throw std::runtime_error("target not found in the container");
};

template <typename T> const int &easyfind(const T &container, int target) {
  typename T::const_iterator result =
      std::find(container.begin(), container.end(), target);

  if (result != container.end())
    return *result;
  throw std::runtime_error("target not found in the container");
};

#endif
