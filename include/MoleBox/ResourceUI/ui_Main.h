/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeView *treeView_resources;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_resourceViews;
    QListView *listView_errorConsole;

    void setupUi(QWidget *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QString::fromUtf8("Main"));
        Main->resize(685, 535);
        horizontalLayout = new QHBoxLayout(Main);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(Main);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView_resources = new QTreeView(splitter);
        treeView_resources->setObjectName(QString::fromUtf8("treeView_resources"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView_resources->sizePolicy().hasHeightForWidth());
        treeView_resources->setSizePolicy(sizePolicy);
        splitter->addWidget(treeView_resources);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget_resourceViews = new QTabWidget(frame);
        tabWidget_resourceViews->setObjectName(QString::fromUtf8("tabWidget_resourceViews"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(tabWidget_resourceViews->sizePolicy().hasHeightForWidth());
        tabWidget_resourceViews->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(tabWidget_resourceViews);

        listView_errorConsole = new QListView(frame);
        listView_errorConsole->setObjectName(QString::fromUtf8("listView_errorConsole"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(listView_errorConsole->sizePolicy().hasHeightForWidth());
        listView_errorConsole->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(listView_errorConsole);

        splitter->addWidget(frame);

        horizontalLayout->addWidget(splitter);


        retranslateUi(Main);

        tabWidget_resourceViews->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QWidget *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "Resources", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
