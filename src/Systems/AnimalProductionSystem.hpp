#ifndef ANIMALPRODUCTIONSYSTEM_HPP
#define ANIMALPRODUCTIONSYSTEM_HPP

#include <iostream>

#include "../Components/AnimalLeaderComponent.hpp"
#include "../Components/BoxColliderComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class AnimalProductionSystem : public System {
private:
  float GetDecayRate(int count) {
    if (count == 1) return 2.0f;
    if (count == 2) return 1.5f;
    if (count >= 3) return 1.0f;
    return 0.0f;
  }

  void Produce(Entity entity) {
    auto& animal = entity.GetComponent<AnimalLeaderComponent>();
    auto& transform = entity.GetComponent<TransformComponent>();
    
    Entity product = Game::GetInstance().registry->CreateEntity();

    glm::vec2 spawnPos = transform.position + glm::vec2(0.0f, 40.0f);
    
    product.AddComponent<TransformComponent>(
      spawnPos,
      glm::vec2(1.0f, 1.0f),
      0.0f
    );
    
    const auto& item = Game::GetInstance().itemManager->GetItem(animal.productId);
    product.AddComponent<SpriteComponent>(
      item.id,
      item.width,
      item.height,
      item.srcRect.x,
      item.srcRect.y,
      glm::vec2(0, 0)
    );
    
    product.AddComponent<ItemComponent>(animal.productId);
    
    product.AddComponent<BoxColliderComponent>(
      item.width,
      item.height,
      glm::vec2(0, 0)
    );
    
    std::cout << "🐄 " << animal.productId << " generated!" << std::endl;
  }

public:
  AnimalProductionSystem() {
    RequireComponent<AnimalLeaderComponent>();
  }

  void Update(float deltaTime) {
    for (auto entity : GetSystemEntities()) {
      auto& animal = entity.GetComponent<AnimalLeaderComponent>();
      
      float decay = GetDecayRate(animal.count);
      
      animal.currentHappiness = std::max(0.0f, animal.currentHappiness - decay * deltaTime);
      animal.currentHunger = std::max(0.0f, animal.currentHunger - decay * deltaTime);
      animal.currentCleanliness = std::max(0.0f, animal.currentCleanliness - decay * deltaTime);
      
      if (animal.currentHappiness >= animal.threshold &&
          animal.currentHunger >= animal.threshold &&
          animal.currentCleanliness >= animal.threshold) {
        
        animal.productionTimer += deltaTime;
        if (animal.productionTimer >= animal.productionInterval) {
          animal.productionTimer = 0.0f;
          Produce(entity);
        }
      } else {
        animal.productionTimer = 0.0f;
      }
    }
  }
};

#endif