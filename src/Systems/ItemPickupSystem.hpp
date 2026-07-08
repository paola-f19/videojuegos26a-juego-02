#ifndef ITEMPICKUPSYSTEM_HPP
#define ITEMPICKUPSYSTEM_HPP

#include "../Components/InventoryComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/PlayerComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../EventManager/EventManager.hpp"
#include "../Events/CollisionEvent.hpp"
#include "../Game/Game.hpp"

#include <iostream>

class ItemPickupSystem : public System {
  public:
    ItemPickupSystem() {
      RequireComponent<InventoryComponent>();
      RequireComponent<PlayerComponent>();
    }

    /**
     * @brief Subscribes the system to collision events.
     *
     * @param eventManager Event manager handling subscriptions.
     */
    void SubscribeToCollisionEvent(std::unique_ptr<EventManager>& eventManager) {
      eventManager->SubscribeToEvent<CollisionEvent, ItemPickupSystem>(this
      , &ItemPickupSystem::OnCollision);
    }

    /**
     * @brief Handles collision events.
     *
     * @param e Collision event data.
     */
    void OnCollision(CollisionEvent& e) {
      bool aIsPlayer = e.a.HasComponent<PlayerComponent>();

      bool bIsPlayer = e.b.HasComponent<PlayerComponent>();

      bool aIsItem = e.a.HasComponent<ItemComponent>();

      bool bIsItem = e.b.HasComponent<ItemComponent>();
      
      if (aIsPlayer && bIsItem) {
        TryPickup(e.a, e.b);
      }
      else if (bIsPlayer && aIsItem) {
        TryPickup(e.b, e.a);
      }
    }

    void TryPickup(Entity player, Entity itemEntity) {
      // std::cout << "TRYPICKUP" << std::endl;
      auto& inventory = player.GetComponent<InventoryComponent>();
      auto& item = itemEntity.GetComponent<ItemComponent>();

      if (inventory.slot1.itemId == "none") {
        inventory.slot1.itemId = item.itemId;

        Game::GetInstance().audioManager->PlaySound("pickup");

        itemEntity.Kill();

        return;
      }

      if (inventory.slot2.itemId == "none") {
        inventory.slot2.itemId = item.itemId;

        Game::GetInstance().audioManager->PlaySound("pickup");

        itemEntity.Kill();

        return;
      }

      return;
    }
};

#endif  // ITEMPICKUPSYSTEM_HPP