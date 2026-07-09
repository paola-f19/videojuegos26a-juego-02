#ifndef RENDERORDERUISYSTEM_HPP
#define RENDERORDERUISYSTEM_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class RenderOrderUISystem : public System {
  public:
    RenderOrderUISystem() {}

    void Update(SDL_Renderer* renderer,
      const std::unique_ptr<AssetManager>& assetManager) {

      auto& order = Game::GetInstance().orderManager->order;

      const int startX = 10;
      const int startY = 70;

      const int iconSize = 16;
      const int rowSpacing = 30;

      int currentY = startY;

      for (const auto& requirement : order) {

        // Draw icon
        const auto& item = Game::GetInstance().itemManager
          ->GetItem(requirement.itemId);

        SDL_Rect srcRect = item.srcRect;
        SDL_Rect dstRect = {
          startX,
          currentY,
          iconSize,
          iconSize
        };

        SDL_RenderCopy(
          renderer,
          assetManager->GetTexture(item.textureId),
          &srcRect,
          &dstRect
        );

        // Draw quantity
        std::string progress = std::to_string(requirement.delivered) + "/"
          + std::to_string(requirement.required);

        SDL_Color color = { 0, 0, 0, 0 };

        SDL_Surface* surface = TTF_RenderText_Blended(
          assetManager->GetFont("press_start_8"),
          progress.c_str(),
          color
        );

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect textRect = {
          startX + 25,
          currentY + 5,
          surface->w,
          surface->h
        };

        SDL_FreeSurface(surface);

        SDL_RenderCopy(
          renderer,
          texture,
          nullptr,
          &textRect
        );

        SDL_DestroyTexture(texture);

        currentY += rowSpacing;
      }
    }
};

#endif  // RENDERORDERUISYSTEM_HPP