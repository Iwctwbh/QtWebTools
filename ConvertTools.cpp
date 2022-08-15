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
		case (sql):
		{
			listParameters = argString.simplified().split('|');
			break;
		}
		case (args):
		{
			listParameters = argString.split(',');
			for (auto&& s : listParameters)
			{
				s = s.trimmed().split(' ').last();
			}
			break;
		}
		case (control):
		{
			listParameters = argString.simplified().split(';');
			QRegularExpression regExp{ "DataBaseHelper\\..*?\\(.*?,.*?\\\"(.*?)\\\"\\)" };
			for (auto&& s : listParameters)
			{
				QRegularExpressionMatch regMatch{ regExp.match(s) };
				s = regMatch.captured(1);
			}
			break;
		}
		case (adapter):
		{
			listParameters = argString.simplified().split(',');
			QRegularExpression regExp{ "SafeSqlString\\((.*?)\\)" };
			for (auto&& s : listParameters)
			{
				QRegularExpressionMatch regMatch{ regExp.match(s) };
				s = regMatch.captured(1);
			}
			break;
		}
		case (ajax):
		{
			listParameters = argString.simplified().split(',');
			for (auto&& s : listParameters)
			{
				s = s.split(':').first();
			}
			break;
		}
		case (model):
		{
			listParameters.clear();
			QRegularExpression regExp{ "public (string|int|bool) (.*?) " };
			for (const QRegularExpressionMatch& match : regExp.globalMatch(argString.simplified()))
			{
				listParameters.emplace_back(match.captured(2));
			}
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

QString ConvertTools::getResult()
{
	strResult.clear();
	for (auto&& s : listParameters)
	{
		QString sTemp = strForm;
		strResult.append(sTemp.replace("$$$$", s.trimmed()).replace(R"(\n)", "\n"));
	}
	strLastResult = strResult;
	return strResult;
}

QString ConvertTools::getLastResult(void)
{
	return strLastResult;
}
