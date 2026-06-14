#ifndef ITEMMANAGER_HPP
#define ITEMMANAGER_HPP

#include <map>
#include <string>

struct ItemDefinition {
  std::string id;
  std::string textureId;
  bool consumable;
};

class ItemManager {
  private:
    std::map<std::string, ItemDefinition> items;

  public:
    ItemManager();
    ~ItemManager();

    void ClearItems();
    void AddItem(const std::string& id, const std::string& textureId
      , bool consumable);
    ItemDefinition GetItem(const std::string& id);
};

#endif  // ITEMMANAGER_HPP
