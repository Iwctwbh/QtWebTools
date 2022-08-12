#include "QtWebTools.h"

QtWebTools::QtWebTools(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Init
#pragma region Init ComboBox
	// QMap 不支持 [key, value] 遍历 ？
	ui.comboBox->addItems(convertTools.getListInputType());
	ui.comboBox_2->addItems(convertTools.getMapForm().keys());

	connect(ui.comboBox_2, &QComboBox::currentIndexChanged, [&]()
	{
		// ReInit TextEdit_3
		ui.textEdit_3->setText(convertTools.getMapForm().value(ui.comboBox_2->currentText()));
	});
#pragma endregion

#pragma region Init PushButton
	connect(ui.pushButton, &QPushButton::clicked, [&]()
	{
		convertTools.initList(ui.textEdit->toPlainText(), ConvertTools::sql);
		convertTools.setForm(ui.textEdit_3->toPlainText());
		ui.textEdit_2->setText(convertTools.toClass());
	});
#pragma endregion
}

QtWebTools::~QtWebTools()
= default;
