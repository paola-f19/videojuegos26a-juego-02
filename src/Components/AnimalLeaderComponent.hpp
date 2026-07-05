#ifndef ANIMALLEADERCOMPONENT_HPP
#define ANIMALLEADERCOMPONENT_HPP

#include <string>

struct AnimalLeaderComponent {
  // Stats
  float maxHappiness;
  float currentHappiness;
  float maxHunger;
  float currentHunger;
  float maxCleanliness;
  float currentCleanliness;
  
  // Configuration
  int count;
  std::string productId;
  float productionTimer;
  float productionInterval;
  float decayRate;
  float threshold;

  AnimalLeaderComponent(
    std::string productId = "slime_product",
    float maxHappiness = 100.0f,
    float currentHappiness = 100.0f,
    float maxHunger = 100.0f,
    float currentHunger = 100.0f,
    float maxCleanliness = 100.0f,
    float currentCleanliness = 100.0f,
    int count = 1,
    float productionInterval = 10.0f,
    float decayRate = 2.0f,
    float threshold = 40.0f
  ) : productId(productId),
      maxHappiness(maxHappiness),
      currentHappiness(currentHappiness),
      maxHunger(maxHunger),
      currentHunger(currentHunger),
      maxCleanliness(maxCleanliness),
      currentCleanliness(currentCleanliness),
      count(count),
      productionTimer(0.0f),
      productionInterval(productionInterval),
      decayRate(decayRate),
      threshold(threshold) {}
};

#endif