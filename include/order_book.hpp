#include <deque>
#include <unordered_map>
#include <map>
#include <optional>
#include "order.hpp"
#include "order_node.hpp"
#include "instrument.hpp"

enum class ActionType {
    NEW_ORDER,
    CANCEL_ORDER,
    REPLACE_ORDER
};

class OrderBook
{
public:
    OrderBook(/* args */) = delete;
   
    OrderBook(const OrderBook&) = delete; // copy
   
    OrderBook& operator=(const OrderBook&) = delete; // copy asignment
   
    OrderBook(OrderBook&&) = delete; // move
   
    OrderBook& operator=(OrderBook&&) = delete; // move asignment
    
    OrderBook(Instrument);

    // Add an order to an OrderBook
    // Reccomended to use std::move(order_object)
    void add_order(Order&&);
    void add_order(const Order&);

    // Unhook orders from the map
    void cancel_order(int orderid);

    // return the best bid from the order book relative to an instrument
    // It may be the case that the best bid does not exist
    std::optional<Order> best_bid() const;

    // return the best ask from the order book relative to an instrument
    // It mayb e the case that the best bid does not exist
    std::optional<Order> best_ask() const;

    ~OrderBook();
private:
    std::unordered_map<int, OrderNode*> id_map_;
    std::map<double, std::deque<OrderNode>> price_levels_;
    Instrument sym_;
};

OrderBook::OrderBook(/* args */)
{
}

OrderBook::~OrderBook()
{
}
