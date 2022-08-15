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
		adapter,
		ajax,
		model
	};

	const QMap<QString, inputType> mapInputType
	{
		{"SQL", sql},
		{"Args", args},
		{"Control", control},
		{"Adapter", adapter},
		{"Ajax", ajax},
		{"Model", model}
	};

	const QMap<QString, QString> mapForm
	{
		{"", ""},
		{"Model", R"(public string $$$$ {get; set;} = "";\n)"},
		{"Args","string $$$$, "},
		{"Adapter","DataBaseHelper.SafeSqlString($$$$),\\n"},
		{"Control", R"(temp = DataBaseHelper.GetValueFromRowByName(SqlResult.Rows[0], "$$$$");\n)"},
		{"Ajax", "$$$$: $(\"#$$$$\").val(),\n"}
	};

	auto initList(const QString&, const inputType) -> int;
	int setForm(const QString&);

	// Convert
	QString getResult(void);

	// Result
	QString getLastResult(void);

private:
	QList<QString> listParameters{};
	QString strForm{};
	QString strResult{};
	QString strLastResult{};
};
