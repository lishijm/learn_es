#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QTimer>
#include <QTime>
#include <QVideoWidget>
#include <QListWidgetItem>
#include <QStringList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void preplay();

    void path_file();

private slots:
    void on_play_btn_clicked();

    void on_chs_btn_clicked();

    void get_duration(qint64 duration);

    void update_time();

    void on_playtime_sliderMoved(int position);

    void on_volumn_sliderMoved(int position);

    void songtime_change(qint64 position);

    void on_up_btn_clicked();

    void on_dow_btn_clicked();

    void on_psu_btn_clicked();

    void on_sp_btn_clicked();

    void on_slp_btn_clicked();

    void on_lsp_btn_clicked();

    void on_llp_btn_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QTimer *timer;
    int charcount;
    QString songname;
    QVideoWidget *video;
    QStringList *pathlist;
    QStringList *namelist;
    int pathcount;
    bool play_state;
    bool change_state;
    int play_mode_flag;
};

#endif // WIDGET_H
