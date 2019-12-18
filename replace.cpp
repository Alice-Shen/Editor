#include "qmessagebox.h"
#include "qtextedit.h"
#include "qtextdocument.h"
#include "replace.h"

ReplaceDialog::ReplaceDialog(QWidget *parent, QTextEdit *textEdit) :
    QDialog(parent),
    textEdit(textEdit)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    initDialog();
}

ReplaceDialog::~ReplaceDialog()
{
}

void ReplaceDialog::initDialog()
{
    ui.label->setBuddy(ui.lineEdit);
    ui.lblReplace->setBuddy(ui.replaceEdit);
    ui.searchButton->setEnabled(false);
    ui.replaceButton->setEnabled(false);
    ui.replaceAllButton->setEnabled(false);
    QObject::connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(search()));
    QObject::connect(ui.replaceButton, SIGNAL(clicked()), this, SLOT(replace()));
    QObject::connect(ui.replaceAllButton, SIGNAL(clicked()), this, SLOT(replaceAll()));
    QObject::connect(ui.lineEdit, &QLineEdit::textChanged, [=]()
    {
        ui.searchButton->setEnabled(ui.lineEdit->text() != "");
        ui.replaceButton->setEnabled(ui.lineEdit->text() != "");
        ui.replaceAllButton->setEnabled(ui.lineEdit->text() != "");
    });
}

void ReplaceDialog::activateWindow()
{
    QDialog::activateWindow();

    ui.lineEdit->setText(textEdit->textCursor().selectedText());
    ui.lineEdit->selectAll();
}

bool ReplaceDialog::search(bool showWarn)
{
    QString text = ui.lineEdit->text();
    if (text.isEmpty())
        return false;

    QTextDocument::FindFlags findFlags;
    if (ui.cbCaseSensitive->isChecked())
        findFlags = QTextDocument::FindCaseSensitively;
    bool found = textEdit->find(text, findFlags);

    if (!found && showWarn)
        QMessageBox::information(this, tr("记事本"), tr("找不到\"%1\"").arg(text), QMessageBox::Ok);
    return found;
}

void ReplaceDialog::replace()
{
    bool found = search();
    if (!found)
        return;

    QTextCursor textCursor = textEdit->textCursor();
    QString replaceText = ui.replaceEdit->text();
    textCursor.insertText(replaceText);

    //寻找下一个
    search();
}

void ReplaceDialog::replaceAll()
{
    QString text = ui.lineEdit->text();
    if (text.isEmpty())
        return;

    QTextDocument::FindFlags findFlags;
    if (ui.cbCaseSensitive->isChecked())
        findFlags = QTextDocument::FindCaseSensitively;
    QString replaceText = ui.replaceEdit->text();
    while (textEdit->find(text, findFlags))
    {
        QTextCursor textCursor = textEdit->textCursor();
        textCursor.insertText(replaceText);
    }
    //往回找
    findFlags |= QTextDocument::FindBackward;
    while (textEdit->find(text, findFlags))
    {
        QTextCursor textCursor = textEdit->textCursor();
        textCursor.insertText(replaceText);
    }
}