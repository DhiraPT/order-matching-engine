// OrderMatchingEngine.cpp : Defines the entry point for the application.
//

#include "order.h"
#include "order_book.h"
#include <iostream>

int main() {
    OrderBook book;
    book.addOrder(Order(1, OrderType::BUY, 20.0, 10));
    book.addOrder(Order(2, OrderType::SELL, 95.0, 5));
    book.addOrder(Order(1, OrderType::BUY, 100.0, 8));
    book.addOrder(Order(2, OrderType::SELL, 65.0, 5));

    std::cout << "Matching Orders...\n";
    book.matchOrders();

    return 0;
}
