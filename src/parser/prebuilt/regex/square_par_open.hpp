#ifndef PARSER_PREBUILT_REGEX_SQUARE_PAR_OPEN_HPP
#define PARSER_PREBUILT_REGEX_SQUARE_PAR_OPEN_HPP

#include <string>

#include <parser/parse_node.hpp>

namespace gpt::regex
{
    class square_par_open : public gpt::parse_node<bool>
    {
        private:
            using node = gpt::parse_node<bool>;

        public:
            static const inline std::string identifier = "[";
            static const inline auto        type       = node::type::DELIMITER_START;

        public:
            inline explicit square_par_open(const std::string&): node(identifier, type)
            {
            }

            inline bool compute(std::string& expression) override
            {
                if (expression.empty())
                {
                    return false;
                }

                for (auto& child: this->children)
                {
                    auto expression_copy = expression;
                    if (child->compute(expression_copy))
                    {
                        expression = expression_copy;
                        return true;
                    }
                }

                return false;
            }

            inline std::string to_string() override
            {
                std::string result = "[";

                for (auto& child: this->children)
                {
                    result += child->to_string();
                }

                result += "]";

                return result;
            }
    };
}// namespace gpt::regex

#endif// PARSER_PREBUILT_REGEX_SQUARE_PAR_OPEN_HPP
