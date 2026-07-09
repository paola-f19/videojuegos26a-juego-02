#ifndef PLAYERCOMPONENT_HPP
#define PLAYERCOMPONENT_HPP

struct PlayerComponent {
  Entity currentFarmPlot{-1};

  Entity currentAnimalContact{-1};

  Entity currentDeliveryZone{-1};

  PlayerComponent() {};
};

#endif  // PLAYERCOMPONENT_HPP