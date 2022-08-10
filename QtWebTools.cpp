#include "QtWebTools.h"

QtWebTools::QtWebTools(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Init
#pragma region Init ComboBox
	// QMap 不支持 [key, value] 遍历 ？
	ui.comboBox->addItems(mapComboBox.keys());
	for (auto&& value : mapComboBox.first())
	{
		ui.comboBox_2->addItem(value);
	}

	QObject::connect(ui.comboBox, &QComboBox::currentIndexChanged, [&]()
	{
		// ReInit ComboBox
		ui.comboBox_2->clear();
		for (auto&& value : mapComboBox.value(ui.comboBox->currentText()))
		{
			ui.comboBox_2->addItem(value);
		}
	});
#pragma endregion

#pragma region Init PushButton
	QObject::connect(ui.pushButton, &QPushButton::clicked, [&]()
	{
		if (ui.comboBox->currentText().compare("SQL") && ui.comboBox_2->currentText().compare("Class"))
		{
			QList<QString> list_str_Text = ui.textEdit->toPlainText().split('|');
			for (auto&& s : list_str_Text)
			{
				s = "public string " + s + "{get; set;} = \"\"";
				ui.textEdit_2->setText(s);
			}

		}
	});
#pragma endregion
}

QtWebTools::~QtWebTools()
= default;
