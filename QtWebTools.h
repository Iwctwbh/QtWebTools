#pragma once

#include <QtWidgets/QMainWindow>

#include "ConvertTools.h"
#include "ui_QtWebTools.h"

class QtWebTools final : public QMainWindow
{
	Q_OBJECT

public:
	QtWebTools(QWidget* parent = nullptr);
	~QtWebTools() override;

private:
	Ui::QtWebToolsClass ui{};	

	ConvertTools convertTools{};
};
