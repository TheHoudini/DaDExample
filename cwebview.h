#ifndef CWEBVIEW_H
#define CWEBVIEW_H

#include <QObject>
#include <QWidget>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebView>
#include <QWebView>
#include <QDropEvent>
#include <QModelIndex>


class cWebView : public QWebView
{
    Q_OBJECT
public:
    cWebView(QWidget *);
    ~cWebView();

    // событие сброса файла на виджет
    void dropEvent(QDropEvent *);


private:
    int id;
    QString html;

public slots:

signals:
    // сигнал,который испускается при сбросе файла на виджет
    // передаётся путь к файлу
    void onDrop(QString);

};

#endif // CWEBVIEW_H
