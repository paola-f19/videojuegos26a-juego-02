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
  , bool consumable, int width, int height, int value, int srcRectX
  , int srcRectY) {
  SDL_Rect scrRect = {srcRectX, srcRectY, width, height};
  items.emplace(
    id,
    ItemDefinition{id, textureId, consumable, width, height, value, scrRect}
  );
}

ItemDefinition& ItemManager::GetItem(const std::string& id) {
  return items[id];
}