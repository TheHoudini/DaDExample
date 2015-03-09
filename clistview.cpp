#include "clistview.h"
#include <QModelIndex>
#include <QAbstractItemView>
#include <QDebug>
#include <QSize>

cListView::cListView(QWidget *parent)
{
    this->setParent(parent);
    // запрет редактирования
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    strListModel = new QStringListModel(this);


}

cListView::~cListView()
{

}

int cListView::getCurrentRow()
{
    return this->currentIndex().row();
}




void cListView::addPath(QString str)
{
    str.remove(0,8);
    strList << str;
    strListModel->setStringList(strList);
    this->setModel(strListModel);

}

void cListView::setCurrentRow(int x)
{
    this->setCurrentIndex( strListModel->index(x));
}




