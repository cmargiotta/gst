#ifndef PARSER_PREBUILT_DICE_ROLLER_DICE_HPP
#define PARSER_PREBUILT_DICE_ROLLER_DICE_HPP

#include <cstdint>
#include <ctime>
#include <random>
#include <string>
#include <vector>

#include <parser/parse_node.hpp>

namespace gpt::dice_roller
{
    class dice : public gpt::parse_node<int, void>
    {
        private:
            using node = gpt::parse_node<int, void>;
            std::mt19937 random_generator;

            std::vector<int> results;

        public:
            static const inline std::string identifier     = "d";
            static const inline auto        type           = node::type::OPERATOR;
            static const inline auto        operands_order = node::operands_order::LEFT_RIGHT;

        public:
            inline explicit dice(const std::string&): node(identifier, type, operands_order)
            {
                random_generator.seed(std::time(nullptr));
            }

            inline int compute() override
            {
                results.clear();
                std::uniform_int_distribution<int> distribution(1, children[1]->compute());

                int result = 0;
                int n      = children[0]->compute();

                for (size_t i = 0; i < abs(n); ++i)
                {
                    results.push_back(distribution(random_generator));
                    result += results.back();
                }

                return result * ((n < 0) ? -1 : 1);
            }

            inline std::string to_string() override
            {
                std::stringstream result;

                result << children[0]->to_string() << "d" << children[1]->to_string();

                if (results.size() != 0)
                {
                    result << " [";

                    for (size_t i = 0; i < results.size(); ++i)
                    {
                        result << results[i];

                        if (results.size() - i > 1)
                        {
                            result << ",";
                        }
                    }

                    result << "]";
                }
                return result.str();
            }
    };
}// namespace gpt::dice_roller

#endif// PARSER_PREBUILT_DICE_ROLLER_DICE_HPP
