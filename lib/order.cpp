#include "order.h"
#include <sstream>

/**
 * Order.
 */
Order::Order(int id, OrderType type, double price, int quantity)
    : id(id), type(type), price(price), quantity(quantity) {
}

// Convert order details to string
std::string Order::toString() const {
    std::ostringstream oss;
    oss << "Order(ID: " << id
        << ", Type: " << (type == OrderType::BUY ? "BUY" : "SELL")
        << ", Price: " << price
        << ", Quantity: " << quantity << ")";
    return oss.str();
}
