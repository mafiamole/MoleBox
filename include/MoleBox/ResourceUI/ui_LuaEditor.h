/********************************************************************************
** Form generated from reading UI file 'LuaEditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUAEDITOR_H
#define UI_LUAEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_saveas;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_script;

    void setupUi(QWidget *ScriptEditor)
    {
        if (ScriptEditor->objectName().isEmpty())
            ScriptEditor->setObjectName(QString::fromUtf8("ScriptEditor"));
        ScriptEditor->resize(394, 352);
        verticalLayout = new QVBoxLayout(ScriptEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_save = new QPushButton(ScriptEditor);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        pushButton_saveas = new QPushButton(ScriptEditor);
        pushButton_saveas->setObjectName(QString::fromUtf8("pushButton_saveas"));

        horizontalLayout->addWidget(pushButton_saveas);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textEdit_script = new QTextEdit(ScriptEditor);
        textEdit_script->setObjectName(QString::fromUtf8("textEdit_script"));

        verticalLayout->addWidget(textEdit_script);


        retranslateUi(ScriptEditor);

        QMetaObject::connectSlotsByName(ScriptEditor);
    } // setupUi

    void retranslateUi(QWidget *ScriptEditor)
    {
        ScriptEditor->setWindowTitle(QApplication::translate("ScriptEditor", "Lua Script Editor", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("ScriptEditor", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_saveas->setText(QApplication::translate("ScriptEditor", "Save As", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScriptEditor: public Ui_ScriptEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUAEDITOR_H
