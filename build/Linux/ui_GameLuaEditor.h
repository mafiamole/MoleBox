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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
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
    QPushButton *pushButton_Save;
    QTextEdit *textEdit_code;
    QLabel *label_2;
    QListWidget *listWidget_errors;

    void setupUi(QWidget *ScriptEditor)
    {
        if (ScriptEditor->objectName().isEmpty())
            ScriptEditor->setObjectName(QString::fromUtf8("ScriptEditor"));
        ScriptEditor->resize(621, 596);
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
        pushButton_Save = new QPushButton(ScriptEditor);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        horizontalLayout_2->addWidget(pushButton_Save);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit_code = new QTextEdit(ScriptEditor);
        textEdit_code->setObjectName(QString::fromUtf8("textEdit_code"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textEdit_code->sizePolicy().hasHeightForWidth());
        textEdit_code->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit_code);

        label_2 = new QLabel(ScriptEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        listWidget_errors = new QListWidget(ScriptEditor);
        listWidget_errors->setObjectName(QString::fromUtf8("listWidget_errors"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget_errors->sizePolicy().hasHeightForWidth());
        listWidget_errors->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(listWidget_errors);


        retranslateUi(ScriptEditor);

        QMetaObject::connectSlotsByName(ScriptEditor);
    } // setupUi

    void retranslateUi(QWidget *ScriptEditor)
    {
        ScriptEditor->setWindowTitle(QApplication::translate("ScriptEditor", "Lua Script Editor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScriptEditor", "Select Script", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("ScriptEditor", "Save", 0, QApplication::UnicodeUTF8));
        textEdit_code->setHtml(QApplication::translate("ScriptEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScriptEditor", "Errors.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScriptEditor: public Ui_ScriptEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELUAEDITOR_H
