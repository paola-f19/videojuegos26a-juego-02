#ifndef PLAYERSYSTEM_HPP
#define PLAYERSYSTEM_HPP

#include "../Components/PlayerComponent.hpp"
#include "../ECS/ECS.hpp"

/**
 * @brief Stores and provides access to the player entity.
 */
class PlayerSystem : public System {
  private:
    Entity player{-1};
    bool hasPlayer = false;

  public:
    /**
     * @brief Constructor.
     */
    PlayerSystem() {
      RequireComponent<PlayerComponent>();
    }

    /**
     * @brief Searches for the player entity.
     */
    void Update() {
      hasPlayer = false;
      this->player = Entity{-1};
      
      for (auto entity : GetSystemEntities()) {
        this->player = entity;
        hasPlayer = true;
        break;
      }
    }

    bool HasPlayer() const {
      return hasPlayer;
    }

    /**
     * @brief Returns the player entity.
     *
     * @return Player entity.
     */
    Entity GetPlayer() const {
      return player;
    }

    void ClearCurrentFarmPlot() {
      auto& playerComponent = player.GetComponent<PlayerComponent>();

      playerComponent.currentFarmPlot = Entity(-1);
    }

    void ClearDeliveryZone() {
      auto& playerComponent = player.GetComponent<PlayerComponent>();

      playerComponent.currentDeliveryZone = Entity(-1);
    }
};

#endif 