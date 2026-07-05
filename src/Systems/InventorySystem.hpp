#ifndef INVENTORYSYSTEP_HPP
#define INVENTORYSYSTEM_HPP

#include <glm/glm.hpp>

#include <iostream>

#include "../Components/InventoryComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/PlayerComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../EventManager/EventManager.hpp"
#include "../Events/ClickEvent.hpp"
#include "../Events/KeyEvent.hpp"
#include "../Game/Game.hpp"

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

      if (GetSystemEntities().empty()) {
          return;
      }

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

      auto player = GetSystemEntities()[0];
      auto& playerComponent = player.GetComponent<PlayerComponent>();
      auto& inventory = player.GetComponent<InventoryComponent>();

      InventorySlot& slot = slotIndex == 1 ? inventory.slot1 : inventory.slot2;

      auto& item = Game::GetInstance().itemManager->GetItem(slot.itemId);

      // TOOLS

      if (item.id == "sickle") {
        if(playerComponent.currentFarmPlot.GetId() == -1)
          return;

        Game::GetInstance().registry->GetSystem<CropSystem>().HarvestCrop(
          playerComponent.currentFarmPlot);

        return;
      }

      if (item.id == "watering_can") {
        if (playerComponent.currentFarmPlot.GetId() == -1)
          return;

        Game::GetInstance().registry->GetSystem<CropSystem>().WaterCrop(
          playerComponent.currentFarmPlot);

        return;
      }

      // PLANTING

      if (item.id == "seed_pouch") {
        if (playerComponent.currentFarmPlot.GetId() == -1) {
          std::cout << "NO FARM PLOT DETECTED" << std::endl;
          return;
        }

        // check that plot is free
        auto& farmPlot = playerComponent.currentFarmPlot
          .GetComponent<FarmPlotComponent>();
        if (farmPlot.occupied)
          return;

        Game::GetInstance().registry->GetSystem<CropSystem>().PlantCrop(
          playerComponent.currentFarmPlot,
          farmPlot.cropId + "_seeds"
        );
        return;
      }

      // DELIVER ITEMS
      if(playerComponent.currentDeliveryZone.GetId() != -1) {
        DeliverItem(slot);
        return;
      }

      // remove item
      // if (item.consumable) {
      //   slot.itemId = "none";
      // }
    }

    void DropSlot(int slotIndex) {
      std::cout << "DROP SLOT " << slotIndex << std::endl;

      auto player = GetSystemEntities()[0];
      auto& inventory = player.GetComponent<InventoryComponent>();

      InventorySlot& slot = slotIndex == 1 ? inventory.slot1 : inventory.slot2;
      if (slot.itemId == "none") {
        return;
      }

      auto& transform = player.GetComponent<TransformComponent>();
      glm::vec2 position = transform.position;

      const auto& item = Game::GetInstance().itemManager->GetItem(slot.itemId);

      Entity droppedItem = Game::GetInstance().registry->CreateEntity();

      droppedItem.AddComponent<TransformComponent>(
        glm::vec2(
          position.x + 8,
          position.y + 30
        ),
        glm::vec2(1.0f, 1.0f),
        0.0f
      );

      droppedItem.AddComponent<SpriteComponent>(
        item.textureId,
        item.width,
        item.height,
        item.srcRect.x,
        item.srcRect.y,
        glm::vec2(0, 0)
      );

      droppedItem.AddComponent<ItemComponent>(slot.itemId);

      droppedItem.AddComponent<BoxColliderComponent>(
        item.width,
        item.height,
        glm::vec2(0, 0)
      );

      slot.itemId = "none";
    }
  private:
    bool isSeed(const std::string& itemId) {
      return itemId.size() >= 6 && itemId.substr(itemId.size() - 6) == "_seeds";
    }

    void DeliverItem(InventorySlot& slot) {
      auto& order = Game::GetInstance().orderManager->order;

      for (auto& requirement : order) {
        if(requirement.itemId == slot.itemId) {
          if(requirement.delivered < requirement.required) {
            requirement.delivered++;

            slot.itemId = "none";

            std::cout << "Delivered " << requirement.itemId << std::endl;
          }
          break;
        }
      }

      if(Game::GetInstance().orderManager->IsComplete()) {
        // win
        std::cout << "LEVEL COMPLETE" << std::endl;
        Game::GetInstance().sceneManager->SetNextScene("win");
        Game::GetInstance().sceneManager->StopScene();
      }
    }
};

#endif  // INVENTORYSYSTEM_HPP