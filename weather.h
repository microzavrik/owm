#include "token.h"
#include "params.h"

#include <nlohmann/json.hpp>

namespace owm
{
	class weather
{
public:
    static std::string get_weather(const std::string& city, const std::string& apiKey,
        owm::params_request requst_stirngs);
private:
    static size_t writecallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};
}