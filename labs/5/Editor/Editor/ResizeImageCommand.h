#pragma once

#include "AbstractCommand.h"
#include "IImage.h"

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(std::shared_ptr<IImage> target, int width, int height);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::shared_ptr<IImage> m_target;
	int m_newWidth;
	int m_newHeight;
};