#ifndef INVENTORYSYSTEP_HPP
#define INVENTORYSYSTEM_HPP

#include <glm/glm.hpp>

#include <iostream>

#include "../Components/InventoryComponent.hpp"
#include "../Components/FollowComponent.hpp"
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
  private:
  void SpawnItem(const std::string& itemId, const glm::vec2& position) {
    auto& registry = *Game::GetInstance().registry;
    auto& itemManager = *Game::GetInstance().itemManager;
    
    const auto& item = itemManager.GetItem(itemId);
    
    Entity newItem = registry.CreateEntity();
    
    newItem.AddComponent<TransformComponent>(
      position,
      glm::vec2(1.0f, 1.0f),
      0.0f
    );
    
    newItem.AddComponent<SpriteComponent>(
      item.id,
      item.width,
      item.height,
      item.srcRect.x,
      item.srcRect.y,
      glm::vec2(0, 0)
    );
    
    newItem.AddComponent<ItemComponent>(item.id);
    
    newItem.AddComponent<BoxColliderComponent>(
      item.width,
      item.height,
      glm::vec2(0, 0)
    );
  }

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

      // DELIVER ITEMS
      if(playerComponent.currentDeliveryZone.GetId() != -1) {
        DeliverItem(slot);
        return;
      }

      // TOOLS

      if (item.id == "sickle") {
        if(playerComponent.currentFarmPlot.GetId() == -1)
          return;

        Game::GetInstance().audioManager->PlaySound("slash");

        Game::GetInstance().registry->GetSystem<CropSystem>().HarvestCrop(
          playerComponent.currentFarmPlot);

        return;
      }

      if (item.id == "watering_can") {
        if (playerComponent.currentFarmPlot.GetId() == -1)
          return;

        Game::GetInstance().audioManager->PlaySound("watering_can");

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

        Game::GetInstance().audioManager->PlaySound("seed_pouch");

        Game::GetInstance().registry->GetSystem<CropSystem>().PlantCrop(
          playerComponent.currentFarmPlot,
          farmPlot.cropId + "_seeds"
        );
        return;
      }

      // Cleaning kit
      if (item.id == "cleaning_kit") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        // + cleaness
        auto& animal = playerComponent.currentAnimalContact.GetComponent<AnimalLeaderComponent>();
        animal.currentCleanliness = std::min(animal.maxCleanliness, animal.currentCleanliness + 20);
        
        std::cout << "Animal limpiado!" << std::endl;
        return;
      }

      if (item.id == "guide_glove") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;

        auto& animal = playerComponent.currentAnimalContact.GetComponent<FollowComponent>();
        if(!animal.isFollowing) {
          animal.isFollowing = true;
        } else {
          animal.isFollowing = false;
        }
        std::cout << "sigue o deja de seguir lol" << std::endl;
        return;
      }

      // BERRY
      if (item.id == "berry") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            (animal.GetComponent<TagComponent>().tag == "animal_slime"
            || animal.GetComponent<TagComponent>().tag == "animal_bird"
            || animal.GetComponent<TagComponent>().tag == "animal_beast")) {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          //animalStats.currentHunger = std::min(animalStats.maxHunger, animalStats.currentHunger + 20);
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      // CARROT
      if (item.id == "carrot") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            (animal.GetComponent<TagComponent>().tag == "animal_bird"
            || animal.GetComponent<TagComponent>().tag == "animal_slime")) {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      // RADDISH
      if (item.id == "radish") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            (animal.GetComponent<TagComponent>().tag == "animal_sugarcane"
            || animal.GetComponent<TagComponent>().tag == "animal_bird"
            || animal.GetComponent<TagComponent>().tag == "animal_mollusc")) {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      // PUMPKIN
      if (item.id == "pumpkin") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            (animal.GetComponent<TagComponent>().tag == "animal_bird"
            || animal.GetComponent<TagComponent>().tag == "animal_beast"))  {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      // SUGAR CANE
      if (item.id == "sugarcane_product") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            animal.GetComponent<TagComponent>().tag == "animal_dragon") {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      // MOLLUSC
      if (item.id == "meat") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        //Need to add other animals tag
        if (animal.HasComponent<TagComponent>() && 
            animal.GetComponent<TagComponent>().tag == "animal_trex") {
          
          auto& animalStats = animal.GetComponent<AnimalLeaderComponent>();
          animalStats.currentHunger = animalStats.maxHunger;
          
          slot.itemId = "none";
          std::cout << "🍓 Slime alimentado!" << std::endl;
        } else {
          std::cout << "❌ Esto no es un slime!" << std::endl;
        }
        return;
      }

      if (item.id == "knife") {
        if (playerComponent.currentAnimalContact.GetId() == -1) return;
        
        Entity animal = playerComponent.currentAnimalContact;
        
        auto& transform = animal.GetComponent<TransformComponent>();

        SpawnItem("meat", transform.position);
        SpawnItem("meat", transform.position);
        SpawnItem("meat", transform.position);
        
        animal.Kill();
        
        slot.itemId = "none";
        std::cout << "Animal sacrificado!" << std::endl;
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
            Game::GetInstance().audioManager->PlaySound("win");
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