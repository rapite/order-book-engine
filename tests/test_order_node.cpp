#include "order_node.hpp"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>

// Test construction with valid order
TEST(OrderNodeTest, ConstructWithOrder) {
    auto order = std::make_unique<Order>(
        Side::BUY,
        100.0,
        1,
        10,
        OrderType::LIMIT,
        TimeInForce::DAY,
        Instrument::ASDF
    );

    OrderNode node(std::move(order));

    ASSERT_NE(node.GetOrder(), nullptr);
    EXPECT_EQ(node.GetOrder()->GetID(), 1);
    EXPECT_EQ(node.GetOrder()->GetQuantity(), 10);
    EXPECT_EQ(node.GetOrder()->GetPrice(), 100.0);
    EXPECT_EQ(node.GetOrder()->GetSide(), Side::BUY);
}

// Test timestamp is set to around now
TEST(OrderNodeTest, TimestampIsSet) {
    auto before = std::chrono::steady_clock::now();
    auto order = std::make_unique<Order>(
        Side::SELL,
        200.0,
        5,
        2,
        OrderType::LIMIT,
        TimeInForce::DAY,
        Instrument::ASDF
    );

    OrderNode node(std::move(order));
    auto after = std::chrono::steady_clock::now();

    auto ts = node.GetTimestamp();
    EXPECT_GE(ts, before);
    EXPECT_LE(ts, after);
}

// Test ownership transfer of unique_ptr
TEST(OrderNodeTest, OwnershipTransfer) {
    auto order = std::make_unique<Order>(
        Side::BUY,
        150.0,
        1,
        20,
        OrderType::LIMIT,
        TimeInForce::DAY,
        Instrument::ASDF
    );

    Order* rawPtr = order.get();

    OrderNode node(std::move(order));

    // Original unique_ptr should be null after move
    EXPECT_EQ(order, nullptr);

    // Node should still own the order
    ASSERT_NE(node.GetOrder(), nullptr);
    EXPECT_EQ(node.GetOrder(), rawPtr);
}