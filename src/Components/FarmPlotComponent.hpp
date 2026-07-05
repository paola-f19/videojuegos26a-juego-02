#ifndef FARMPLOTCOMPONENT_HPP
#define FARMPLOTCOMPONENT_HPP

#include <string>

#include "../ECS/ECS.hpp"

struct FarmPlotComponent {
  bool occupied = false;
  Entity plantedCropEntity{-1};
  std::string cropId;

  FarmPlotComponent(const std::string& cropId = "")  {
    this->cropId = cropId;
  }
};

#endif  // FARMPLOTCOMPONENT_HPP