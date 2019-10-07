#include "MockShapeFactory.h"
#include "MockShape.h"

using namespace std;

unique_ptr<CShape> CMockShapeFactory::CreateShape(const std::string& description) const
{
	return make_unique<CMockShape>(description);
}