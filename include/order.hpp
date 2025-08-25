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
        
    private:
        Side side_;
        int price_;
        int quantity_;
        int remaining_quantity_;
        OrderType type_;
        TimeInForce tif_;
        Instrument sym_;
};

#endif