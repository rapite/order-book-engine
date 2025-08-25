#ifndef ORDER_H
#define ORDER_H

#include "instrument.hpp"

enum class OrderType {
    LIMIT,
    MARKET,
    STOP,
    STOP_LIMIT,
    PEGGED,
    DISCRETIONARY_LIMIT,
    ICEBERG
};

enum class TimeInForce {
    DAY,
    GTC,
    GTD,
    IOC,
    FOK
};

enum class Side {
    BUY,
    SELL
};

class Order {
    public:
        Order() = delete; // delete default constructor

        // custom constructor to replace default constructor
        Order(Side, double, int, OrderType, TimeInForce, Instrument);
 
        Order(const Order&) = delete; // delete copy constructor
        
        Order& operator=(const Order&) = delete; // delete copy assignment
        
        Order(Order&&) = delete; // delete move constructor
        
        Order& operator=(Order&&) = delete; // delete move assignment
       
        Side side() const { return side_; }
        int price() const { return price_; }
        int quantity() const { return quantity_; }
        int remaining_quantity() const { return remaining_quantity_; }
        OrderType type() const { return type_; }
        TimeInForce tif() const { return tif_; }
        Instrument sym() const {return sym_; }

        ~Order() = default;

    private:
        Side side_;
        double price_;
        int quantity_;
        int remaining_quantity_;
        OrderType type_;
        TimeInForce tif_;
        Instrument sym_;
};

#endif