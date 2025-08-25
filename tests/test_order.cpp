#include <gtest/gtest.h>
#include "order.hpp"

TEST(OrderTest, Construction) {
    Order o(Side::BUY, 100.0, 10, OrderType::LIMIT, TimeInForce::GTC, Instrument::TAS);

    EXPECT_EQ(o.side(), Side::BUY);
    EXPECT_DOUBLE_EQ(o.price(), 100.0);
    EXPECT_EQ(o.quantity(), 10);
    EXPECT_EQ(o.remaining_quantity(), 10);
}
