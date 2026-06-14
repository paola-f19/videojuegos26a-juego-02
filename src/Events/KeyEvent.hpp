#ifndef KEYEVENT_HPP
#define KEYEVENT_HPP

#include "../ECS/ECS.hpp"
#include "../EventManager/Event.hpp"

class KeyEvent : public Event {
  public:
    char key;

    KeyEvent(char key = 'q') {
      this->key = key;
    }
};

#endif  // KEYEVENT_HPP