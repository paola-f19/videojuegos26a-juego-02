#ifndef ANIMALEVENTSYSTEM_HPP
#define ANIMALEVENTSYSTEM_HPP

#include "../Components/AnimalLeaderComponent.hpp"
#include "../Components/AnimalStatusComponent.hpp"
#include "../Components/AnimationComponent.hpp"
#include "../Components/LifetimeComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class AnimalEventSystem : public System {
private:
  float eventTimer = 0.0f;
  float eventInterval = 15.0f;

  void SpawnLightningEffect(Entity animalEntity) {
    auto& transform = animalEntity.GetComponent<TransformComponent>();

    Entity lightning = Game::GetInstance().registry->CreateEntity();

    lightning.AddComponent<TransformComponent>(
      transform.position + glm::vec2(0, -16),
      glm::vec2(1.0f, 1.0f),
      0.0f
    );

    lightning.AddComponent<SpriteComponent>(
      "lightning",
      16,
      16,
      0,
      0
    );

    lightning.AddComponent<AnimationComponent>(
      "lightning_strike"
    );

    lightning.AddComponent<LifetimeComponent>(1.0f);

    Game::GetInstance().audioManager->PlaySound("lightning_strike");
  }

public:
  AnimalEventSystem() {
    RequireComponent<AnimalLeaderComponent>();
    RequireComponent<AnimalStatusComponent>();
  }

  void Update(float deltaTime) {
    eventTimer += deltaTime;

    if (eventTimer < eventInterval) {
      return;
    }

    eventTimer = 0.0f;

    auto entities = GetSystemEntities();

    if (entities.empty()) {
      return;
    }

    int roll = rand() % 100;
    std::cout << "Rolling for lightning..." << std::endl;

    if (roll < 20) { // 20% chance every interval
      int victimIndex = rand() % entities.size();

      auto entity = entities[victimIndex];
      auto& status = entity.GetComponent<AnimalStatusComponent>();

      status.struckByLightning = true;
      status.statusTimer = 10.0f;

      SpawnLightningEffect(entity);

      std::cout << "Animal struck by lightning!" << std::endl;
    }
  }
};

#endif  // ANIMALEVENTSYSTEM_HPP