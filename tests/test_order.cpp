#include <gtest/gtest.h>
#include "order.hpp"

TEST(OrderTest, Construction) {
    Order o(
        Side::BUY,
        100.0,
        1,
        10,
        OrderType::LIMIT,
        TimeInForce::GTC,
        Instrument::TAS
    );

    EXPECT_EQ(o.GetSide(), Side::BUY);
    EXPECT_DOUBLE_EQ(o.GetPrice(), 100.0);
    EXPECT_EQ(o.GetQuantity(), 10);
    EXPECT_EQ(o.GetRemainingQuantity(), 10);
}
