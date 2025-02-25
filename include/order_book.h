#pragma once

#include "order.h"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>

class OrderBook {
private:
    // Priority queues for buy and sell orders
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> buyOrders;
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> sellOrders;

public:
    // Constructor
    OrderBook();

    // Add an order to the order book
    void addOrder(const Order& order);

    // Match orders in the order book
    void matchOrders();
};
