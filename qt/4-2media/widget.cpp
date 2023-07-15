#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pathcount=0;
    play_mode_flag=0;
    play_state=false;
    change_state=true;

    this->player=new QMediaPlayer;
    this->timer=new QTimer;
    this->video = new QVideoWidget;
    this->pathlist=new QStringList;
    this->namelist=new QStringList;

    this->ui->verticalLayout_2->addWidget(video);
    this->ui->playtime->setValue(0);
    this->ui->volumn->setRange(0,100);
    this->ui->volumn->setValue(0);
    this->player->setVolume(0);

    connect(this->player,&QMediaPlayer::durationChanged,this,&Widget::get_duration);
    connect(this->timer,&QTimer::timeout,this,&Widget::update_time);
    connect(this->player,&QMediaPlayer::positionChanged,this,&Widget::songtime_change);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::path_file(){
    QFileInfo info(pathlist->at(pathcount));
    this->songname=info.fileName();
    this->ui->songname->setText(songname);
}

void Widget::on_chs_btn_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"chose",".","MP4(*.mp4);;WAV(*.wav)");
    pathlist->append(path);
    QString tmp;
    QFileInfo info(path);
    tmp=info.fileName();
    namelist->append(tmp);
    this->ui->listWidget->addItem(tmp);
#if 0
    for(int i=0;i<pathlist->size();i++){
        QFileInfo info(pathlist->at(i));
        tmp=info.fileName();
        this->ui->listWidget->addItem(tmp);
    }
#endif
}

void Widget::on_up_btn_clicked()
{
    if(pathcount>0){
        pathcount--;
    }
    else if(pathcount==0){
        pathcount=pathlist->size()-1;
    }
    path_file();
    change_state=true;
    if(play_state==true){
        preplay();
    }
}

void Widget::on_dow_btn_clicked()
{
    if(pathcount==pathlist->size()-1){
        pathcount=0;
    }
    else if(pathcount<pathlist->size()-1){
        pathcount++;
    }
    path_file();
    change_state=true;
    if(play_state==true){
        preplay();
    }
}

void Widget::preplay(){
    QString path=pathlist->at(pathcount);
    this->player->setMedia(QMediaContent(path));
    this->charcount=0;
    if(path.endsWith(".mp4")){
        qDebug()<<path;
        this->player->setVideoOutput(this->video);
    }
    else if(path.endsWith(".wav")){
    }
    this->timer->start(1000);
    this->player->play();
    change_state=false;
}

void Widget::on_play_btn_clicked()
{
    if(change_state==true){
        path_file();
        preplay();
        change_state=false;
    }
    else if(change_state==false){
        this->timer->start(1000);
        this->player->play();
    }
    play_state=true;
}

void Widget::on_psu_btn_clicked()
{
    this->player->pause();
    play_state=false;
}

void Widget::get_duration(qint64 duration){
    this->ui->playtime->setRange(0,duration);
}

void Widget::songtime_change(qint64 position){
    this->ui->playtime->setValue(position);
}

void Widget::update_time(){
    this->charcount++;

    if(this->charcount==this->songname.size()){
        this->charcount=0;
    }
    this->ui->songname->setText(this->songname.mid(this->charcount));

    qint64 dur =this->player->duration();
    qint64 pos=this->player->position();
    QTime time1(0,0,0,0),time2(0,0,0,0);

    this->ui->songtime->setText(time2.addMSecs(pos).toString("mm:ss")+"/"+time1.addMSecs(dur).toString("mm:ss"));

    if(pos==dur){
        this->player->stop();
        switch (play_mode_flag) {
        case 0:
            break;
        case 1:
            this->player->play();
            break;
        case 2:
            if(this->pathcount==pathlist->size()-1){
                on_psu_btn_clicked();
            }
            else{
                on_dow_btn_clicked();
            }
            break;
        case 3:
            this->on_dow_btn_clicked();
            break;
        }
    }
}

void Widget::on_playtime_sliderMoved(int position)
{
    this->player->setPosition(position);
}

void Widget::on_volumn_sliderMoved(int position)
{
    this->player->setVolume(position);
}

void Widget::on_sp_btn_clicked()
{
    play_mode_flag=0;
}

void Widget::on_slp_btn_clicked()
{
    play_mode_flag=1;
}

void Widget::on_lsp_btn_clicked()
{
    play_mode_flag=2;
}

void Widget::on_llp_btn_clicked()
{
    play_mode_flag=3;
}

void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString play_clic=item->text();
    pathcount=namelist->indexOf(play_clic);
    path_file();
    preplay();

}
