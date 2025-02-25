#include "order_book.h"

// Constructor initializes the priority queues
OrderBook::OrderBook()
    : buyOrders([](const Order& a, const Order& b) { return a.price < b.price; }),  // Max-heap for buy orders
    sellOrders([](const Order& a, const Order& b) { return a.price > b.price; }) // Min-heap for sell orders
{
}

// Add an order to the appropriate queue
void OrderBook::addOrder(const Order& order) {
    if (order.type == OrderType::BUY) {
        buyOrders.push(order);
    }
    else if (order.type == OrderType::SELL) {
        sellOrders.push(order);
    }
}

// Match orders in the order book
void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        Order buy = buyOrders.top();
        Order sell = sellOrders.top();

        // Check if a match is possible
        if (buy.price >= sell.price) {
            int matchedQuantity = std::min(buy.quantity, sell.quantity);
            std::cout << "Matched " << matchedQuantity << " units at price " << sell.price << "\n";

            // Update quantities
            buy.quantity -= matchedQuantity;
            sell.quantity -= matchedQuantity;

            // Remove or update orders in the queues
            buyOrders.pop();
            if (buy.quantity > 0) {
                buyOrders.push(buy);
            }

            sellOrders.pop();
            if (sell.quantity > 0) {
                sellOrders.push(sell);
            }
        }
        else {
            break; // No more matches possible
        }
    }
}