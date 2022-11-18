#ifndef LEXER
#define LEXER

#include <array>
#include <concepts>
#include <string>

#include "language_descriptor.hpp"

namespace gst
{
    // clang-format off
    template<class T>
    concept Language_Descriptor = requires
    {
        { T::terminals[0] } -> std::convertible_to<std::string>;
        { T::production_rules[0] } -> std::convertible_to<std::string>;
    };
    // clang-format on

    template<Language_Descriptor Descriptor>
    class lexer
    {
        private:
            static constexpr auto terminals = Descriptor::terminals.size();

            static constexpr auto extract_terminals()
            {
                std::array<std::string_view, terminals> result;

                return result;
            }

        public:
            constexpr lexer()
            {
            }
    };
}// namespace gst

#endif /* LEXER */
