#ifndef PARSER_PREBUILT_MATH_FUNCTION_NUMBER_HPP
#define PARSER_PREBUILT_MATH_FUNCTION_NUMBER_HPP

#include <cstdint>
#include <string>
#include <unordered_map>

#include <parser/prebuilt/math_function/base_node.hpp>

namespace gpt::math_function
{
    class number : public base_node
    {
        private:
            using node = base_node::node;

            const gpt::math::fraction<int> value;

        public:
            static const inline std::string identifier = "\\-?[0-9]+";
            static const inline auto        type       = node::type::LEAF;

        public:
            inline explicit number(const std::string& token)
                : base_node(identifier, type), value(std::stoi(token))
            {
            }

            inline gpt::math::fraction<int>
                compute(std::unordered_map<std::string, gpt::math::fraction<int>>&) override
            {
                return value;
            }

            inline std::string to_string() override
            {
                return static_cast<std::string>(value);
            }
    };
}// namespace gpt::math_function

#endif// PARSER_PREBUILT_MATH_FUNCTION_NUMBER_HPP
