![Image alt](https://github.com/sxaxq/owm/raw/master/images/OpenWeather.png)
<hr>
## Using OWM (OpenWeatherMap) API in C++
To start using the OWM (OpenWeatherMap) API in your C++ application, you can utilize the owm library that provides a convenient way to access weather data.

### Setting up OWM Token
Before making requests to the OpenWeatherMap API, it is necessary to create an instance of the owm::token class and pass your API key to it. The token instance will automatically validate the key.

```c++
owm::token my_token("YOUR_API_KEY");
Obtaining Weather Information
Once your API key is validated, you can use the static function get_weather of the owm::weather class to retrieve weather data for a specific city, along with the required parameters.
```

```c+++
std::vector<owm::request_strings> request_params = {owm::request_strings::weather, 
                                                    owm::request_strings::celcius, 
                                                    owm::request_strings::fahrenheit, 
                                                    owm::request_strings::country};
owm::weather::weather_data data = owm::weather::get_weather("London", my_token, request_params);
```
In the above example, the get_weather function retrieves weather details for the city "London", including the weather condition in string format, temperature in Celsius, temperature in Fahrenheit, and the country in which the city is located.

Feel free to explore the owm library's documentation for additional features and customization options.
