#include "weather.h"
#include "params.h";

int main()
{
    owm::token t("bd5e378503939ddaee76f12ad7a97608");
    owm::params_request data;
    data.push_back(owm::request_strings::weather);
    owm::weather::get_weather("Kakhovka", t.GetToken(), data);
}