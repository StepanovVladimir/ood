#include "graphics_lib/Canvas.h"
#include "shape_drawing_lib/Triangle.h"
#include "shape_drawing_lib/Rectangle.h"
#include "shape_drawing_lib/CanvasPainter.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"
#include <string>

using namespace std;
using namespace graphics_lib;
using namespace shape_drawing_lib;
using namespace modern_graphics_lib;

namespace app
{
	void PaintPicture(CCanvasPainter& painter)
	{
		CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
		CRectangle rectangle({ 30, 40 }, 18, 24);

	}

	void PaintPictureOnCanvas()
	{
		CCanvas simpleCanvas;
		CCanvasPainter painter(simpleCanvas);
		PaintPicture(painter);
	}

	void PaintPictureOnModernGraphicsRenderer()
	{
		CModernGraphicsRenderer renderer(cout);

	}
}

using namespace app;

int main()
{
	cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		PaintPictureOnCanvas();
	}
}