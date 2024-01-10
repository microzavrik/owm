#ifndef PARAMS_H
#define PARAMS_H

#include <vector>

namespace owm
{
	enum class request_strings
	{
		weather,
		celcius,
		fahrenheit,
		country,
	};

	using params_request = std::vector<request_strings>;
}

#endif