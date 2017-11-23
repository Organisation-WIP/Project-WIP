/********************************************************************************
** Form generated from reading UI file 'dockwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKWIDGET_H
#define UI_DOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FPSWidget
{
public:
    QWidget *dockWidgetContents;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QDockWidget *FPSWidget)
    {
        if (FPSWidget->objectName().isEmpty())
            FPSWidget->setObjectName(QStringLiteral("FPSWidget"));
        FPSWidget->resize(200, 100);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FPSWidget->sizePolicy().hasHeightForWidth());
        FPSWidget->setSizePolicy(sizePolicy);
        FPSWidget->setMinimumSize(QSize(200, 100));
        FPSWidget->setBaseSize(QSize(200, 100));
        FPSWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        layoutWidget = new QWidget(dockWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 171, 31));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lcdNumber);

        FPSWidget->setWidget(dockWidgetContents);

        retranslateUi(FPSWidget);

        QMetaObject::connectSlotsByName(FPSWidget);
    } // setupUi

    void retranslateUi(QDockWidget *FPSWidget)
    {
        FPSWidget->setWindowTitle(QApplication::translate("FPSWidget", "FPS", Q_NULLPTR));
        label->setText(QApplication::translate("FPSWidget", "Aktuelle FPS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FPSWidget: public Ui_FPSWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKWIDGET_H
