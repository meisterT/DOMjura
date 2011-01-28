#include "maindialog.h"
#include "ui_maindialog.h"

#include <QFileDialog>

namespace DJ {
namespace View {

MainDialog::MainDialog(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainDialog) {
	ui->setupUi(this);
}

MainDialog::~MainDialog() {
	delete ui;
}

void MainDialog::setSaveXMLEnabled(bool enabled) {
	this->ui->buttonSaveXMLData->setEnabled(enabled);
}

void MainDialog::setActionsEnabled(bool enabled) {
	this->ui->groupBoxActions->setEnabled(enabled);
}

void MainDialog::setCategories(QList<QString> categories) {
	this->ui->comboBoxCategory->clear();
	this->ui->comboBoxCategory->addItems(categories);
}

void MainDialog::selectParticipantsCategory() {
	for (int i = 0; i < this->ui->comboBoxCategory->count(); i++) {
		if (this->ui->comboBoxCategory->itemText(i) == "Participants") {
			this->ui->comboBoxCategory->setCurrentIndex(i);
			break;
		}
	}
}

QString MainDialog::getSelectedCategory() {
	return this->ui->comboBoxCategory->currentText();
}

void MainDialog::on_buttonBrowseLocal_clicked() {
	QString dir = QFileDialog::getExistingDirectory(this, "Select XML directory",
													ui->lineEditLocalDir->text().isEmpty() ? QDir().homePath() : ui->lineEditLocalDir->text(),
													QFileDialog::ShowDirsOnly);
	if (!dir.isEmpty()) {
		ui->lineEditLocalDir->setText(dir);
		QDir theDir(dir);
		emit dirChanged(theDir);
	}
}

void MainDialog::on_buttonAbout_clicked() {
	emit aboutClicked();
}

void MainDialog::on_comboProtocol_currentIndexChanged(QString text) {
	QString url = text;
	url += ui->lineEditURL->text();
	emit URLChanged(url);
}

void MainDialog::on_lineEditURL_textChanged(QString text) {
	QString url = ui->comboProtocol->currentText();
	url += text;
	emit URLChanged(url);
}

void MainDialog::on_lineEditPassword_textChanged(QString text) {
	emit passwordChanged(text);
}

void MainDialog::on_lineEditUsername_textChanged(QString text) {
	emit usernameChanged(text);
}

void MainDialog::on_buttonLoadData_clicked() {
	emit loadDataClicked();
}

void MainDialog::on_radioDOMjudge_clicked() {
	emit switchedToURL();
}

void MainDialog::on_radioLocalXML_clicked() {
	emit switchedToDir();
}

void MainDialog::on_buttonSaveXMLData_clicked() {
	QString dir = QFileDialog::getExistingDirectory(this, "Select XML save directory", QDir().homePath());
	if (!dir.isEmpty()) {
		emit saveXMLclicked(dir);
	}
}

void MainDialog::on_buttonViewStats_clicked() {
	emit statsClicked();
}

void MainDialog::on_buttonStartResultsPresentation_clicked() {
	emit resultsClicked();
}

void MainDialog::on_buttonSettings_clicked() {
	emit settingsClicked();
}


} // namespace View
} // namespace DJ