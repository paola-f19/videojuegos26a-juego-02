#ifndef ORDERMANAGER_HPP
#define ORDERMANAGER_HPP

#include <string>
#include <vector>

struct OrderRequirement {
  std::string itemId;
  int required;
  int delivered;
};

class OrderManager {
  public:
    std::vector<OrderRequirement> order;

    OrderManager();
    ~OrderManager();

    void ClearOrder();

    bool IsComplete();
};

#endif  // ORDERMANAGER_HPP