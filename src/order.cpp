#include <stdexcept>
#include "order.hpp"

Order::Order(Side side, double price, int orderID, int quantity, OrderType type, TimeInForce tif, Instrument sym)
    : side_(side),
      price_(price),
      orderID_(orderID),
      quantity_(quantity),
      remaining_quantity_(quantity),
      type_(type),
      tif_(tif),
      sym_(sym) {
        
    //constraints for valid prices and quantities
    if (price <= 0.0) {
        throw std::invalid_argument("Price must be positive");
    }
    if (quantity <= 0) {
        throw std::invalid_argument("Quantity must be positive");
    }
}
