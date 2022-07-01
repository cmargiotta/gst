#ifndef PARSER_PREBUILT_ARITHMETIC_PAR_CLOSE_HPP
#define PARSER_PREBUILT_ARITHMETIC_PAR_CLOSE_HPP

#include <cstdint>
#include <string>

#include <parser/parse_node.hpp>

namespace gpt::arithmetic
{
    class par_close : public gpt::parse_node<int, void>
    {
        private:
            using node = gpt::parse_node<int, void>;

        private:
            std::string to_string_() override
            {
                return ")";
            }

        public:
            static const inline std::string identifier = "\\)";
            static const inline auto        type       = node::type::DELIMITER_END;

        public:
            inline explicit par_close(const std::string&): node(identifier, type)
            {
            }

            inline int compute() override
            {
                return 0;
            }
    };
}// namespace gpt::arithmetic

#endif// PARSER_PREBUILT_ARITHMETIC_PAR_CLOSE_HPP
