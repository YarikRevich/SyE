#include "helper.hpp"

#include <vector>
#include <functional>

Middleware::Middleware(std::function<void()> middleware)
{
	this->middleware = middleware;
};

void Middleware::use()
{
	this->middleware();
};

MiddlwareExecutor::MiddlwareExecutor(std::vector<Middleware> middlewares)
{
	for (int i = 0; i < middlewares.size(); i++)
	{
		middlewares[i].use();
	};
};