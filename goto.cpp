#include "qmessagebox.h"
#include "goto.h"

GotoDialog::GotoDialog(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    ui.label->setBuddy(ui.lineEdit);
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, this);
    ui.lineEdit->setValidator(validator);
}

GotoDialog::~GotoDialog()
{
}

void GotoDialog::setLineNumber(int currLine, int maxLineCount)
{
    ui.lineEdit->setText(QString::number(currLine));
    ui.lineEdit->selectAll();
    this->maxLineCount = maxLineCount;
}

void GotoDialog::accept()
{
    QString value = ui.lineEdit->text().trimmed();
    if (value.isEmpty())
    {
        this->showMessage(tr("请输入要跳到的行数。"));
        return;
    }
    if (value.toInt() > this->maxLineCount)
    {
        this->showMessage(tr("行数超过了总行数。"));
        return;
    }

    this->gotoLine = value.toInt();
    return QDialog::accept();
}

void GotoDialog::showMessage(QString title)
{
    QMessageBox::warning(this, tr("记事本 - 跳行"), title, tr("确定"));
}