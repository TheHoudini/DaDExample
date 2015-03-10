#include "window.h"
#include "ui_window.h"

window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);


    connect(ui->mWebView,SIGNAL(onDrop(QString)),ui->mListView,SLOT(addPath(QString)));
    connect(ui->mWebView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(addJsObjects()));




}

window::~window()
{
    delete ui;
}


void window::addJsObjects()
{
    ui->mWebView->page()->mainFrame()->addToJavaScriptWindowObject("listView",ui->mListView);
}
