#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QToolButton>
#include <QFontDialog>
#include <QColorDialog>
#include <QClipboard>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refresh_title();
    void read_file();
public slots:
    void new_file_action();
    void open_file_action();
    void save_file_action();
    void saveas_file_action();
    void copy_action();
    void cut_action();
    void paste_action();
    void font_select();
    void color_select();
    void not_save_title();
private:
    QMenuBar *menu_bar;
    QToolBar *tool_bar;
    QStatusBar *sta_bar;
    QTextEdit *text_edit;
    bool existflag;
    QString inifilename;
    QString filename;
    QString path;
    QString clip;
};

#endif // MAINWINDOW_H
