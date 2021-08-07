#pragma once

#include <iostream>
#include <type_traits>
#include "./../exceptions/exceptions.hpp"

#define buffer_assertion(T, A) std::is_same_v<T, A>
