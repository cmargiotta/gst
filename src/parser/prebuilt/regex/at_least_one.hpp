#ifndef PARSER_PREBUILT_REGEX_AT_LEAST_ONE_HPP
#define PARSER_PREBUILT_REGEX_AT_LEAST_ONE_HPP

#include <cstdint>
#include <string>

#include <parser/parse_node.hpp>

namespace gpt::regex
{
    class at_least_one : public gpt::parse_node<bool>
    {
        private:
            using node = gpt::parse_node<bool>;

        public:
            static const inline std::string identifier     = "+";
            static const inline auto        type           = node::type::OPERATOR;
            static const inline auto        operands_order = node::operands_order::LEFT;

        public:
            inline explicit at_least_one(const std::string&): node(identifier, type, operands_order)
            {
            }

            inline bool compute(std::string& expression) override
            {
                if (expression.empty())
                {
                    return false;
                }

                size_t matched = 0;

                while (children.back()->compute(expression))
                {
                    ++matched;
                }

                return matched > 0;
            }
    };
}// namespace gpt::regex

#endif// PARSER_PREBUILT_REGEX_AT_LEAST_ONE_HPP
