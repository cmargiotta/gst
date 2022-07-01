#ifndef PARSER_PREBUILT_ARITHMETIC_PAR_OPEN_HPP
#define PARSER_PREBUILT_ARITHMETIC_PAR_OPEN_HPP

#include <cstdint>
#include <string>

#include <parser/parse_node.hpp>

namespace gpt::arithmetic
{
    class par_open : public gpt::parse_node<int, void>
    {
        private:
            using node = gpt::parse_node<int, void>;

        private:
            std::string to_string_() override
            {
                return "(";
            }

        public:
            static const inline std::string identifier = "\\(";
            static const inline auto        type       = node::type::DELIMITER_START;

        public:
            inline explicit par_open(const std::string&): node(identifier, type)
            {
            }

            inline int compute() override
            {
                return children[0]->compute();
            }

            inline std::string to_string() override
            {
                std::string result = "(";

                result += children[0]->to_string() + ")";

                return result;
            }
    };
}// namespace gpt::arithmetic

#endif// PARSER_PREBUILT_ARITHMETIC_PAR_OPEN_HPP
