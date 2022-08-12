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
	enum inputType
	{
		sql,
		args,
		control,
		adapter
	};
	auto initList(const QString&, const inputType) -> int;
	int setForm(const QString&);

	// Convert
	QString toClass(void);

	// Result
	QString getLastResult(void);

	// Get Const
	auto getListInputType() const ->QList<QString>;
	auto getMapForm() const ->QMap<QString, QString>;
private:
	QList<QString> listParameters{};
	QString strForm{};
	QString strResult{};
	QString strLastResult{};

	const QList<QString> listInputType
	{
		"SQL","Class"
	};

	const QMap<QString, QString> mapForm
	{
		{"", ""},
		{"Class", R"(public string $$$$ {get; set;} = "";\n)"},
		{"Args","string $$$$, "},
		{"Adapter","DataBaseHelper.SafeSqlString($$$$),\\n"},
		{"Control", R"(temp = DataBaseHelper.GetValueFromRowByName(SqlResult.Rows[0], "$$$$");\n)"}
	};
};
