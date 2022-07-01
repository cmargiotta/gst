#ifndef PARSER_PREBUILT_ARITHMETIC_ROOT_HPP
#define PARSER_PREBUILT_ARITHMETIC_ROOT_HPP

#include <string>

#include <parser/parse_node.hpp>

namespace gpt::arithmetic
{
    class root : public gpt::parse_node<int, void>
    {
        private:
            using node = gpt::parse_node<int, void>;

        public:
            root(): node("", node::type::ROOT, node::operands_order::ROOT)
            {
            }

            int compute() override
            {
                return children[0]->compute();
            }
    };
}// namespace gpt::arithmetic

#endif// PARSER_PREBUILT_ARITHMETIC_ROOT_HPP
