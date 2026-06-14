#ifndef INVENTORYSYSTEP_HPP
#define INVENTORYSYSTEM_HPP

#include "../Components/InventoryComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/PlayerComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../EventManager/EventManager.hpp"
#include "../Events/ClickEvent.hpp"
#include "../Events/KeyEvent.hpp"

class InventorySystem : public System {
  public:
    InventorySystem() {
      RequireComponent<InventoryComponent>();
    }

    /**
     * @brief Subscribes the system to click events.
     * @param eventManager Event manager instance.
     */
    void SubscribeToClickEvent(std::unique_ptr<EventManager>& eventManager) {
      eventManager->SubscribeToEvent<ClickEvent, InventorySystem>(this
      , &InventorySystem::OnClickEvent);
    }

    /**
     * @brief Subscribes the system to key events.
     * @param eventManager Event manager instance.
     */
    void SubscribeToKeyEvent(std::unique_ptr<EventManager>& eventManager) {
      eventManager->SubscribeToEvent<KeyEvent, InventorySystem>(this
      , &InventorySystem::OnKeyEvent);
    }

    /**
     * @brief Handles click events and triggers entity click callbacks.
     * @param e Click event data.
     */
    void OnClickEvent(ClickEvent& e) {
      UseSlot(e.buttonCode);
    }

    /**
     * @brief Handles key events.
     * @param e Key event data.
     */
    void OnKeyEvent(KeyEvent& e) {
      if (e.key == 'q') {
        DropSlot(1);
      } else if (e.key == 'e') {
        DropSlot(2);
      }
    }

    void UseSlot(int slotIndex) {
      std::cout << "USE SLOT " << slotIndex << std::endl;
    }

    void DropSlot(int slotIndex) {
      std::cout << "DROP SLOT " << slotIndex << std::endl;
    }

};

#endif  // INVENTORYSYSTEM_HPP