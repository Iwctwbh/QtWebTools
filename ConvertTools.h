#pragma once

#include <qmap.h>

#include "ConvertTools.h"
#include "QObject"
#include "QThread"

class ConvertTools final : QObject
{
public:
	ConvertTools();
	~ConvertTools() override;

	// Const Value
	enum inputType
	{
		sql,
		args,
		control,
		adapter
	};

	const QMap<QString, inputType> mapInputType
	{
		{"SQL", sql},
		{"Args", args},
		{"Control", control},
		{"Adapter", adapter}
	};

	const QMap<QString, QString> mapForm
	{
		{"", ""},
		{"Class", R"(public string $$$$ {get; set;} = "";\n)"},
		{"Args","string $$$$, "},
		{"Adapter","DataBaseHelper.SafeSqlString($$$$),\\n"},
		{"Control", R"(temp = DataBaseHelper.GetValueFromRowByName(SqlResult.Rows[0], "$$$$");\n)"}
	};

	auto initList(const QString&, const inputType) -> int;
	int setForm(const QString&);

	// Convert
	QString toClass(void);

	// Result
	QString getLastResult(void);
	
private:
	QList<QString> listParameters{};
	QString strForm{};
	QString strResult{};
	QString strLastResult{};
};
