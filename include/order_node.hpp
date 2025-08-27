#ifndef ORDER_NODE_HPP
#define ORDER_NODE_HPP

#include <chrono>
#include <memory>
#include "order.hpp"

class OrderNode {
    public:
        OrderNode() = delete;
        OrderNode(const OrderNode&) = delete;
        OrderNode& operator&=(const OrderNode&) = delete;
        OrderNode(OrderNode&&) = delete;
        OrderNode& operator&=(OrderNode&&) = delete;
        
        OrderNode(std::unique_ptr<Order> order)
            : timestamp_(std::chrono::steady_clock::now()),
            order_(std::move(order)) {}

        ~OrderNode();
    private:
        std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> timestamp_;
        std::unique_ptr<Order> order_;
};

#endif