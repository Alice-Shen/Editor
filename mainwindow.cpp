#include "mainwindow.h"
//#include<QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Text Editor"));
	text_edit = new QTextEdit;
    this->setCentralWidget(text_edit);
    resize(900,500);
    cur_file_name = tr("");
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
   if(file_menu){
       delete file_menu;
   }
   if(edit_menu){
       delete edit_menu;
   }
   if(format_menu){
	   delete format_menu;
   }
   if(help_menu){
	   delete help_menu;
   }
   if(new_act){
       delete new_act;
   }
   if(open_act){
       delete open_act;
   }
   if(save_act){
       delete save_act;
   }
   if(save_as_act){
       delete save_as_act;
   }
   if(print_act){
       delete print_act;
   }
   if(print_preview_act){
       delete print_preview_act;
   }
   if(exit_act){
       delete exit_act;
   }
   if(undo_act){
       delete undo_act;
   }
   if(redo_act){
       delete redo_act;
   }
   if(cut_act){
       delete cut_act;
   }
   if(copy_act){
       delete copy_act;
   }
   if(paste_act){
       delete paste_act;
   }
   if(find_act){
       delete find_act;
   }
   if(replace_act){
       delete replace_act;
   }
   if(bold_act){
	   delete bold_act;
   }
   if(italic_act){
	   delete italic_act;
   }
   if(underline_act){
	   delete underline_act;
   }
   if(color_act){
       delete color_act;
   }
   if(about_act){
       delete about_act;
   }
   if(aboutQt_act){
       delete aboutQt_act;
   }
   if(text_edit){
       delete text_edit;
   }
   if(find_dialog){
       delete find_dialog;
   }
   if(replace_dialog){
       delete replace_dialog;
   }
}

void MainWindow::createMenus()
{
    file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->setStyleSheet("color:blue");
    file_menu->addAction(new_act);
    file_menu->addAction(open_act);
    file_menu->addAction(save_act);
    file_menu->addAction(save_as_act);
    file_menu->addAction(print_act);
	file_menu->addAction(print_preview_act);
	file_menu->addAction(exit_act);
    file_menu->addSeparator();
    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->setStyleSheet("color:blue");
	edit_menu->addAction(undo_act);
	edit_menu->addAction(redo_act);
	edit_menu->addAction(cut_act);
	edit_menu->addAction(copy_act);
	edit_menu->addAction(paste_act);
    edit_menu->addAction(find_act);
    edit_menu->addAction(replace_act);
	format_menu = menuBar()->addMenu(tr("&Format"));
	format_menu->setStyleSheet("color:blue");
	font_menu = format_menu->addMenu(tr("&Font"));
	format_menu->addAction(color_act);
	font_menu->addAction(bold_act);
	font_menu->addAction(italic_act);
	font_menu->addAction(underline_act);
    help_menu = menuBar()->addMenu(tr("&Help"));
    help_menu->setStyleSheet("color:blue");
    help_menu->addAction(about_act);
	help_menu->addAction(aboutQt_act);
    QToolBar *tool_bar = addToolBar(tr("file"));
    tool_bar->addAction(new_act);
    tool_bar->addAction(open_act);
    tool_bar->addAction(save_act);
    tool_bar->addAction(print_act);
	tool_bar->addSeparator();
	tool_bar->addAction(undo_act);
	tool_bar->addAction(redo_act);
	tool_bar->addAction(cut_act);
	tool_bar->addAction(copy_act);
	tool_bar->addAction(paste_act);
    //tool_bar->addAction(find_act);
    //tool_bar->addAction(replace_act);
	tool_bar->addSeparator();
	tool_bar->addAction(bold_act);
	tool_bar->addAction(italic_act);
	tool_bar->addAction(underline_act);
	tool_bar->addAction(color_act);
}

