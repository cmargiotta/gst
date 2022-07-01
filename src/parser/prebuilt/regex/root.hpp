#ifndef PARSER_PREBUILT_REGEX_ROOT_HPP
#define PARSER_PREBUILT_REGEX_ROOT_HPP

#include <string>

#include <parser/parse_node.hpp>

namespace gpt::regex
{
    class root : public gpt::parse_node<bool>
    {
        private:
            using node = gpt::parse_node<bool>;

        public:
            root(): node("", node::type::ROOT, node::operands_order::ROOT)
            {
            }

            bool compute(ExpectedInputType& expr) override
            {
                bool result = true;

                for (auto& child: this->children)
                {
                    result = result && child->compute(expr);
                }

                return result;
            }

            bool is_exact_matcher()
            {
                for (auto& child: this->children)
                {
                    if (child->get_type() != node::type::LEAF)
                    {
                        return false;
                    }
                }

                return true;
            }

            inline root& operator+=(std::unique_ptr<root>&& other)
            {
                merge(std::move(other));
                return *this;
            }

            void merge(std::unique_ptr<root>&& other);
    };
}// namespace gpt::regex

#endif// PARSER_PREBUILT_REGEX_ROOT_HPP
