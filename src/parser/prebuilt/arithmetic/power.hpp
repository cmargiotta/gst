#ifndef PARSER_PREBUILT_ARITHMETIC_POWER_HPP
#define PARSER_PREBUILT_ARITHMETIC_POWER_HPP

#include <cmath>
#include <cstdint>
#include <string>

#include <parser/parse_node.hpp>

namespace gpt::arithmetic
{
    class power : public gpt::parse_node<int, void>
    {
        private:
            using node = gpt::parse_node<int, void>;

        public:
            static const inline std::string identifier     = "^";
            static const inline auto        type           = node::type::OPERATOR;
            static const inline auto        operands_order = node::operands_order::LEFT_RIGHT;

        public:
            inline explicit power(const std::string&): node(identifier, type, operands_order)
            {
            }

            inline int compute() override
            {
                return static_cast<int>(pow(children[0]->compute(), children[1]->compute()));
            }
    };
}// namespace gpt::arithmetic

#endif// PARSER_PREBUILT_ARITHMETIC_POWER_HPP
