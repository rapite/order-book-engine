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
    Order(Side, double, int, int, OrderType, TimeInForce, Instrument);

    Order(const Order&) = delete; // delete copy constructor

    Order& operator=(const Order&) = delete; // delete copy assignment
    
    Order(Order&&) = delete; // delete move constructor
    
    Order& operator=(Order&&) = delete; // delete move assignment
    
    Side GetSide() const { return side_; }
    int GetPrice() const { return price_; }
    int GetQuantity() const { return quantity_; }
    int GetRemainingQuantity() const { return remaining_quantity_; }
    OrderType GetType() const { return type_; }
    TimeInForce GetTIF() const { return tif_; }
    Instrument GetSym() const {return sym_; }

    ~Order() = default;

private:
    Side side_;
    double price_;
    int orderID_;
    int quantity_;
    int remaining_quantity_;
    OrderType type_;
    TimeInForce tif_;
    Instrument sym_;
};

#endif