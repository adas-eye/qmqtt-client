#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "qmqtt.h"
#include "connform.h"
#include "pubform.h"
#include "subform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QMQTT::Client *client, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onMQTT_Connected();
    void onMQTT_Connacked(quint8 ack);
    void onMQTT_error(QAbstractSocket::SocketError err);
    void onMQTT_Published(QMQTT::Message &message);
    void onMQTT_Pubacked(quint8 type, quint16 msgid);
    void onMQTT_Received(const QMQTT::Message &message);
    void onMQTT_subscribed(const QString &topic);
    void onMQTT_subacked(quint16 msgid, quint8 qos);
    void onMQTT_unsubscribed(const QString &topic);
    void onMQTT_unsubacked(quint16 msgid);
    void onMQTT_Pong();
    void onMQTT_disconnected();

    void on_action_Connect_triggered();
    void on_action_Subscribe_triggered();
    void on_action_Publish_triggered();
    void on_action_About_triggered();

    void on_action_Quit_triggered();

private:
    void clearChecked();
    void log(const QString & msg);
    QMQTT::Client *_client;
    Ui::MainWindow *ui;
    ConnForm * _connDialog;
    PubForm * _pubDialog;
    SubForm * _subDialog;
};

#endif // MAINWINDOW_H
