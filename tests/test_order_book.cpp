#include <gtest/gtest.h>
#include "order.hpp"
#include "order_book.hpp"

TEST(OrderBookTest, ConstructEmpty) {
    OrderBook book(Instrument::TAS);

    EXPECT_FALSE(book.best_bid().has_value());
    EXPECT_FALSE(book.best_ask().has_value());
}

TEST(OrderBookTest, AddBuyOrderSetsBestBid) {
    OrderBook book(Instrument::TAS);

    Order o1(Side::BUY, 100.0, 10, 1, OrderType::LIMIT, TimeInForce::GTC, Instrument::TAS);
    book.add_order(o1);

    auto bid = book.best_bid();
    ASSERT_TRUE(bid.has_value());
    EXPECT_DOUBLE_EQ(bid->GetPrice(), 100.0);
    EXPECT_EQ(bid->GetQuantity(), 10);
}

TEST(OrderBookTest, AddSellOrderSetsBestAsk) {
    OrderBook book(Instrument::TAS);

    Order o1(Side::SELL, 101.0, 5, 1, OrderType::LIMIT, TimeInForce::GTC, Instrument::TAS);
    book.add_order(o1);

    auto ask = book.best_ask();
    ASSERT_TRUE(ask.has_value());
    EXPECT_DOUBLE_EQ(ask->GetPrice(), 101.0);
    EXPECT_EQ(ask->GetQuantity(), 5);
}

TEST(OrderBookTest, CancelOrderRemovesFromBook) {
    OrderBook book(Instrument::TAS);

    Order o1(Side::BUY, 99.0, 10, 1, OrderType::LIMIT, TimeInForce::GTC, Instrument::TAS);
    book.add_order(o1);

    // book.cancel_order(o1.id());
    EXPECT_FALSE(book.best_bid().has_value());
}
