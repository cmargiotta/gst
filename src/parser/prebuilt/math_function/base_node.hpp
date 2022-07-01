#ifndef PARSER_PREBUILT_MATH_FUNCTION_BASE_MATH_NODE_HPP
#define PARSER_PREBUILT_MATH_FUNCTION_BASE_MATH_NODE_HPP

#include <algorithm>
#include <string>
#include <unordered_map>

#include <math/fraction.hpp>
#include <parser/parse_node.hpp>
#include <parser/prebuilt/math_function/base_node.hpp>
#include <parser/prebuilt/math_function/exceptions.hpp>

namespace gpt::math_function
{
    class base_node : public gpt::parse_node<gpt::math::fraction<int>,
                                             std::unordered_map<std::string, gpt::math::fraction<int>>>
    {
        public:
            using node = gpt::parse_node<gpt::math::fraction<int>,
                                         std::unordered_map<std::string, gpt::math::fraction<int>>>;

        public:
            base_node(const std::string& id_,
                      type               t = node::type::LEAF,
                      operands_order     o = node::operands_order::LEFT_RIGHT)
                : node(id_, t, o)
            {
            }

            ~base_node() override = default;

            gpt::math::fraction<int> simplify()
            {
                try
                {
                    std::unordered_map<std::string, gpt::math::fraction<int>> arg;
                    gpt::math::fraction<int>                                  value = compute(arg);

                    return value;
                }
                catch (...)
                {
                    throw(not_simplifiable());
                }
            }
    };
}// namespace gpt::math_function

#endif// PARSER_PREBUILT_MATH_FUNCTION_BASE_MATH_NODE_HPP
