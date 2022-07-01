#include <catch2/catch.hpp>

#include <type_traits>
#include <vector>

#include <concepts.hpp>

void function1();
int  function2(int, int);

struct A
{
        int b;

        virtual ~A() = default;
};

struct B : public A
{
};

struct C
{
};

MAKE_EXISTENCE_VERIFIER(b)

TEST_CASE("Function traits work correctly", "[traits]")
{
    REQUIRE(gpt::with_b<A>);
    REQUIRE(gpt::with_b<B>);
    REQUIRE(!gpt::with_b<C>);

    REQUIRE(gpt::iterator<A*>);
    REQUIRE(!gpt::iterator<A>);
}

TEST_CASE("Iterator trait works correctly", "[traits]")
{
    REQUIRE(gpt::iterator<std::vector<int>::iterator>);
    REQUIRE(gpt::iterator<int*>);
    REQUIRE(!gpt::iterator<int>);
}