#ifndef CROPCOMPONENT_HPP
#define CROPCOMPONENT_HPP

#include <string>

struct CropComponent {
  std::string id;
  float growthTimer;
  float growthTime;
  bool harvestable;
  bool watered = false;

  // growth visuals
  int growthStages = 6;
  int currenStage = 0;

  CropComponent(std::string id = "", float growthTimer = 0.0f
    , float growthTime = 0.0f, bool harvestable = false) {
    this->id = id;
    this->growthTimer = growthTimer;
    this->growthTime = growthTime;
    this->harvestable = harvestable;
  }
};

#endif  // CROPCOMPONENT_HPP