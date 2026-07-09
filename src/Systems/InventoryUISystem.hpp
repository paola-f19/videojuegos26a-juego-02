#ifndef INVENTORYUISYSTEM_HPP
#define INVENTORYUISYSTEM_HPP

#include <SDL2/SDL.h>

#include "../Components/InventoryComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/PlayerComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class InventoryUISystem : public System {
  private:
    void DrawSlotBackground(SDL_Renderer* renderer, const SDL_Rect& rect) {
      SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        0
      );

      SDL_RenderDrawRect(
        renderer,
        &const_cast<SDL_Rect&>(rect)
      );
    }

    void DrawSlotItem(
      SDL_Renderer* renderer,
      const SDL_Rect& rect,
      const std::string& itemId,
      const std::unique_ptr<AssetManager>& assetManager,
      const std::unique_ptr<ItemManager>& itemManager) {

      if (itemId == "none") {
        return;
      }

      const auto& item = itemManager->GetItem(itemId);

      SDL_Texture* texture = assetManager->GetTexture(item.textureId);

      SDL_Rect dstRect {
        rect.x + 2,
        rect.y + 2,
        rect.w - 4,
        rect.h - 4
      };

      SDL_RenderCopy(
        renderer,
        texture,
        &item.srcRect,
        &dstRect
      );
    }

  public:
    InventoryUISystem() {
      RequireComponent<InventoryComponent>();
      RequireComponent<PlayerComponent>();
    }

    void Update(SDL_Renderer* renderer
      , const std::unique_ptr<AssetManager>& assetManager
      , const std::unique_ptr<ItemManager>& itemManager) {
      for (auto entity : GetSystemEntities()) {
        const auto& inventory = entity.GetComponent<InventoryComponent>();
        
        SDL_Rect slot1Rect {
          10,
          30,
          24,
          24
        };

        SDL_Rect slot2Rect {
          40,
          30,
          24,
          24
        };

        DrawSlotBackground(renderer, slot1Rect);
        DrawSlotBackground(renderer, slot2Rect);

        DrawSlotItem(
          renderer,
          slot1Rect,
          inventory.slot1.itemId,
          assetManager,
          itemManager
        );

        DrawSlotItem(
          renderer,
          slot2Rect,
          inventory.slot2.itemId,
          assetManager,
          itemManager
        );
      }
    }
};

#endif  // INVENTORYUISYSTEM_HPP