#ifndef LANGUAGE_DESCRIPTOR
#define LANGUAGE_DESCRIPTOR

#include <string_view>
#include <vector>

namespace gst
{
    struct language_descriptor
    {
            std::vector<std::string_view> terminals;
            /*
             * Literal terminals must be specified with Terminal -> regex matching its literals.
             */
            std::vector<std::string_view> production_rules;
    };
}// namespace gst

#endif /* LANGUAGE_DESCRIPTOR */
