#ifndef ITEMMANAGER_HPP
#define ITEMMANAGER_HPP

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct ItemDefinition {
  std::string id;
  std::string textureId;
  bool consumable;

  int width;
  int height;

  SDL_Rect srcRect;
};

class ItemManager {
  private:
    std::map<std::string, ItemDefinition> items;

  public:
    ItemManager();
    ~ItemManager();

    void ClearItems();
    void AddItem(const std::string& id, const std::string& textureId
      , bool consumable, int width = 0, int height = 0, int srcRectX = 0
      , int srcRectY = 0);
    ItemDefinition GetItem(const std::string& id);
};

#endif  // ITEMMANAGER_HPP
