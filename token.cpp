#include "token.h"

namespace owm
{
    token::token(const std::string& akey) : apiKey(akey)
    {
        if (!CheckValidKey().sucess)
            std::cout << "API key is invalid" << std::endl;
        else
            std::cout << "API key is valid" << std::endl;
    }

    response_status token::CheckValidKey() noexcept
    {
        CURL* curl;
        CURLcode res{};
        std::int64_t httpCode;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        if (curl)
        {
            std::string url = "http://api.openweathermap.org/data/2.5/weather?q=London&appid=" + apiKey;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            if (res == CURLE_OK)
            {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

                if (httpCode < 400)
                {
                    return { true, httpCode };
                }
                else
                {
                    return { false, httpCode };
                }
            }
        }
    }
}