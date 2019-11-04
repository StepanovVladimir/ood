#pragma once

namespace graphics_lib
{
	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;

		virtual void MoveTo(int x, int y) = 0;
		virtual void LineTo(int x, int y) = 0;
	};
}