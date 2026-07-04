#include "OrderManager.hpp"

#include <iostream>

OrderManager::OrderManager() {
  std::cout << "[ORDERMANAGER] Se ejecuta constructor" << std::endl;
}

OrderManager::~OrderManager() {
  std::cout << "[ORDERMANAGER] Se ejecuta destructor" << std::endl;
}

void OrderManager::ClearOrder() {
  order.clear();
}

bool OrderManager::IsComplete() {
  bool complete = true;

  for (auto& requirement : order) {
    if(requirement.delivered < requirement.required) {
      complete = false;
      break;
    }
  }

  return complete;
}