#ifndef TOKEN_H
#define TOKEN_H

#include "include.hpp"

namespace owm
{
    struct response_status
    {
        bool sucess;
        std::int64_t response_code;
    };

    class token
    {
    public:
        token(const std::string& akey);
        response_status CheckValidKey() noexcept;
        std::string GetToken() const { return apiKey; }
    private:
        std::string apiKey;
    };
}

#endif