#include "pch.h"
#include "Cappuccino.h"
#include "Latte.h"
#include "BlackTea.h"
#include "FruitTea.h"
#include "GreenTea.h"
#include "HerbalTea.h"
#include "Milkshake.h"
#include "ChocolateCrumbs.h"
#include "Cinnamon.h"
#include "CoconutFlakes.h"
#include "IceCubes.h"
#include "Lemon.h"
#include "Syrup.h"
#include <iostream>
#include <functional>

using namespace std;

template <typename Condiment, typename ...Args>
auto DecorateWith(const Args&...args)
{
	return [=](auto &&b) {
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

template <typename Component, typename Decorator>
auto operator<<(Component &&component, const Decorator &decorate)
{
	return decorate(forward<Component>(component));
}

int main()
{
	unique_ptr<IBeverage> tea =
		make_unique<CBlackTea>()
		<< DecorateWith<CLemon>(2)
		<< DecorateWith<CIceCubes>(3, CIceCubes::Type::Water);
	cout << tea->GetDescription() << " costs " << tea->GetCost() << endl;

	unique_ptr<IBeverage> latte =
		make_unique<CLatte>(CLatte::Portion::Double)
		<< DecorateWith<CCinnamon>()
		<< DecorateWith<CLemon>(2)
		<< DecorateWith<CIceCubes>(2, CIceCubes::Type::Dry)
		<< DecorateWith<CChocolateCrumbs>(2);
	cout << latte->GetDescription() << " costs " << latte->GetCost() << endl;

	unique_ptr<IBeverage> milkshake =
		make_unique<CMilkshake>(CMilkshake::Portion::Medium)
		<< DecorateWith<CSyrup>(CSyrup::Type::Maple)
		<< DecorateWith<CCoconutFlakes>(8);
	cout << milkshake->GetDescription() << " costs " << milkshake->GetCost() << endl;
}