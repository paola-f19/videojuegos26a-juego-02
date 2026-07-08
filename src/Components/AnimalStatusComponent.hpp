#ifndef ANIMALSTATUSCOMPONENT_HPP
#define ANIMALSTATUSCOMPONENT_HPP

struct AnimalStatusComponent {
  bool struckByLightning = false;
  float statusTimer = 0.0f;

  AnimalStatusComponent() {};
};

#endif  // ANIMALSTATUSCOMPONENT_HPP