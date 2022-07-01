#ifndef PARSER_PREBUILT_MATH_FUNCTION_POWER_HPP
#define PARSER_PREBUILT_MATH_FUNCTION_POWER_HPP

#include <cmath>
#include <cstdint>
#include <string>

#include <parser/prebuilt/math_function/base_node.hpp>

namespace gpt::math_function
{
    class power : public base_node
    {
        private:
            using node = base_node::node;

        public:
            static const inline std::string identifier     = "^";
            static const inline auto        type           = node::type::OPERATOR;
            static const inline auto        operands_order = node::operands_order::LEFT_RIGHT;

        public:
            inline explicit power(const std::string&): base_node(identifier, type, operands_order)
            {
            }

            inline gpt::math::fraction<int>
                compute(std::unordered_map<std::string, gpt::math::fraction<int>>& input) override
            {
                return pow(children[0]->compute(input), children[1]->compute(input));
            }
    };
}// namespace gpt::math_function

#endif// PARSER_PREBUILT_MATH_FUNCTION_POWER_HPP
