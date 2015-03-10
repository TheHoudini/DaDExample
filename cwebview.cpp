#include "cwebview.h"
#include <QMimeData>

cWebView::cWebView(QWidget *parent)
{

    setParent(parent);
    id=0;


    html = html.append(" <script> listView.clicked.connect(itemClicked);  var active; \
                           function  onClicked(id){  \
                                 if(active) active.border=\"1\";\
                                 active = document.getElementById(id);\
                                 if(active)active.border=\"5\";\
                                 listView.setCurrentRow(id);    }\
                           function itemClicked(){ \
                                 if(active)active.border=\"1\";  \
                                 active = document.getElementById(listView.currentRow); \
                                 if(active)active.border=\"5\"; \
                                         }    </script> ");

    setHtml(html);
}

cWebView::~cWebView()
{

}

void cWebView::dropEvent(QDropEvent *event)
{
    // запись всех путей в list
    QStringList list;
    list = event->mimeData()->text().split("\n");

    // для каждого пути  добавляется картинка и испускается сигнал
    for(int i =0;i<list.count()-1;i++){

        emit onDrop(list.at(i));

        html = html.append("<img src=\"%1\" width=\"50\" height=\"50\" border=\"1\" id=\"%2\" onClick=\"onClicked(%3)\"  > \n ")
                    .arg(list.at(i)).arg(id).arg(id);
        id++;

    }

    setHtml(html);

}




