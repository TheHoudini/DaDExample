#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "cwebview.h"
#include "clistview.h"
#include <QListView>
#include <QStringListModel>

class dialog : public QWidget
{
    Q_OBJECT

public:
    dialog(QWidget *parent = 0);
    ~dialog();

    cWebView *webView;
    cListView *listView;


public slots:
    // интеграция объектов к js
    void addJsObjects();

};

#endif // DIALOG_H
