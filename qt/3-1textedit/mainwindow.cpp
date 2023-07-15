#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->inifilename="untitile";
    this->existflag=false;
    this->filename=inifilename;
    this->setWindowTitle("untitle");

    this->menu_bar=new QMenuBar(this);
    this->setMenuBar(this->menu_bar);
    this->tool_bar=new QToolBar(this);
    this->addToolBar(this->tool_bar);
    this->sta_bar=new QStatusBar(this);
    this->setStatusBar(this->sta_bar);
    this->text_edit=new QTextEdit;
    this->setCentralWidget(this->text_edit);

    QMenu *file_menu=new QMenu("file",this);
    this->menu_bar->addMenu(file_menu);

    QMenu *edit_menu=new QMenu("edit",this);
    this->menu_bar->addMenu(edit_menu);

    QMenu *format_menu=new QMenu("format",this);
    this->menu_bar->addMenu(format_menu);
#if 0
    QMenu *view_menu=new QMenu("view",this);
    this->menu_bar->addMenu(view_menu);
#endif
    QAction *f_new=new QAction(this);
    f_new->setText("new file");
    f_new->setShortcut(QKeySequence::New);
    file_menu->addAction(f_new);

    QAction *f_open=new QAction(this);
    f_open->setText("open exist file");
    f_open->setShortcut(QKeySequence::Open);
    file_menu->addAction(f_open);

    QAction *f_save=new QAction(this);
    f_save->setText("save");
    f_save->setShortcut(QKeySequence::Save);
    //f_save->setIcon(QIcon(":pathname"))
    file_menu->addAction(f_save);

    QAction *f_saveas=new QAction(this);
    f_saveas->setText("save as");
    f_saveas->setShortcut(QKeySequence::SaveAs);
    file_menu->addAction(f_saveas);

    QAction *e_copy=new QAction(this);
    e_copy->setText("copy");
    e_copy->setShortcut(QKeySequence::Copy);
    edit_menu->addAction(e_copy);

    QAction *e_paste=new QAction(this);
    e_paste->setText("paste");
    e_paste->setShortcut(QKeySequence::Paste);
    edit_menu->addAction(e_paste);

    QAction *e_cut=new QAction(this);
    e_cut->setText("cut");
    e_cut->setShortcut(QKeySequence::Cut);
    edit_menu->addAction(e_cut);

    QAction *fm_font=new QAction(this);
    fm_font->setText("font");
    format_menu->addAction(fm_font);

    QAction *fm_color=new QAction(this);
    fm_color->setText("color");
    format_menu->addAction(fm_color);
#if 0
    QAction *e_cancel=new QAction(this);
    e_cancel->setText("cancel");
    e_cancel->setShortcut(QKeySequence::Cancel);
    edit_menu->addAction(e_cancel);

    QAction *e_all=new QAction(this);
    e_all->setText("all");
    e_all->setShortcut(QKeySequence::Cancel);
    edit_menu->addAction(e_all);

    QAction *zoom_in=new QAction(this);
    zoom_in->setText("zoom in");
    zoom_in->setShortcut(QKeySequence::ZoomIn);
    view_menu->addAction(zoom_in);

    QAction *zoom_out=new QAction(this);
    zoom_out->setText("zoom out");
    zoom_out->setShortcut(QKeySequence::ZoomOut);
    view_menu->addAction(zoom_out);
#endif
    f_new->setStatusTip("new file");
    f_open->setStatusTip("open exist file");

    connect(f_new,SIGNAL(triggered()),this,SLOT(new_file_action()));
    connect(f_open,SIGNAL(triggered()),this,SLOT(open_file_action()));
    connect(f_save,SIGNAL(triggered()),this,SLOT(save_file_action()));
    connect(f_saveas,SIGNAL(triggered()),this,SLOT(saveas_file_action()));
    connect(e_copy,SIGNAL(triggered()),this,SLOT(copy_action()));
    connect(e_cut,SIGNAL(triggered()),this,SLOT(cut_action()));
    connect(e_paste,SIGNAL(triggered()),this,SLOT(paste_action()));
    connect(fm_font,SIGNAL(triggered()),this,SLOT(font_select()));
    connect(fm_color,SIGNAL(triggered()),this,SLOT(color_select()));
    connect(this->text_edit,&QTextEdit::textChanged,this,&MainWindow::not_save_title);

    this->tool_bar->addAction(f_new);
    this->tool_bar->addAction(f_open);

    QToolButton *font_btn=new QToolButton(this);
    font_btn->setText("font");
    this->tool_bar->addWidget(font_btn);

    QToolButton *color_btn=new QToolButton(this);
    color_btn->setText("color");
    this->tool_bar->addWidget(color_btn);

    connect(font_btn,&QToolButton::clicked,this,&MainWindow::font_select);
    connect(color_btn,&QToolButton::clicked,this,&MainWindow::color_select);
}

