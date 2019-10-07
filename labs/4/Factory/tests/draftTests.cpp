#include "../../../../catch2/catch.hpp"
#include "../Factory/PictureDraft.h"
#include "../Factory/Rectangle.h"
#include "../Factory/Triangle.h"
#include "../Factory/Ellipse.h"
#include "../Factory/RegularPolygon.h"

using namespace std;

TEST_CASE("Picture draft tests")
{
	CPictureDraft pictureDraft;

	CHECK(pictureDraft.IsEmpty());
	CHECK(pictureDraft.GetShapesCount() == 0);
	CHECK_THROWS_AS(pictureDraft[0], runtime_error);

	unique_ptr<CShape> rectangle = make_unique<CRectangle>(Point{ 2, 3 }, Point{ 4, 6 });
	const CShape& refRectangle = *rectangle;
	pictureDraft.AddShape(move(rectangle));

	CHECK_FALSE(pictureDraft.IsEmpty());

	unique_ptr<CShape> triangle = make_unique<CTriangle>(Point{ 1, 2 }, Point{ 4, 2 }, Point{ 3, 5 });
	const CShape& refTriangle = *triangle;
	pictureDraft.AddShape(move(triangle));

	unique_ptr<CShape> ellipse = make_unique<CEllipse>(Point{ 5, 6 }, 3, 2);
	const CShape& refEllipse = *ellipse;
	pictureDraft.AddShape(move(ellipse));

	unique_ptr<CShape> regularPolygon = make_unique<CRegularPolygon>(4, Point{ 10, 10 }, 5);
	const CShape& refRegularPolygon = *regularPolygon;
	pictureDraft.AddShape(move(regularPolygon));

	CHECK(pictureDraft.GetShapesCount() == 4);
	CHECK_THROWS_AS(pictureDraft[4], runtime_error);

	CHECK(addressof(pictureDraft[0]) == addressof(refRectangle));
	CHECK(addressof(pictureDraft[1]) == addressof(refTriangle));
	CHECK(addressof(pictureDraft[2]) == addressof(refEllipse));
	CHECK(addressof(pictureDraft[3]) == addressof(refRegularPolygon));
}