void MainWindow::createActions()
{
    find = false;
    find_dialog = new FindDialog(this);
    replace_dialog = new ReplaceDialog(this);
    //Action响应file_menu
    new_act = new QAction(QIcon(".//icons/new"),tr("&New"),this);
    new_act->setShortcut(QKeySequence::New);

    open_act = new QAction(QIcon(".//icons/open"),tr("&Open"),this);
    open_act->setShortcut(QKeySequence::Open);

    save_act = new QAction(QIcon(".//icons/save"),tr("&Save"),this);
    save_act->setShortcut(QKeySequence::Save);

    save_as_act = new QAction(tr("Save As"),this);
	save_as_act->setShortcut(QKeySequence::SaveAs);

    print_act = new QAction(QIcon(".//icons/print"),tr("&Print"),this);
    print_act->setShortcut(QKeySequence::Print);

	print_preview_act = new QAction(QIcon(".//icons/printPreview"),tr("&Print Preview"),this);

    exit_act = new QAction(QIcon(".//icons/exit"),tr("&Exit"),this);
    exit_act->setShortcut(QKeySequence::Quit);

	//Action响应edit_menu
	undo_act = new QAction(QIcon(".//icons/undo"),tr("&Undo"),this);
	undo_act->setShortcut(QKeySequence::Undo);

	redo_act = new QAction(QIcon(".//icons/redo"),tr("&Redo"),this);
	redo_act->setShortcut(QKeySequence::Redo);

	cut_act = new QAction(QIcon(".//icons/cut"),tr("&Cut"),this);
	cut_act->setShortcut(QKeySequence::Cut);

	copy_act = new QAction(QIcon(".//icons/copy"),tr("&Copy"),this);
	copy_act->setShortcut(QKeySequence::Copy);

	paste_act = new QAction(QIcon(".//icons/paste"),tr("&Paste"),this);
	paste_act->setShortcut(QKeySequence::Paste);

    find_act = new QAction(tr("&Find"),this);
    find_act->setShortcut(QKeySequence::Find);

    replace_act = new QAction(tr("&Replace"),this);
    replace_act->setShortcut(QKeySequence::Replace);

	//Action响应font_menu
	bold_act = new QAction(QIcon(".//icons/bold"),tr("Bold"),this);
	italic_act = new QAction(QIcon(".//icons/italic"),tr("Italic"),this);
	underline_act = new QAction(QIcon(".//icons/underline"),tr("Underline"),this);

	//Action响应format_menu
	color_act = new QAction(QIcon(".//icons/color"),tr("Color"),this);

	//Action响应help_menu
    about_act = new QAction(QIcon(".//icons/about"),tr("About"),this);
	aboutQt_act = new QAction(QIcon(".//icons/aboutQt"),tr("About Qt"),this);

    connect(new_act,SIGNAL(triggered()),this,SLOT(newAct()));
    connect(open_act,SIGNAL(triggered()),this,SLOT(openAct()));
    connect(save_act,SIGNAL(triggered()),this,SLOT(saveAct()));
	connect(save_as_act,SIGNAL(triggered()),this,SLOT(saveAsAct()));
    connect(print_act,SIGNAL(triggered()),this,SLOT(printAct()));
	connect(print_preview_act,SIGNAL(triggered()),this,SLOT(printPreviewAct()));
    connect(exit_act,SIGNAL(triggered()),this,SLOT(exitAct()));
	connect(undo_act,SIGNAL(triggered()),this,SLOT(undoAct()));
	connect(redo_act,SIGNAL(triggered()),this,SLOT(redoAct()));
	connect(cut_act,SIGNAL(triggered()),this,SLOT(cutAct()));
	connect(copy_act,SIGNAL(triggered()),this,SLOT(copyAct()));
	connect(paste_act,SIGNAL(triggered()),this,SLOT(pasteAct()));
    connect(find_act,SIGNAL(triggered()),this,SLOT(showFindDialog()));
    connect(replace_act,SIGNAL(triggered()),this,SLOT(showReplaceDialog()));
	connect(bold_act,SIGNAL(triggered()),this,SLOT(boldAct()));
	connect(italic_act,SIGNAL(triggered()),this,SLOT(italicAct()));
	connect(underline_act,SIGNAL(triggered()),this,SLOT(underlineAct()));
	connect(color_act,SIGNAL(triggered()),this,SLOT(colorAct()));
    connect(about_act,SIGNAL(triggered()),this,SLOT(aboutAct()));
	connect(aboutQt_act,SIGNAL(triggered()),this,SLOT(aboutQtAct()));

    connect(find_dialog,SIGNAL(findTextDataButtonClickedSignal(QString,bool,bool)),this,SLOT(findAct(QString,bool,bool)));
    connect(replace_dialog,SIGNAL(findReplaceStr(QString,bool)),this,SLOT(findReplace(QString,bool)));
    connect(replace_dialog,SIGNAL(replaceCurOneStr(QString,QString)),this,SLOT(replaceCur(QString,QString)));
    connect(replace_dialog,SIGNAL(replaceAllStr(QString,QString,bool)),this,SLOT(replaceAll(QString,QString,bool)));
}

