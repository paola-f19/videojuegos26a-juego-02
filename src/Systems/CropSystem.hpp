#ifndef CROPSYSTEM_HPP
#define CROPSYSTEM_HPP

#include <glm/glm.hpp>

#include <iostream>

#include "../Components/CropComponent.hpp"
#include "../Components/FarmPlotComponent.hpp"
#include "../Components/ItemComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"
#include "../Game/Game.hpp"

class CropSystem : public System {
  private:
    Entity CreateCrop(const std::string& cropId, Entity plot) {
      Entity crop = Game::GetInstance().registry->CreateEntity();

      auto& plotTransform = plot.GetComponent<TransformComponent>();

      const auto& item = Game::GetInstance().itemManager->GetItem(cropId);

      crop.AddComponent<CropComponent>(
        cropId,
        0.0f,
        10.0f,
        false
      );

      crop.AddComponent<TransformComponent>(
        plotTransform.position,
        glm::vec2(1.0f, 1.0f),
        0.0f
      );

      crop.AddComponent<SpriteComponent>(
        item.id,
        item.width,
        item.height,
        item.srcRect.x,
        item.srcRect.y,
        glm::vec2(0, 0)
      );

      return crop;
    }

    std::string GetHarvestItemId(const std::string& cropId) {
      const std::string suffix = "_seeds";

      if (cropId.size() >= suffix.size() &&
        cropId.substr(
            cropId.size() - suffix.size()
        ) == suffix)
      {
        return cropId.substr(
            0,
            cropId.size() - suffix.size()
        );
      }
      return cropId;
    }

    void CreateHarvestedCrop(const std::string& cropId, Entity plot) {
      auto& transform = plot.GetComponent<TransformComponent>();

      std::string harvestedItemId = GetHarvestItemId(cropId);

      const auto& item = Game::GetInstance()
        .itemManager->GetItem(harvestedItemId);

      Entity crop = Game::GetInstance().registry->CreateEntity();
      
      crop.AddComponent<TransformComponent>(
        glm::vec2(
          transform.position.x,
          transform.position.y
        ),
        glm::vec2(1.0f, 1.0f),
        0.0f
      );

      crop.AddComponent<SpriteComponent>(
        item.id,
        item.width,
        item.height,
        item.srcRect.x,
        item.srcRect.y,
        glm::vec2(0, 0)
      );

      crop.AddComponent<ItemComponent>(item.id);

      crop.AddComponent<BoxColliderComponent>(
        item.width,
        item.height,
        glm::vec2(0, 0)
      );
    }

    void UpdateGrowthSprite(Entity crop) {
      auto& cropComponent = crop.GetComponent<CropComponent>();
      auto& sprite = crop.GetComponent<SpriteComponent>();

      float progress = cropComponent.growthTimer / cropComponent.growthTime;

      int newStage = static_cast<int>(progress
        * (cropComponent.growthStages - 1));

      if (newStage > (cropComponent.growthStages - 1)) {
        newStage = cropComponent.growthStages - 1;
      }

      if (newStage != cropComponent.currenStage) {
        cropComponent.currenStage = newStage;

        sprite.srcRect.x = cropComponent.currenStage * 16;

        std::cout << cropComponent.id << " advanced to stage " 
          << cropComponent.currenStage << std::endl;
      }
    }

  public:
    CropSystem() {
      RequireComponent<CropComponent>();
    }

    void PlantCrop(Entity plot, const std::string& cropId) {
      auto& farmPlot = plot.GetComponent<FarmPlotComponent>();

      if (farmPlot.occupied)
        return;

      Entity crop = CreateCrop(cropId, plot);

      farmPlot.occupied = true;
      farmPlot.plantedCropEntity = crop;

      std::cout << "Planted " << cropId << std::endl;
    }

    void HarvestCrop(Entity plot) {
      auto& farmPlot = plot.GetComponent<FarmPlotComponent>();

      if (!farmPlot.occupied)
        return;

      Entity crop = farmPlot.plantedCropEntity;

      auto& cropComponent = crop.GetComponent<CropComponent>();

      if (!cropComponent.harvestable) {
        std::cout << "Crop not ready!" << std::endl;
        return;
      }

      CreateHarvestedCrop(cropComponent.id, plot);

      std::cout << "Harvested " << cropComponent.id << std::endl;

      crop.Kill();

      farmPlot.occupied = false;
      farmPlot.plantedCropEntity = Entity(-1);
    }

    void WaterCrop(Entity plot) {
      auto& farmPlot = plot.GetComponent<FarmPlotComponent>();

      if (!farmPlot.occupied)
        return;

      Entity crop = farmPlot.plantedCropEntity;

      auto& cropComponent = crop.GetComponent<CropComponent>();

      cropComponent.watered = true;

      std::cout << "Crop watered!" << std::endl;
    }

    void Update(float deltaTime) {
      for (auto crop : GetSystemEntities()) {

        auto& cropComponent = crop.GetComponent<CropComponent>();

        if (!cropComponent.harvestable) {
          if (cropComponent.watered) {
            cropComponent.growthTimer += deltaTime;
          }

          if (cropComponent.growthTimer >= cropComponent.growthTime) {
            cropComponent.harvestable = true;
            std::cout << cropComponent.id << " is ready to harvest!" << std::endl;
          }
        }
        UpdateGrowthSprite(crop);
      }
    }
};

#endif  // CROPSYSTEM_HPP