add_test([=[OrderTest.Construction]=]  /home/andy0/Projects/order-book-engine/build/order_tests [==[--gtest_filter=OrderTest.Construction]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[OrderTest.Construction]=]  PROPERTIES WORKING_DIRECTORY /home/andy0/Projects/order-book-engine/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  order_tests_TESTS OrderTest.Construction)
