#ifndef ITEMCOMPONENT_HPP
#define ITEMCOMPONENT_HPP

#include <string>

struct ItemComponent {
  std::string itemId;

  ItemComponent(std::string id = "") {
    this->itemId = id;
  }
};

#endif  // ITEMCOMPONENT_HPP