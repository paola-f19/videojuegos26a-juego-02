#ifndef FOLLOWCOMPONENT_HPP
#define FOLLOWCOMPONENT_HPP

/**
 * @brief Defines a movement pattern where the entity follows the player.
 */
struct FollowComponent {
  float speed;
  bool isFollowing;

  /**
   * @brief Constructor.
   *
   * @param speed Movement speed.
   * @param isFollowing Whether the entity is currently following.
   */
  FollowComponent(float speed = 0.0f, bool isFollowing = true) {
    this->speed = speed;
    this->isFollowing = isFollowing;
  }
};

#endif  // FOLLOWCOMPONENT_HPP