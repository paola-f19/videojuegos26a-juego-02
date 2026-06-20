#ifndef FARMPLOTCOMPONENT_HPP
#define FARMPLOTCOMPONENT_HPP

#include <string>

#include "../ECS/ECS.hpp"

struct FarmPlotComponent {
  bool occupied = false;
  Entity plantedCropEntity{-1};

  FarmPlotComponent() {}
};

#endif  // FARMPLOTCOMPONENT_HPP