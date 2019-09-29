#pragma once

template <typename Condiment, typename ...Args>
auto DecorateWith(const Args&...args)
{
	return [=](auto &&b) {
		return std::make_unique<Condiment>(std::forward<decltype(b)>(b), args...);
	};
}

template <typename Component, typename Decorator>
auto operator<<(Component &&component, const Decorator &decorate)
{
	return decorate(std::forward<Component>(component));
}