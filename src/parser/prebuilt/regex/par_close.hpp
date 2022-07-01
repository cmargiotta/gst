#ifndef PARSER_PREBUILT_REGEX_ROUND_PAR_CLOSE_HPP
#define PARSER_PREBUILT_REGEX_ROUND_PAR_CLOSE_HPP

#include <string>

#include <parser/parse_node.hpp>

namespace gpt::regex
{
    class par_close : public gpt::parse_node<bool>
    {
        private:
            using node = gpt::parse_node<bool>;

        public:
            static const inline std::string identifier = "),]";
            static const inline auto        type       = node::type::DELIMITER_END;

        public:
            inline explicit par_close(const std::string&): node(identifier, type)
            {
            }

            inline bool compute(std::string& expression) override
            {
                return true;
            }
    };
}// namespace gpt::regex

#endif// PARSER_PREBUILT_REGEX_ROUND_PAR_CLOSE_HPP
