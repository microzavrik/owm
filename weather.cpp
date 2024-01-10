#include "weather.h"

#include <algorithm>

namespace owm
{
    std::string weather::get_weather(const std::string& city, const std::string& apiKey, 
        owm::params_request get_info_param)
    {
        std::setlocale(LC_ALL, "rus");
        CURL* curl;
        CURLcode res;
        std::string response_string;
        std::string result_string;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        if (curl) {
            std::string url = "http://api.openweathermap.org/data/2.5/weather?q=London&appid=" + apiKey;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

            res = curl_easy_perform(curl);

            if (res == CURLE_OK) {
                nlohmann::json j = nlohmann::json::parse(response_string);

                for (size_t i = 0; i < get_info_param.size(); i++)
                {
                    if (std::find(get_info_param.begin(), get_info_param.end(), owm::request_strings::weather) !=
                        std::end(get_info_param))
                    {
                        if (j.find("main") != j.end() && j["main"].find("temp") != j["main"].end()) 
                        {
                            double temp_kelvin = j["main"]["temp"];
                            double temp_celsius = temp_kelvin - 273.15;
                            double d = std::round(temp_celsius);
                            result_string += "Current temp in " + city + ": " + std::to_string(d) + "°C\n";
                            std::cout << result_string << std::endl;
                        }

                    }
                }
            }
            else
            {
                std::cerr << "Не удалось выполнить запрос: " << curl_easy_strerror(res) << std::endl;
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();

        return result_string;
    }
}