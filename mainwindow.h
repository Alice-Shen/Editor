#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<Qtwidgets>
#include<QtPrintSupport>
#include <finddialog.h>
#include <replacedialog.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
private slots:
    void createMenus();
    void createActions();
    void newAct();
    void openAct();
    void saveAct();
	void saveAsAct();
    void printAct();
	void printDocument(QPrinter *printer);
	void printPreviewAct();
    void exitAct();
	void undoAct();
	void redoAct();
	void cutAct();
	void copyAct();
	void pasteAct();
    void findAct(QString,bool,bool);
	void boldAct();
	void italicAct();
	void underlineAct();
	void colorAct();
    void aboutAct(); 
	void aboutQtAct();
    void showFindDialog();
    void showReplaceDialog();
    void findReplace(QString,bool);
    void replaceCur(QString,QString);
    void replaceAll(QString,QString,bool);

private:
    //菜单
    bool   find;
    QMenu *file_menu;
    QMenu *edit_menu;
	QMenu *format_menu;
	QMenu *help_menu;
	QMenu *font_menu;
 //   QMenu *about_menu;
	//QMenu *aboutQt_menu;
    //Action响应file_menu
    QAction *new_act;
    QAction *open_act;
    QAction *save_act;
    QAction *save_as_act;
    QAction *print_act;
	QAction *print_preview_act;
    QAction *exit_act;
    //Action响应edit_menu
	QAction *undo_act;
	QAction *redo_act;
	QAction *cut_act;
	QAction *copy_act;
	QAction *paste_act;
    QAction *find_act;
    QAction *replace_act;
	//Action响应format_menu
	QAction *font_act;
	QAction *bold_act;
	//Action响应font_mune
	QAction *italic_act;
	QAction *underline_act;
	QAction *color_act;
    //Action响应help_menu
    QAction *about_act;
	QAction *aboutQt_act;
    //Edit
    QTextEdit *text_edit;

    FindDialog *find_dialog;
    ReplaceDialog *replace_dialog;
    QString cur_file_name;

};

#endif // MAINWINDOW_H
