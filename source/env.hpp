//
// Created by alex on 18/01/2021.
//

#ifndef DISCPP_BOT_BOILERPLATE_ENV_HPP
#define DISCPP_BOT_BOILERPLATE_ENV_HPP

#include <cstdlib>
#include <string>

#if defined(_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#endif

namespace Env {
	std::string Get(const std::string& key);
};

#endif //DISCPP_BOT_BOILERPLATE_ENV_HPP
