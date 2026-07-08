#ifndef ANIMALBARSYSTEM_HPP
#define ANIMALBARSYSTEM_HPP

#include <SDL2/SDL.h>

#include "../Components/AnimalLeaderComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class AnimalBarSystem : public System {
public:
  AnimalBarSystem() {
    RequireComponent<AnimalLeaderComponent>();
    RequireComponent<TransformComponent>();
  }

  void Update(SDL_Renderer* renderer, const SDL_Rect& camera) {
    for (auto entity : GetSystemEntities()) {
      auto& transform = entity.GetComponent<TransformComponent>();
      auto& stats = entity.GetComponent<AnimalLeaderComponent>();
            
      // bar pos
      float barX = transform.position.x - camera.x;
      float barY = transform.position.y - camera.y - 30.0f;
            
      float barWidth = 40.0f;
      float barHeight = 4.0f;
      float spacing = 5.0f;
            
      // happiness (yellow)
      float happinessPercent = stats.currentHappiness / stats.maxHappiness;
      SDL_Rect happinessRect = {
        static_cast<int>(barX),
        static_cast<int>(barY),
        static_cast<int>(barWidth * happinessPercent),
        static_cast<int>(barHeight)
      };
      SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);
      SDL_RenderFillRect(renderer, &happinessRect);
            
      // Hunger (red)
      float hungerPercent = stats.currentHunger / stats.maxHunger;
      SDL_Rect hungerRect = {
        static_cast<int>(barX),
        static_cast<int>(barY + barHeight + spacing),
        static_cast<int>(barWidth * hungerPercent),
        static_cast<int>(barHeight)
      };
      SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
      SDL_RenderFillRect(renderer, &hungerRect);
            
      // Clean (blue)
      float cleanlinessPercent = stats.currentCleanliness / stats.maxCleanliness;
      SDL_Rect cleanlinessRect = {
        static_cast<int>(barX),
        static_cast<int>(barY + (barHeight + spacing) * 2),
        static_cast<int>(barWidth * cleanlinessPercent),
        static_cast<int>(barHeight)
      };
      SDL_SetRenderDrawColor(renderer, 50, 150, 255, 255); 
      SDL_RenderFillRect(renderer, &cleanlinessRect);
    }
  }
};

#endif