#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

enum class OrderType { BUY, SELL };

class Order {
public:
    int id;                    // Order ID
    OrderType type;            // Order type (BUY or SELL)
    double price;              // Price of the order
    int quantity;              // Quantity of the order

    // Constructor
    Order(int id, OrderType type, double price, int quantity);

    // Convert order details to string (for debugging/logging)
    std::string toString() const;
};