void MainWindow::newAct()
{
    if (text_edit->document()->isModified())
    {
        QMessageBox::StandardButton button = QMessageBox::information(this,
                                          "The text is not saved.", "Do you want to save?",QMessageBox::Save |
                                           QMessageBox::Discard | QMessageBox::Cancel);
        switch(button)
        {
            case QMessageBox::Save:{
                saveAct();
				cur_file_name = "";
				break;
                if (text_edit->document()->isModified()){
                    return;
                }
            }
            case QMessageBox::Cancel:{
                return;
            }
            case QMessageBox::Discard:{
				cur_file_name = "";
                break;
            }
        }
    }
    text_edit->clear();
}

//打开文件
void MainWindow::openAct()
{
    QString file_name = QFileDialog::getOpenFileName(this,tr("Open File"),QString(),
                          tr("HTML document (*.htm *.html);;all files(*.*)"));
    cur_file_name = file_name;
    if(!file_name.isEmpty()){
       QFile file(file_name);
       if(!file.open(QIODevice::ReadOnly)){
          QMessageBox::critical(this,tr("Error!"),tr("Cannot open the file."));
          return;
       }
       QTextStream ins(&file);
       text_edit->setText(ins.readAll());
       file.close();
    }
}

//保存文件
void MainWindow::saveAct()
{
//	cur_file_name = QFileDialog::getSaveFileName();
    if(cur_file_name.isEmpty()){
        QString file_name = QFileDialog::getSaveFileName(this,tr("Save File"),QString(),
                               tr("HTML document (*.htm *.html);;all files(*.*)"));
		cur_file_name = file_name;
        if(!file_name.isEmpty()){
            QFile file(file_name);
            if(!file.open(QIODevice::WriteOnly)){
                QMessageBox::critical(this,tr("Error！"),tr("Cannot open the file."));
                return;
            }
            QTextStream outs(&file);
            outs<<text_edit->toPlainText();
            outs.flush();
            file.close();
        }
    }
    else{
        QFile file(cur_file_name);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this,tr("Error!"),tr("Cannot open the file"));
            return;
        }
        QTextStream outs(&file);
        outs<<text_edit->toPlainText();
        outs.flush();
        file.close();
    }
}

void MainWindow::saveAsAct()
{
    QString file_name = QFileDialog::getSaveFileName(this,tr("Save File"),QString(),
                           tr("HTML document (*.htm *.html);;all files(*.*)"));
    if(!file_name.isEmpty()){
        QFile file(file_name);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this,tr("Error!"),tr("Cannot open the file."));
            return;
        }
        QTextStream outs(&file);
        outs<<text_edit->toPlainText();
        outs.flush();
        file.close();
    }

}

void MainWindow::printAct()
{
    QPrinter printer;
    QString printer_name = printer.printerName();
       if( printer_name.size() == 0){
           return;
       }
       QPrintDialog dlg(&printer, this);
       if (text_edit->textCursor().hasSelection()){
           dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
       }
       if(dlg.exec() == QDialog::Accepted){
           text_edit->print(&printer);
       }
}

//打印预览
void MainWindow::printDocument(QPrinter *printer)  
{  
    QPainter painter;  
    painter.begin(printer);  
  
    QString family("Arial");  
    QString style("Normal");  
  
    QFont font(family, 32, 50, false);  
    font.setStyleName(style);  
    font = QFont(font, painter.device());  
  
    QFontMetricsF fontMetrics(font);  
    QRectF rect = fontMetrics.boundingRect(QString("%1 %2").arg(family).arg(style));  
     
    qreal xScale = printer->pageRect().width() / rect.width();  
    qreal yScale = printer->pageRect().height() / rect.height();  
    double scale = qMin(xScale, yScale);  
    
    painter.save();     
    painter.scale(scale, scale);  
    
	const QString str = text_edit->toPlainText();
	painter.drawText(50,100,str); //预览显示 
    painter.restore();   
    painter.end();  
}  

void MainWindow::printPreviewAct()  
{  
    QPrinter printer(QPrinter::HighResolution);  
    QPrintPreviewDialog preview(&printer, this);  
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),  this, SLOT(printDocument(QPrinter*)));  
    preview.exec();  
} 


void MainWindow::undoAct()
{
	text_edit->undo();
}

void MainWindow::redoAct()
{
	text_edit->redo();
}

void MainWindow::cutAct() 
{ 
	text_edit->cut(); 
} 

void MainWindow::copyAct()
{ 
	text_edit->copy(); 
} 

