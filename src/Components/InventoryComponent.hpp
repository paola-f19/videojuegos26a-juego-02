#ifndef INVENTORYCOMPONENT_HPP
#define INVENTORYCOMPONENT_HPP

#include "ItemComponent.hpp"

#include <string>

struct InventorySlot {
  std::string itemId = "none";
};

struct InventoryComponent {
  InventorySlot slot1;
  InventorySlot slot2;
};

#endif  // INVENTORYCOMPONENT_HPP