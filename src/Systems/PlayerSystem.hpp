#ifndef PLAYERSYSTEM_HPP
#define PLAYERSYSTEM_HPP

#include "../Components/PlayerComponent.hpp"
#include "../Components/TagComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"

/**
 * @brief Stores and provides access to the player entity.
 */
class PlayerSystem : public System {
  private:
    TransformComponent* playerTransform;
    Entity player{-1};

  public:
    /**
     * @brief Constructor.
     */
    PlayerSystem() {
      RequireComponent<PlayerComponent>();
      RequireComponent<TagComponent>();
      RequireComponent<TransformComponent>();
    }

    /**
     * @brief Searches for the player entity.
     */
    void Update() {
      for (auto entity : GetSystemEntities()) {
        this->player = entity;
      }
    }

    /**
     * @brief Returns the player's transform component.
     *
     * @return Reference to the player's transform.
     */
    TransformComponent& GetPlayerTransform() const {
      return *playerTransform;
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
};

#endif 