#include <deque>
#include <unordered_map>
#include <map>
#include <optional>
#include "order.hpp"
#include "order_node.hpp"

enum class ActionType {
    NEW_ORDER,
    CANCEL_ORDER
};

class OrderBook {
public:
    OrderBook(/* args */) = delete;
   
    OrderBook(const OrderBook&) = delete; // copy
   
    OrderBook& operator=(const OrderBook&) = delete; // copy asignment
   
    OrderBook(OrderBook&&) = delete; // move
   
    OrderBook& operator=(OrderBook&&) = delete; // move asignment
    
    OrderBook(Instrument); // Book keep a new instrument

    // Add an order to an OrderBook
    // Reccomended to use std::move(order_object)
    void new_order(std::unique_ptr<Order>); // take by value

    // Unhook orders from the map
    void cancel_order(int orderid);

    // return the best bid from the order book relative to an instrument
    // It may be the case that the best bid does not exist
    std::optional<Order> best_bid() const;

    // return the best ask from the order book relative to an instrument
    // It maybe the case that the best bid does not exist
    std::optional<Order> best_ask() const;

    ~OrderBook();
private:
    // <USERIDS, NODES>
    std::unordered_map<int, OrderNode*> id_map_;

    // <PRICE, FIFO<NODES>
    std::map<double, std::deque<std::unique_ptr<OrderNode>>> price_levels_;
    Instrument sym_;
};

