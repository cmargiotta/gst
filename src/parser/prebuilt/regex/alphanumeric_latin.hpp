#ifndef PARSER_PREBUILT_REGEX_ALPHANUMERIC_LATIN_HPP
#define PARSER_PREBUILT_REGEX_ALPHANUMERIC_LATIN_HPP

#include <string>

#include <parser/parse_node.hpp>

namespace gpt::regex
{
    class alphanumeric_latin : public gpt::parse_node<bool>
    {
        private:
            using node = gpt::parse_node<bool>;

        public:
            static const inline std::string identifier = "\\w";
            static const inline auto        type       = node::type::LEAF;

        public:
            inline explicit alphanumeric_latin(const std::string&): node(identifier, type)
            {
            }

            inline bool compute(std::string& expression) override
            {
                if (expression.empty())
                {
                    return false;
                }

                char to_match = expression[0];
                expression    = expression.substr(1);

                return (to_match >= 'a' && to_match <= 'z') || (to_match >= 'A' && to_match <= 'Z')
                       || (to_match >= '0' && to_match <= '9');
            }
    };
}// namespace gpt::regex

#endif// PARSER_PREBUILT_REGEX_ALPHANUMERIC_LATIN_HPP
