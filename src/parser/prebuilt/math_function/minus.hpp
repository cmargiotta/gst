#ifndef PARSER_PREBUILT_MATH_FUNCTION_MINUS_HPP
#define PARSER_PREBUILT_MATH_FUNCTION_MINUS_HPP

#include <cstdint>
#include <string>

#include <parser/prebuilt/math_function/base_node.hpp>

namespace gpt::math_function
{
    class minus : public base_node
    {
        private:
            using node = base_node::node;

        private:
            std::string to_string_() override
            {
                return "-";
            }

        public:
            static const inline std::string identifier     = "\\-";
            static const inline auto        type           = node::type::OPERATOR;
            static const inline auto        operands_order = node::operands_order::LEFT_RIGHT;

        public:
            inline explicit minus(const std::string&): base_node(identifier, type, operands_order)
            {
            }

            inline gpt::math::fraction<int>
                compute(std::unordered_map<std::string, gpt::math::fraction<int>>& input) override
            {
                return children[0]->compute(input) - children[1]->compute(input);
            }
    };
}// namespace gpt::math_function

#endif// PARSER_PREBUILT_MATH_FUNCTION_MINUS_HPP
