#ifndef FOLLOWSYSTEM_HPP
#define FOLLOWSYSTEM_HPP

#include "../Components/FollowComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../ECS/ECS.hpp"

class FollowSystem : public System {
public:
  FollowSystem() {
    RequireComponent<FollowComponent>();
    RequireComponent<TransformComponent>();
  }

  void Update(float deltatime, TransformComponent& playerTransform) {
    for (auto entity : GetSystemEntities()) {
      auto& transform = entity.GetComponent<TransformComponent>();
      auto& follow = entity.GetComponent<FollowComponent>();

      if (!follow.isFollowing) continue;

      glm::vec2 toPlayer = playerTransform.position - transform.position;
      float distance = glm::length(toPlayer);

      if (distance > 0.0f) {
        glm::vec2 direction = glm::normalize(toPlayer);
        transform.position += direction * follow.speed * deltatime;
      }
    }
  }
};

#endif