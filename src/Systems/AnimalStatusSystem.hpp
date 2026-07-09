#ifndef ANIMALSTATUSSYSTEM_HPP
#define ANIMALSTATUSSYSTEM_HPP

#include "../Components/AnimalLeaderComponent.hpp"
#include "../Components/AnimalStatusComponent.hpp"
#include "../ECS/ECS.hpp"

class AnimalStatusSystem : public System {
public:
  AnimalStatusSystem() {
    RequireComponent<AnimalLeaderComponent>();
    RequireComponent<AnimalStatusComponent>();
  }

  void Update(float deltaTime) {
    for (auto entity : GetSystemEntities()) {

      auto& animal = entity.GetComponent<AnimalLeaderComponent>();
      auto& status = entity.GetComponent<AnimalStatusComponent>();

      if (!status.struckByLightning) {
        continue;
      }

      status.statusTimer -= deltaTime;

      // effect on animal stats
      animal.currentHappiness = 0;
      animal.currentHunger = 0;
      animal.currentCleanliness = 0;

      if (status.statusTimer <= 0.0f) {
        status.struckByLightning = false;

        std::cout << "Animal recovered." << std::endl;
      }
    }
  }
};

#endif  // ANIMALSTATUSSYSTEM_HPP