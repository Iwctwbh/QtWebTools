#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWebTools.h"

class QtWebTools : public QMainWindow
{
	Q_OBJECT

public:
	QtWebTools(QWidget* parent = nullptr);
	~QtWebTools();

private:
	Ui::QtWebToolsClass ui{};
	QMap<QString, QList<QString>> mapComboBox
	{
		{"Web", {"Jquery", "Class", "Control"}},
		{"Jquery",{"Class","Control"}},
		{"SQL",{"Class", "Control"}}
	};
};
