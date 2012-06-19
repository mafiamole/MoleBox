/********************************************************************************
** Form generated from reading UI file 'GameLuaEditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELUAEDITOR_H
#define UI_GAMELUAEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_scriptSelection;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_New;
    QPushButton *pushButton_SaveAs;
    QTabWidget *tabCodeWindow;
    QWidget *tab;
    QLabel *label_2;
    QListWidget *listWidget_errors;

    void setupUi(QWidget *ScriptEditor)
    {
        if (ScriptEditor->objectName().isEmpty())
            ScriptEditor->setObjectName(QString::fromUtf8("ScriptEditor"));
        ScriptEditor->resize(568, 596);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScriptEditor->sizePolicy().hasHeightForWidth());
        ScriptEditor->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ScriptEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ScriptEditor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_scriptSelection = new QComboBox(ScriptEditor);
        comboBox_scriptSelection->setObjectName(QString::fromUtf8("comboBox_scriptSelection"));

        horizontalLayout->addWidget(comboBox_scriptSelection);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);

        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(ScriptEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(48);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(500, 30));
        groupBox->setFlat(true);
        pushButton_Save = new QPushButton(groupBox);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(10, 0, 75, 23));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Save->sizePolicy().hasHeightForWidth());
        pushButton_Save->setSizePolicy(sizePolicy2);
        pushButton_New = new QPushButton(groupBox);
        pushButton_New->setObjectName(QString::fromUtf8("pushButton_New"));
        pushButton_New->setGeometry(QRect(170, 0, 75, 23));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_New->sizePolicy().hasHeightForWidth());
        pushButton_New->setSizePolicy(sizePolicy3);
        pushButton_SaveAs = new QPushButton(groupBox);
        pushButton_SaveAs->setObjectName(QString::fromUtf8("pushButton_SaveAs"));
        pushButton_SaveAs->setGeometry(QRect(90, 0, 75, 23));
        sizePolicy2.setHeightForWidth(pushButton_SaveAs->sizePolicy().hasHeightForWidth());
        pushButton_SaveAs->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(groupBox);

        tabCodeWindow = new QTabWidget(ScriptEditor);
        tabCodeWindow->setObjectName(QString::fromUtf8("tabCodeWindow"));
        tabCodeWindow->setTabsClosable(true);
        tabCodeWindow->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabCodeWindow->addTab(tab, QString());

        verticalLayout->addWidget(tabCodeWindow);

        label_2 = new QLabel(ScriptEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        listWidget_errors = new QListWidget(ScriptEditor);
        listWidget_errors->setObjectName(QString::fromUtf8("listWidget_errors"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget_errors->sizePolicy().hasHeightForWidth());
        listWidget_errors->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(listWidget_errors);


        retranslateUi(ScriptEditor);

        tabCodeWindow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScriptEditor);
    } // setupUi

    void retranslateUi(QWidget *ScriptEditor)
    {
        ScriptEditor->setWindowTitle(QApplication::translate("ScriptEditor", "Lua Script Editor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScriptEditor", "Select Script", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pushButton_Save->setText(QApplication::translate("ScriptEditor", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_New->setText(QApplication::translate("ScriptEditor", "New", 0, QApplication::UnicodeUTF8));
        pushButton_SaveAs->setText(QApplication::translate("ScriptEditor", "Save As", 0, QApplication::UnicodeUTF8));
        tabCodeWindow->setTabText(tabCodeWindow->indexOf(tab), QApplication::translate("ScriptEditor", "Resources", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScriptEditor", "Errors.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScriptEditor: public Ui_ScriptEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELUAEDITOR_H
