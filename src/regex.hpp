#ifndef REGEX
#define REGEX

#include <string>

namespace gst::regex
{
    constexpr bool match(const std::string& regex, std::string_view string)
    {
        return true;
    }
}// namespace gst::regex

#endif /* REGEX */