MainWindow::~MainWindow()
{

}

void MainWindow::new_file_action(){
    clip.clear();
    bool res=this->text_edit->document()->isModified();
    if(res==false){
        this->refresh_title();
    }
    else{
       int ret=QMessageBox::question(this,"notepad","save this modifcation?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
       if(ret==QMessageBox::Yes){
           if(existflag==true){
               this->save_file_action();
               this->refresh_title();
           }
           else{
               this->saveas_file_action();
               this->refresh_title();
           }
           existflag=false;
       }
       else if(ret==QMessageBox::No){
           this->refresh_title();
           existflag=false;
       }
       else if(ret==QMessageBox::Cancel){

       }
    }
}

void MainWindow::open_file_action(){
    clip.clear();
    bool res=this->text_edit->document()->isModified();
    if(res==false){
        this->read_file();
    }
    else{
       int ret=QMessageBox::question(this,"notepad","save this modifcation?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
       if(ret==QMessageBox::Yes){
           if(existflag==true){
               save_file_action();
           }
           else{
               saveas_file_action();
           }
           this->read_file();
       }
       else if(ret==QMessageBox::No){
           this->read_file();
       }
       else if(ret==QMessageBox::Cancel){

       }
    }
}

void MainWindow::save_file_action(){
    if(this->existflag==false){
        this->saveas_file_action();
    }
    else{
        QFile file(path);
        bool res=file.open(QFile::WriteOnly);
        if(res==true){
            QString content=this->text_edit->toPlainText();
            file.write((content.toStdString()).data());
            file.close();
            this->text_edit->document()->setModified(false);
        }
        this->setWindowTitle(filename);
    }
    existflag=true;
}

void MainWindow::saveas_file_action(){
    qDebug()<<"saveas";
    this->path=QFileDialog::getSaveFileName(this,"save as",".","*.txt");
    QFile file(this->path);
    bool res=file.open(QFile::WriteOnly);
    if(res==true){
        QString content=this->text_edit->toPlainText();
        file.write((content.toStdString()).data());
        file.close();
        QFileInfo info(this->path);
        this->filename=info.fileName();
        this->setWindowTitle(this->filename);
        this->text_edit->document()->setModified(false);
    }
    existflag=true;
}

void MainWindow::read_file(){
    existflag=true;
    this->path=QFileDialog::getOpenFileName(this,"open file",".","*.txt");
    QFileInfo fi(path);
    this->filename=fi.fileName();
    QFile file(path);
    bool res=file.open(QFile::ReadOnly);
    if(res==true){
        QByteArray arr=file.readAll();
        this->text_edit->setText(arr);
        file.close();
    }
    this->setWindowTitle(this->filename);
}

void MainWindow::refresh_title(){
    this->text_edit->clear();
    filename=inifilename;
    this->setWindowTitle("untitle");
}

void MainWindow::not_save_title(){
    this->setWindowTitle("*"+this->filename);
}

void MainWindow::copy_action(){
    clip=this->text_edit->textCursor().selectedText();
}

void MainWindow::cut_action(){
    clip=this->text_edit->textCursor().selectedText();
    this->text_edit->textCursor().deleteChar();
}

void MainWindow::paste_action(){
    qDebug()<<clip;
    this->text_edit->textCursor().insertText(clip);
}

void MainWindow::font_select(){
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    this->text_edit->setCurrentFont(font);
}

void MainWindow::color_select(){
    QColor color=QColorDialog::getColor(Qt::black,this);
    this->text_edit->setTextColor(color);
}
