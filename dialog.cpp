#include "dialog.h"
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>

dialog::dialog(QWidget *parent)
    : QWidget(parent)
{
    this->setLayout(new QHBoxLayout() );



    listView = new cListView(this);
    webView  = new cWebView(this);


    connect(webView,SIGNAL(onDrop(QString)),listView,SLOT(addPath(QString)));
    connect(webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(addJsObjects()));


    this->layout()->addWidget(webView);
    this->layout()->addWidget(listView);






}

dialog::~dialog()
{

}

void dialog::addJsObjects()
{
    webView->page()->mainFrame()->addToJavaScriptWindowObject("listView",listView);
}