void MainWindow::pasteAct() 
{ 
	text_edit->paste(); 
}

void MainWindow::findReplace(QString find_str, bool flg)
{
    bool find_flag;
    if(flg){
        find_flag = text_edit->find(find_str,QTextDocument::FindCaseSensitively);
    }
    else{
        find_flag = text_edit->find(find_str);
    }
    if(!find_flag){
        QMessageBox::information(this,tr("Relute"),tr("No find result."),QMessageBox::Yes);
    }
    else{
        find = true;
    }
}

void MainWindow::replaceCur(QString find_str, QString replace_str)
{
    if(find){
        QTextCursor text_cursor = text_edit->textCursor();
        text_cursor.insertText(replace_str);
    }
    else{
        QMessageBox::information(this,tr("Result"),tr("No information to replace.")+find_str,QMessageBox::Yes);
    }
    find = false;
}

void MainWindow::replaceAll(QString find_str, QString replace_str,bool flg)
{
    if(!flg){
        bool haf = text_edit->find(find_str);
        if(haf){
            QTextCursor text_cursor = text_edit->textCursor();
            text_cursor.insertText(replace_str);
            while(text_edit->find(find_str)){
                text_cursor = text_edit->textCursor();
                text_cursor.insertText(replace_str);
            }
            while(text_edit->find(find_str,QTextDocument::FindBackward)){
                text_cursor = text_edit->textCursor();
                text_cursor.insertText(replace_str);
            }
        }
        else
             QMessageBox::information(this,tr("Result"),tr("No information to replace.")+find_str,QMessageBox::Yes);
    }
    else{
        bool haf = text_edit->find(find_str,QTextDocument::FindCaseSensitively);
        if(haf){
            QTextCursor text_cursor = text_edit->textCursor();
            text_cursor.insertText(replace_str);
            while(text_edit->find(find_str,QTextDocument::FindCaseSensitively)){
                text_cursor = text_edit->textCursor();
                text_cursor.insertText(replace_str);
            }
            while(text_edit->find(find_str,QTextDocument::FindCaseSensitively|QTextDocument::FindBackward)){
                text_cursor = text_edit->textCursor();
                text_cursor.insertText(replace_str);
            }
        }
        else
            QMessageBox::information(this,tr("Result."),tr("No information to replace.")+find_str,QMessageBox::Yes);
    }
}


void MainWindow::findAct(QString str,bool ignore,bool choose)
{
    QString text = str;
    bool find_flag;
    if(!text.isEmpty()){
        if(choose){
            if(ignore)
              find_flag = text_edit->find(text,QTextDocument::FindCaseSensitively);
            else
                find_flag = text_edit->find(text);
        }
        else{
            if(ignore)
                find_flag = text_edit->find(text,QTextDocument::FindBackward|QTextDocument::FindCaseSensitively);
            else
                find_flag = text_edit->find(text,QTextDocument::FindBackward);
        }
        if(!find_flag)
            QMessageBox::information(this,tr("Result"),tr("No find result."),QMessageBox::Yes);
    }
}

void MainWindow::boldAct(){
	QTextCharFormat fmt; 
	fmt.setFontWeight(bold_act->isChecked() ? QFont::Bold : QFont::Normal );
	text_edit->mergeCurrentCharFormat(fmt);
	bold_act->setCheckable(true);
}

void MainWindow::italicAct(){
	QTextCharFormat fmt; 
	fmt.setFontItalic(italic_act->isChecked());
	text_edit->mergeCurrentCharFormat(fmt);
	italic_act->setCheckable(true);
}

void MainWindow::underlineAct(){
	QTextCharFormat fmt; 
	fmt.setFontUnderline(underline_act->isChecked());
	text_edit->mergeCurrentCharFormat(fmt);
	underline_act->setCheckable(true);
}

void MainWindow::colorAct(){
	QColor color = QColorDialog::getColor(); 
	QTextCharFormat fmt; 
	fmt.setForeground(color);
	text_edit->mergeCurrentCharFormat(fmt);
	color_act->setCheckable(true);
}

void MainWindow::aboutAct()
{
	QMessageBox::about(this, tr("About"), tr("This is a simple text editor. Powered by Shen Jianan."));
}

void MainWindow::aboutQtAct()
{
	connect(aboutQt_act, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::showFindDialog()
{
    find_dialog->show();
}

void MainWindow::showReplaceDialog()
{
    replace_dialog->show();
}

void MainWindow::exitAct()
{
    this->close();
}