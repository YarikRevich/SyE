#include <vector>
#include <functional>

std::vector<std::function<void()>> _middlewares;

void use(std::function<void()> m)
{
	//Adds func to middlewares

	_middlewares.push_back(m);
}
