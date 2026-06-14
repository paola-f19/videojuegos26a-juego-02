#include "ItemManager.hpp"

#include <iostream>

ItemManager::ItemManager() {
  std::cout << "[ITEMMANAGER] Se ejecuta constructor" << std::endl;
}

ItemManager::~ItemManager() {
  std::cout << "[ITEMMANAGER] Se ejecuta destructor" << std::endl;
}

void ItemManager::ClearItems() {
  items.clear();
}

void ItemManager::AddItem(const std::string& id, const std::string& textureId
  , bool consumable) {
    items.emplace(
      id,
      ItemDefinition{id, textureId, consumable}
    );
}

ItemDefinition ItemManager::GetItem(const std::string& id) {
  return items[id];
}