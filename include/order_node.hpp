#ifndef ORDER_NODE_HPP
#define ORDER_NODE_HPP

#include <chrono>

enum class ActionType {
    NEW_ORDER,
    CANCEL_ORDER,
    REPLACE_ORDER
};

class OrderNode {
    public:
    private:
        std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> timestamp_;
        int orderid_;
        ActionType action_;
        OrderNode *next_;
        OrderNode *prev_;
};

#endif