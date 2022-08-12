#include "ConvertTools.h"

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
			listParameters = {};
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

auto ConvertTools::getListInputType() const -> QList<QString>
{
	return listInputType;
}

auto ConvertTools::getMapForm() const -> QMap<QString, QString>
{
	return mapForm;
}
