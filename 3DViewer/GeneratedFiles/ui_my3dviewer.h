/********************************************************************************
** Form generated from reading UI file 'my3dviewer.ui'
**
** Created: Mon Apr 23 20:54:06 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY3DVIEWER_H
#define UI_MY3DVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_My3DViewerClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *mainWindowClass;
    QPushButton *StartSpin;
    QPushButton *StopSpin;
    QRadioButton *radioButton;
    QListWidget *ListOfFaces;
    QListWidget *ListOfVertices;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QListWidget *HE;
    QLabel *label_9;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QListWidget *ListOfControlPoints;
    QLabel *label_14;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSlider *horizontalSlider_6;
    QToolBox *Operations;
    QWidget *page;
    QPushButton *AddVertex;
    QPushButton *DivideQuad;
    QPushButton *DeleteVertex;
    QPushButton *EdgeBtwFaces;
    QPushButton *Smooth;
    QPushButton *pushButton_4;
    QWidget *page_3;
    QPushButton *FocusV;
    QPushButton *FocusE;
    QPushButton *FocusF;
    QPushButton *LoadFrag;
    QWidget *page_2;
    QPushButton *ToggleFFD;
    QPushButton *SaveFile;
    QPushButton *UploadFile;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label_10;
    QPushButton *pushButton_2;
    QDoubleSpinBox *doubleSpinBox_5;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_18;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_8;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *My3DViewerClass)
    {
        if (My3DViewerClass->objectName().isEmpty())
            My3DViewerClass->setObjectName(QString::fromUtf8("My3DViewerClass"));
        My3DViewerClass->resize(908, 776);
        My3DViewerClass->setMouseTracking(true);
        My3DViewerClass->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(My3DViewerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFocusPolicy(Qt::StrongFocus);
        mainWindowClass = new MyGLWidget(centralWidget);
        mainWindowClass->setObjectName(QString::fromUtf8("mainWindowClass"));
        mainWindowClass->setGeometry(QRect(10, 10, 641, 481));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        mainWindowClass->setPalette(palette);
        mainWindowClass->setMouseTracking(true);
        mainWindowClass->setFocusPolicy(Qt::NoFocus);
        StartSpin = new QPushButton(centralWidget);
        StartSpin->setObjectName(QString::fromUtf8("StartSpin"));
        StartSpin->setGeometry(QRect(710, 410, 131, 23));
        StopSpin = new QPushButton(centralWidget);
        StopSpin->setObjectName(QString::fromUtf8("StopSpin"));
        StopSpin->setGeometry(QRect(710, 440, 131, 23));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(190, 500, 82, 17));
        ListOfFaces = new QListWidget(centralWidget);
        ListOfFaces->setObjectName(QString::fromUtf8("ListOfFaces"));
        ListOfFaces->setGeometry(QRect(10, 550, 101, 221));
        ListOfFaces->setFocusPolicy(Qt::ClickFocus);
        ListOfVertices = new QListWidget(centralWidget);
        ListOfVertices->setObjectName(QString::fromUtf8("ListOfVertices"));
        ListOfVertices->setGeometry(QRect(120, 550, 101, 221));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 530, 46, 13));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 530, 51, 16));
        label_2->setFont(font);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(510, 510, 160, 19));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #f55);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #f55, stop: 1 #c11);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(510, 550, 160, 19));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #5e6);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #5e6, stop: 1 #080);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(510, 590, 160, 19));
        horizontalSlider_3->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #bbf);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #bbf, stop: 1 #55f);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 510, 16, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 550, 16, 16));
        label_4->setMouseTracking(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 590, 16, 16));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(780, 630, 62, 22));
        doubleSpinBox->setMinimum(-99.9);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(780, 660, 62, 22));
        doubleSpinBox_2->setMinimum(-99.9);
        doubleSpinBox_2->setSingleStep(0.1);
        doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(780, 690, 62, 22));
        doubleSpinBox_3->setMinimum(-99.9);
        doubleSpinBox_3->setSingleStep(0.1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(770, 630, 16, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(770, 690, 16, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(770, 660, 16, 16));
        HE = new QListWidget(centralWidget);
        HE->setObjectName(QString::fromUtf8("HE"));
        HE->setGeometry(QRect(230, 550, 101, 221));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 530, 71, 16));
        label_9->setFont(font);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(800, 510, 42, 22));
        spinBox->setMinimum(2);
        spinBox->setMaximum(6);
        spinBox->setValue(5);
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(800, 550, 42, 22));
        spinBox_2->setMinimum(2);
        spinBox_2->setMaximum(6);
        spinBox_2->setValue(5);
        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(800, 590, 42, 22));
        spinBox_3->setMinimum(2);
        spinBox_3->setMaximum(6);
        spinBox_3->setValue(5);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(730, 510, 61, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(730, 550, 51, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(730, 590, 51, 20));
        ListOfControlPoints = new QListWidget(centralWidget);
        ListOfControlPoints->setObjectName(QString::fromUtf8("ListOfControlPoints"));
        ListOfControlPoints->setGeometry(QRect(340, 550, 101, 221));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(340, 530, 81, 16));
        horizontalSlider_4 = new QSlider(centralWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(510, 660, 160, 19));
        horizontalSlider_4->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #f55);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #f55, stop: 1 #c11);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_4->setMaximum(1000);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(centralWidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(510, 740, 160, 19));
        horizontalSlider_5->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #bbf);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #bbf, stop: 1 #55f);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_5->setMaximum(1000);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(490, 700, 16, 16));
        label_15->setMouseTracking(true);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(490, 660, 16, 16));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(490, 740, 16, 16));
        horizontalSlider_6 = new QSlider(centralWidget);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setGeometry(QRect(510, 700, 160, 19));
        horizontalSlider_6->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #5e6);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #5e6, stop: 1 #080);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        horizontalSlider_6->setMaximum(1000);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        Operations = new QToolBox(centralWidget);
        Operations->setObjectName(QString::fromUtf8("Operations"));
        Operations->setGeometry(QRect(660, 40, 231, 331));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 231, 250));
        AddVertex = new QPushButton(page);
        AddVertex->setObjectName(QString::fromUtf8("AddVertex"));
        AddVertex->setGeometry(QRect(30, 10, 131, 23));
        DivideQuad = new QPushButton(page);
        DivideQuad->setObjectName(QString::fromUtf8("DivideQuad"));
        DivideQuad->setGeometry(QRect(30, 40, 131, 23));
        DeleteVertex = new QPushButton(page);
        DeleteVertex->setObjectName(QString::fromUtf8("DeleteVertex"));
        DeleteVertex->setGeometry(QRect(30, 100, 131, 23));
        EdgeBtwFaces = new QPushButton(page);
        EdgeBtwFaces->setObjectName(QString::fromUtf8("EdgeBtwFaces"));
        EdgeBtwFaces->setGeometry(QRect(30, 70, 131, 23));
        Smooth = new QPushButton(page);
        Smooth->setObjectName(QString::fromUtf8("Smooth"));
        Smooth->setGeometry(QRect(50, 130, 75, 23));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 160, 75, 23));
        Operations->addItem(page, QString::fromUtf8("Geometry"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 100, 30));
        FocusV = new QPushButton(page_3);
        FocusV->setObjectName(QString::fromUtf8("FocusV"));
        FocusV->setGeometry(QRect(20, 10, 75, 23));
        FocusE = new QPushButton(page_3);
        FocusE->setObjectName(QString::fromUtf8("FocusE"));
        FocusE->setGeometry(QRect(20, 40, 75, 23));
        FocusF = new QPushButton(page_3);
        FocusF->setObjectName(QString::fromUtf8("FocusF"));
        FocusF->setGeometry(QRect(20, 70, 75, 23));
        LoadFrag = new QPushButton(page_3);
        LoadFrag->setObjectName(QString::fromUtf8("LoadFrag"));
        LoadFrag->setGeometry(QRect(20, 100, 75, 23));
        Operations->addItem(page_3, QString::fromUtf8("Camera"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 231, 250));
        ToggleFFD = new QPushButton(page_2);
        ToggleFFD->setObjectName(QString::fromUtf8("ToggleFFD"));
        ToggleFFD->setGeometry(QRect(20, 70, 75, 23));
        SaveFile = new QPushButton(page_2);
        SaveFile->setObjectName(QString::fromUtf8("SaveFile"));
        SaveFile->setGeometry(QRect(20, 40, 75, 23));
        UploadFile = new QPushButton(page_2);
        UploadFile->setObjectName(QString::fromUtf8("UploadFile"));
        UploadFile->setGeometry(QRect(20, 10, 75, 23));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 130, 75, 23));
        doubleSpinBox_4 = new QDoubleSpinBox(page_2);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(120, 130, 62, 22));
        doubleSpinBox_4->setMaximum(5);
        doubleSpinBox_4->setSingleStep(0.1);
        doubleSpinBox_4->setValue(1);
        radioButton_2 = new QRadioButton(page_2);
        buttonGroup = new QButtonGroup(My3DViewerClass);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(80, 110, 31, 17));
        radioButton_3 = new QRadioButton(page_2);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(120, 110, 31, 17));
        radioButton_4 = new QRadioButton(page_2);
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(160, 110, 82, 17));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 110, 31, 16));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 160, 75, 23));
        doubleSpinBox_5 = new QDoubleSpinBox(page_2);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(120, 160, 62, 22));
        doubleSpinBox_5->setMinimum(-5);
        doubleSpinBox_5->setMaximum(5);
        doubleSpinBox_5->setSingleStep(0.1);
        doubleSpinBox_5->setValue(1);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 75, 23));
        doubleSpinBox_6 = new QDoubleSpinBox(page_2);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(120, 190, 62, 22));
        doubleSpinBox_6->setMaximum(5);
        doubleSpinBox_6->setSingleStep(0.1);
        doubleSpinBox_6->setValue(1);
        doubleSpinBox_7 = new QDoubleSpinBox(page_2);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(60, 220, 62, 22));
        doubleSpinBox_7->setMinimum(-100);
        doubleSpinBox_7->setMaximum(100);
        label_18 = new QLabel(page_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 220, 31, 21));
        label_19 = new QLabel(page_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(130, 220, 16, 21));
        doubleSpinBox_8 = new QDoubleSpinBox(page_2);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(150, 220, 62, 22));
        doubleSpinBox_8->setMinimum(-100);
        doubleSpinBox_8->setMaximum(100);
        doubleSpinBox_8->setSingleStep(0.5);
        doubleSpinBox_8->setValue(1);
        Operations->addItem(page_2, QString::fromUtf8("Deformations"));
        My3DViewerClass->setCentralWidget(centralWidget);

        retranslateUi(My3DViewerClass);
        QObject::connect(StartSpin, SIGNAL(clicked()), mainWindowClass, SLOT(play()));
        QObject::connect(StopSpin, SIGNAL(clicked()), mainWindowClass, SLOT(stop()));
        QObject::connect(radioButton, SIGNAL(clicked()), mainWindowClass, SLOT(mousemodetoggle()));
        QObject::connect(ListOfFaces, SIGNAL(itemClicked(QListWidgetItem*)), mainWindowClass, SLOT(setCurr(QListWidgetItem*)));
        QObject::connect(ListOfVertices, SIGNAL(itemClicked(QListWidgetItem*)), mainWindowClass, SLOT(setCurr2(QListWidgetItem*)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(colorRed(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(colorGreen(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(colorBlue(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(x(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(y(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(z(double)));
        QObject::connect(mainWindowClass, SIGNAL(red(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(mainWindowClass, SIGNAL(green(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(mainWindowClass, SIGNAL(blue(int)), horizontalSlider_3, SLOT(setValue(int)));
        QObject::connect(mainWindowClass, SIGNAL(xsig(double)), doubleSpinBox, SLOT(setValue(double)));
        QObject::connect(mainWindowClass, SIGNAL(ysig(double)), doubleSpinBox_2, SLOT(setValue(double)));
        QObject::connect(mainWindowClass, SIGNAL(zsig(double)), doubleSpinBox_3, SLOT(setValue(double)));
        QObject::connect(DeleteVertex, SIGNAL(clicked()), mainWindowClass, SLOT(deleteVertex()));
        QObject::connect(DivideQuad, SIGNAL(clicked()), mainWindowClass, SLOT(quadtwotriangles()));
        QObject::connect(AddVertex, SIGNAL(clicked()), mainWindowClass, SLOT(addVertex()));
        QObject::connect(EdgeBtwFaces, SIGNAL(clicked()), mainWindowClass, SLOT(edgeBtwnTwoFaces()));
        QObject::connect(HE, SIGNAL(itemClicked(QListWidgetItem*)), mainWindowClass, SLOT(setCurrHE(QListWidgetItem*)));
        QObject::connect(UploadFile, SIGNAL(clicked()), mainWindowClass, SLOT(loadFile()));
        QObject::connect(Smooth, SIGNAL(clicked()), mainWindowClass, SLOT(moveEverything()));
        QObject::connect(SaveFile, SIGNAL(clicked()), mainWindowClass, SLOT(saveFile()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(getXDiv(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(getYDiv(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(getZDiv(int)));
        QObject::connect(ListOfControlPoints, SIGNAL(itemClicked(QListWidgetItem*)), mainWindowClass, SLOT(setCurr2(QListWidgetItem*)));
        QObject::connect(FocusV, SIGNAL(clicked()), mainWindowClass, SLOT(focusV()));
        QObject::connect(LoadFrag, SIGNAL(clicked()), mainWindowClass, SLOT(loadFrag()));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(lightsX()));
        QObject::connect(horizontalSlider_6, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(lightsY()));
        QObject::connect(horizontalSlider_5, SIGNAL(valueChanged(int)), mainWindowClass, SLOT(lightsZ()));
        QObject::connect(ToggleFFD, SIGNAL(clicked()), mainWindowClass, SLOT(toggleDeform()));
        QObject::connect(pushButton, SIGNAL(clicked()), mainWindowClass, SLOT(twistmesh()));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(setTwistval(double)));
        QObject::connect(radioButton_2, SIGNAL(clicked()), mainWindowClass, SLOT(twistX()));
        QObject::connect(radioButton_3, SIGNAL(clicked()), mainWindowClass, SLOT(twistY()));
        QObject::connect(radioButton_4, SIGNAL(clicked()), mainWindowClass, SLOT(twistZ()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mainWindowClass, SLOT(taperMesh()));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(setTaperval(double)));
        QObject::connect(doubleSpinBox_7, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(setBendMin(double)));
        QObject::connect(doubleSpinBox_8, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(setBendMax(double)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), mainWindowClass, SLOT(bendMesh()));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), mainWindowClass, SLOT(setBendval(double)));
        QObject::connect(pushButton_4, SIGNAL(clicked()), mainWindowClass, SLOT(unitCube()));

        Operations->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(My3DViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *My3DViewerClass)
    {
        My3DViewerClass->setWindowTitle(QApplication::translate("My3DViewerClass", "My 3D Viewer", 0, QApplication::UnicodeUTF8));
        StartSpin->setText(QApplication::translate("My3DViewerClass", "Start Spinning!", 0, QApplication::UnicodeUTF8));
        StopSpin->setText(QApplication::translate("My3DViewerClass", "Stop Spinning!", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("My3DViewerClass", "MouseMode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("My3DViewerClass", "Faces", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("My3DViewerClass", "Vertices", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("My3DViewerClass", "R", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("My3DViewerClass", "G", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("My3DViewerClass", "B", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("My3DViewerClass", "X", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("My3DViewerClass", "Z", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("My3DViewerClass", "Y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("My3DViewerClass", "HalfEdges", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("My3DViewerClass", "X Divisions", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("My3DViewerClass", "Y Divisions", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("My3DViewerClass", "Z Divisions", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("My3DViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Control Points</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("My3DViewerClass", "Y", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("My3DViewerClass", "X", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("My3DViewerClass", "Z", 0, QApplication::UnicodeUTF8));
        AddVertex->setText(QApplication::translate("My3DViewerClass", "Add Vertex", 0, QApplication::UnicodeUTF8));
        DivideQuad->setText(QApplication::translate("My3DViewerClass", "Divide Quad", 0, QApplication::UnicodeUTF8));
        DeleteVertex->setText(QApplication::translate("My3DViewerClass", "Delete Vertex", 0, QApplication::UnicodeUTF8));
        EdgeBtwFaces->setText(QApplication::translate("My3DViewerClass", "Edge Between Two Faces", 0, QApplication::UnicodeUTF8));
        Smooth->setText(QApplication::translate("My3DViewerClass", "Smooth", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("My3DViewerClass", "Unit Cube", 0, QApplication::UnicodeUTF8));
        Operations->setItemText(Operations->indexOf(page), QApplication::translate("My3DViewerClass", "Geometry", 0, QApplication::UnicodeUTF8));
        FocusV->setText(QApplication::translate("My3DViewerClass", "focus v", 0, QApplication::UnicodeUTF8));
        FocusE->setText(QApplication::translate("My3DViewerClass", "focus e", 0, QApplication::UnicodeUTF8));
        FocusF->setText(QApplication::translate("My3DViewerClass", "focus f", 0, QApplication::UnicodeUTF8));
        LoadFrag->setText(QApplication::translate("My3DViewerClass", "load Frag", 0, QApplication::UnicodeUTF8));
        Operations->setItemText(Operations->indexOf(page_3), QApplication::translate("My3DViewerClass", "Camera", 0, QApplication::UnicodeUTF8));
        ToggleFFD->setText(QApplication::translate("My3DViewerClass", "Toggle FFD", 0, QApplication::UnicodeUTF8));
        SaveFile->setText(QApplication::translate("My3DViewerClass", "Save File", 0, QApplication::UnicodeUTF8));
        UploadFile->setText(QApplication::translate("My3DViewerClass", "Upload file", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("My3DViewerClass", "Twist", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("My3DViewerClass", "X", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("My3DViewerClass", "Y", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("My3DViewerClass", "Z", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("My3DViewerClass", "Axis:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("My3DViewerClass", "Taper", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("My3DViewerClass", "Bend", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("My3DViewerClass", "From:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("My3DViewerClass", "To:", 0, QApplication::UnicodeUTF8));
        Operations->setItemText(Operations->indexOf(page_2), QApplication::translate("My3DViewerClass", "Deformations", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class My3DViewerClass: public Ui_My3DViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY3DVIEWER_H
