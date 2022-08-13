#include "ConvertTools.h"

#include <qregularexpression.h>

ConvertTools::ConvertTools()
= default;

ConvertTools::~ConvertTools()
= default;

int ConvertTools::initList(const QString& argString, const inputType enumType)
{
	switch (enumType)
	{
		case sql:
		{
			listParameters = argString.simplified().split('|');
			break;
		}
		case args:
		{
			listParameters = argString.split(',');
			for (auto&& s : listParameters)
			{
				s = s.trimmed().split(' ').last();
			}
			break;
		}
		case control:
		{
			break;
		}
		case adapter:
		{
			break;
		}
		default:
		{
			break;
		}
	}
	return 0;
}

auto ConvertTools::setForm(const QString& argFormString) -> int
{
	strForm = argFormString;
	return 0;
}

QString ConvertTools::toClass()
{
	strResult.clear();
	for (auto&& s : listParameters)
	{
		QString sTemp = strForm;
		strResult.append(sTemp.replace("$$$$", s).replace(R"(\n)", "\n"));
	}
	strLastResult = strResult;
	return strResult;
}

QString ConvertTools::getLastResult(void)
{
	return strLastResult;
}
