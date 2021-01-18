//
// Created by alex on 18/01/2021.
//

#include "env.hpp"

std::string Env::Get(const std::string& key) {
	return std::string(getenv(key.c_str()));
}