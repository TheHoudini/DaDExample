#ifndef CLISTVIEW_H
#define CLISTVIEW_H

#include <QObject>
#include <QWidget>
#include <QListView>
#include <QStringList>
#include <QStringListModel>


class cListView : public QListView
{
    Q_OBJECT
    Q_PROPERTY(int currentRow READ getCurrentRow)
public:
    cListView(QWidget*);
    ~cListView();

    // геттер для параметра currentRow
    int getCurrentRow();

private:
    QStringList strList;
    QStringListModel *strListModel;



public slots:
    // добавляет итем в виджет
    void addPath(QString);
    // устанавливает строку текущей
    Q_INVOKABLE void setCurrentRow(int);


};

#endif // CLISTVIEW_H
