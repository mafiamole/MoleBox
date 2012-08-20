/********************************************************************************
** Form generated from reading UI file 'Audio.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIO_H
#define UI_AUDIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_AudioViewer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSplitter *splitter;
    Phonon::SeekSlider *seekSlider;
    Phonon::VolumeSlider *volumeSlider;

    void setupUi(QWidget *AudioViewer)
    {
        if (AudioViewer->objectName().isEmpty())
            AudioViewer->setObjectName(QString::fromUtf8("AudioViewer"));
        AudioViewer->resize(362, 60);
        verticalLayout = new QVBoxLayout(AudioViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AudioViewer);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        splitter = new QSplitter(AudioViewer);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        seekSlider = new Phonon::SeekSlider(splitter);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        splitter->addWidget(seekSlider);
        volumeSlider = new Phonon::VolumeSlider(splitter);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        splitter->addWidget(volumeSlider);

        verticalLayout->addWidget(splitter);


        retranslateUi(AudioViewer);

        QMetaObject::connectSlotsByName(AudioViewer);
    } // setupUi

    void retranslateUi(QWidget *AudioViewer)
    {
        AudioViewer->setWindowTitle(QApplication::translate("AudioViewer", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AudioViewer", "Playing:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AudioViewer: public Ui_AudioViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
