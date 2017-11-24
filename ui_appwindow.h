/********************************************************************************
** Form generated from reading UI file 'appwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWINDOW_H
#define UI_APPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rtrglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_AppWindow
{
public:
    QHBoxLayout *mainLayout;
    rtrGLWidget *openGLWidget;
    QWidget *ui_container;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QComboBox *modelComboBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QComboBox *shaderComboBox;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSlider *sunlightSlider;
    QLabel *label_2;
    QSlider *nightLightSlider;
    QLabel *label_6;
    QSlider *blendExpSlider;
    QCheckBox *animationCheckbox;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *blackBgRadioButton;
    QRadioButton *greyBgRadioButton;
    QRadioButton *whiteBgRadioButton;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *bumpMapCheckbox;
    QSlider *bumpMapSlider;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *dispMapCheckBox;
    QSlider *dispMapSlider;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *wireframeCheckBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_off;
    QRadioButton *radioButton_N;
    QRadioButton *radioButton_T;
    QRadioButton *radioButton_B;
    QSlider *vectorScaleSlider;
    QSpacerItem *verticalSpacer;
    QPushButton *quitButton;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QButtonGroup *vectorsGroup;

    void setupUi(QWidget *AppWindow)
    {
        if (AppWindow->objectName().isEmpty())
            AppWindow->setObjectName(QStringLiteral("AppWindow"));
        AppWindow->resize(858, 701);
        AppWindow->setMinimumSize(QSize(800, 600));
        mainLayout = new QHBoxLayout(AppWindow);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        openGLWidget = new rtrGLWidget(AppWindow);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(0, 0));
        openGLWidget->setFocusPolicy(Qt::StrongFocus);

        mainLayout->addWidget(openGLWidget);

        ui_container = new QWidget(AppWindow);
        ui_container->setObjectName(QStringLiteral("ui_container"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ui_container->sizePolicy().hasHeightForWidth());
        ui_container->setSizePolicy(sizePolicy1);
        ui_container->setFocusPolicy(Qt::WheelFocus);
        verticalLayout = new QVBoxLayout(ui_container);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(ui_container);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        modelComboBox = new QComboBox(groupBox_2);
        modelComboBox->setObjectName(QStringLiteral("modelComboBox"));
        modelComboBox->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(modelComboBox);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ui_container);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        shaderComboBox = new QComboBox(groupBox_3);
        shaderComboBox->setObjectName(QStringLiteral("shaderComboBox"));
        shaderComboBox->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(shaderComboBox);

        widget_2 = new QWidget(groupBox_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        sunlightSlider = new QSlider(widget_2);
        sunlightSlider->setObjectName(QStringLiteral("sunlightSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sunlightSlider->sizePolicy().hasHeightForWidth());
        sunlightSlider->setSizePolicy(sizePolicy2);
        sunlightSlider->setFocusPolicy(Qt::NoFocus);
        sunlightSlider->setMaximum(100);
        sunlightSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sunlightSlider, 0, 2, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        nightLightSlider = new QSlider(widget_2);
        nightLightSlider->setObjectName(QStringLiteral("nightLightSlider"));
        sizePolicy2.setHeightForWidth(nightLightSlider->sizePolicy().hasHeightForWidth());
        nightLightSlider->setSizePolicy(sizePolicy2);
        nightLightSlider->setFocusPolicy(Qt::NoFocus);
        nightLightSlider->setValue(0);
        nightLightSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(nightLightSlider, 1, 2, 1, 1);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        blendExpSlider = new QSlider(widget_2);
        blendExpSlider->setObjectName(QStringLiteral("blendExpSlider"));
        blendExpSlider->setFocusPolicy(Qt::NoFocus);
        blendExpSlider->setMaximum(100);
        blendExpSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(blendExpSlider, 2, 2, 1, 1);


        verticalLayout_4->addWidget(widget_2);

        animationCheckbox = new QCheckBox(groupBox_3);
        animationCheckbox->setObjectName(QStringLiteral("animationCheckbox"));
        animationCheckbox->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(animationCheckbox);


        verticalLayout->addWidget(groupBox_3);

        groupBox_6 = new QGroupBox(ui_container);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        blackBgRadioButton = new QRadioButton(groupBox_6);
        blackBgRadioButton->setObjectName(QStringLiteral("blackBgRadioButton"));

        horizontalLayout_4->addWidget(blackBgRadioButton);

        greyBgRadioButton = new QRadioButton(groupBox_6);
        greyBgRadioButton->setObjectName(QStringLiteral("greyBgRadioButton"));
        greyBgRadioButton->setChecked(true);

        horizontalLayout_4->addWidget(greyBgRadioButton);

        whiteBgRadioButton = new QRadioButton(groupBox_6);
        whiteBgRadioButton->setObjectName(QStringLiteral("whiteBgRadioButton"));

        horizontalLayout_4->addWidget(whiteBgRadioButton);


        verticalLayout->addWidget(groupBox_6);

        groupBox_4 = new QGroupBox(ui_container);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 6, -1, 6);
        bumpMapCheckbox = new QCheckBox(groupBox_4);
        bumpMapCheckbox->setObjectName(QStringLiteral("bumpMapCheckbox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bumpMapCheckbox->sizePolicy().hasHeightForWidth());
        bumpMapCheckbox->setSizePolicy(sizePolicy3);
        bumpMapCheckbox->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(bumpMapCheckbox);

        bumpMapSlider = new QSlider(groupBox_4);
        bumpMapSlider->setObjectName(QStringLiteral("bumpMapSlider"));
        sizePolicy2.setHeightForWidth(bumpMapSlider->sizePolicy().hasHeightForWidth());
        bumpMapSlider->setSizePolicy(sizePolicy2);
        bumpMapSlider->setFocusPolicy(Qt::NoFocus);
        bumpMapSlider->setMaximum(100);
        bumpMapSlider->setValue(0);
        bumpMapSlider->setOrientation(Qt::Horizontal);
        bumpMapSlider->setInvertedAppearance(false);
        bumpMapSlider->setInvertedControls(false);

        horizontalLayout_2->addWidget(bumpMapSlider);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(ui_container);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 6, -1, 6);
        dispMapCheckBox = new QCheckBox(groupBox_5);
        dispMapCheckBox->setObjectName(QStringLiteral("dispMapCheckBox"));
        sizePolicy3.setHeightForWidth(dispMapCheckBox->sizePolicy().hasHeightForWidth());
        dispMapCheckBox->setSizePolicy(sizePolicy3);
        dispMapCheckBox->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(dispMapCheckBox);

        dispMapSlider = new QSlider(groupBox_5);
        dispMapSlider->setObjectName(QStringLiteral("dispMapSlider"));
        sizePolicy2.setHeightForWidth(dispMapSlider->sizePolicy().hasHeightForWidth());
        dispMapSlider->setSizePolicy(sizePolicy2);
        dispMapSlider->setFocusPolicy(Qt::NoFocus);
        dispMapSlider->setMaximum(100);
        dispMapSlider->setValue(0);
        dispMapSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(dispMapSlider);


        verticalLayout->addWidget(groupBox_5);

        groupBox = new QGroupBox(ui_container);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 6, -1, 6);
        wireframeCheckBox = new QCheckBox(groupBox);
        wireframeCheckBox->setObjectName(QStringLiteral("wireframeCheckBox"));
        wireframeCheckBox->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(wireframeCheckBox);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 0);
        radioButton_off = new QRadioButton(widget);
        vectorsGroup = new QButtonGroup(AppWindow);
        vectorsGroup->setObjectName(QStringLiteral("vectorsGroup"));
        vectorsGroup->addButton(radioButton_off);
        radioButton_off->setObjectName(QStringLiteral("radioButton_off"));
        radioButton_off->setFocusPolicy(Qt::NoFocus);
        radioButton_off->setChecked(true);

        horizontalLayout->addWidget(radioButton_off);

        radioButton_N = new QRadioButton(widget);
        vectorsGroup->addButton(radioButton_N);
        radioButton_N->setObjectName(QStringLiteral("radioButton_N"));
        radioButton_N->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(radioButton_N);

        radioButton_T = new QRadioButton(widget);
        vectorsGroup->addButton(radioButton_T);
        radioButton_T->setObjectName(QStringLiteral("radioButton_T"));
        radioButton_T->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(radioButton_T);

        radioButton_B = new QRadioButton(widget);
        vectorsGroup->addButton(radioButton_B);
        radioButton_B->setObjectName(QStringLiteral("radioButton_B"));
        radioButton_B->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(radioButton_B);


        verticalLayout_2->addWidget(widget);

        vectorScaleSlider = new QSlider(groupBox);
        vectorScaleSlider->setObjectName(QStringLiteral("vectorScaleSlider"));
        sizePolicy2.setHeightForWidth(vectorScaleSlider->sizePolicy().hasHeightForWidth());
        vectorScaleSlider->setSizePolicy(sizePolicy2);
        vectorScaleSlider->setFocusPolicy(Qt::NoFocus);
        vectorScaleSlider->setMinimum(1);
        vectorScaleSlider->setMaximum(100);
        vectorScaleSlider->setValue(1);
        vectorScaleSlider->setSliderPosition(1);
        vectorScaleSlider->setTracking(true);
        vectorScaleSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(vectorScaleSlider);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 368, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        quitButton = new QPushButton(ui_container);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(quitButton);

        label = new QLabel(ui_container);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(ui_container);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(ui_container);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(ui_container);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);


        mainLayout->addWidget(ui_container);


        retranslateUi(AppWindow);

        modelComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppWindow);
    } // setupUi

    void retranslateUi(QWidget *AppWindow)
    {
        AppWindow->setWindowTitle(QApplication::translate("AppWindow", "RTR Demo", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("AppWindow", "Model", Q_NULLPTR));
        modelComboBox->clear();
        modelComboBox->insertItems(0, QStringList()
         << QApplication::translate("AppWindow", "Sphere", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Torus", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Rect", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Cube", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Duck", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Teapot", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Dwarf", Q_NULLPTR)
        );
        groupBox_3->setTitle(QApplication::translate("AppWindow", "Shader", Q_NULLPTR));
        shaderComboBox->clear();
        shaderComboBox->insertItems(0, QStringList()
         << QApplication::translate("AppWindow", "Phong", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Debug Tex Coords", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Debug Day/Night", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Day Texture", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Night Texture", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Day+Night Texture", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Debug Gloss", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Phong+Gloss", Q_NULLPTR)
         << QApplication::translate("AppWindow", "Day+Night+Gloss", Q_NULLPTR)
         << QApplication::translate("AppWindow", "+Clouds", Q_NULLPTR)
         << QApplication::translate("AppWindow", "None", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("AppWindow", "Sunlight", Q_NULLPTR));
        label_2->setText(QApplication::translate("AppWindow", "Night Lights", Q_NULLPTR));
        label_6->setText(QApplication::translate("AppWindow", "Blending Exp", Q_NULLPTR));
        animationCheckbox->setText(QApplication::translate("AppWindow", "cloud animation", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("AppWindow", "Background", Q_NULLPTR));
        blackBgRadioButton->setText(QApplication::translate("AppWindow", "black", Q_NULLPTR));
        greyBgRadioButton->setText(QApplication::translate("AppWindow", "grey", Q_NULLPTR));
        whiteBgRadioButton->setText(QApplication::translate("AppWindow", "white", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("AppWindow", "Bump Mapping", Q_NULLPTR));
        bumpMapCheckbox->setText(QApplication::translate("AppWindow", "on", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("AppWindow", "Displacement Mapping", Q_NULLPTR));
        dispMapCheckBox->setText(QApplication::translate("AppWindow", "on", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AppWindow", "Visualize wireframe / vectors", Q_NULLPTR));
        wireframeCheckBox->setText(QApplication::translate("AppWindow", "wireframe", Q_NULLPTR));
        radioButton_off->setText(QApplication::translate("AppWindow", "off", Q_NULLPTR));
        radioButton_N->setText(QApplication::translate("AppWindow", "N", Q_NULLPTR));
        radioButton_T->setText(QApplication::translate("AppWindow", "T", Q_NULLPTR));
        radioButton_B->setText(QApplication::translate("AppWindow", "B", Q_NULLPTR));
        quitButton->setText(QApplication::translate("AppWindow", "quit", Q_NULLPTR));
        label->setText(QApplication::translate("AppWindow", "'h': show/hide UI", Q_NULLPTR));
        label_4->setText(QApplication::translate("AppWindow", "cursor keys: rotate / zoom", Q_NULLPTR));
        label_5->setText(QApplication::translate("AppWindow", "Alt + cursor: move light in X/Y", Q_NULLPTR));
        label_7->setText(QApplication::translate("AppWindow", "Alt + Shift + cursor: move light in Z", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppWindow: public Ui_AppWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWINDOW_H
