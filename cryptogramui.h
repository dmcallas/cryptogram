#ifndef CRYPTOGRAM_UI_H
#define CRYPTOGRAM_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Cryptogram
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEditCT;
    QPlainTextEdit *plainTextEditPT;
    QGridLayout *gridLayout;
    QLabel *keyLabel[26];
    QLineEdit *keyEdit[26];
    QLabel *label_ptcode;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonFreq;
    QPushButton *pushButtonClearLetters;
    QPushButton *pushButtonClearToLower;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonKeyCT;
    QPushButton *pushButtonKeyPT;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_27;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonVigenere;
    QLineEdit *lineEdit_29;
    QCheckBox *checkBoxAutoKey;
    QCheckBox *checkBoxBeaufort;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCaesar;
    QSpinBox *spinBox;
    QPushButton *pushButtonGuess;

    void setupUi(QDialog *Cryptogram)
    {
        if (Cryptogram->objectName().isEmpty())
            Cryptogram->setObjectName(QString::fromUtf8("Cryptogram"));
        Cryptogram->resize(728, 535);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cryptogram->sizePolicy().hasHeightForWidth());
        Cryptogram->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(Cryptogram);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        plainTextEditCT = new QPlainTextEdit(Cryptogram);
        plainTextEditCT->setObjectName(QString::fromUtf8("plainTextEditCT"));
        sizePolicy.setHeightForWidth(plainTextEditCT->sizePolicy().hasHeightForWidth());
        plainTextEditCT->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier [unknown]"));
        plainTextEditCT->setFont(font);

        gridLayout_4->addWidget(plainTextEditCT, 0, 0, 1, 3);

        plainTextEditPT = new QPlainTextEdit(Cryptogram);
        plainTextEditPT->setObjectName(QString::fromUtf8("plainTextEditPT"));
        sizePolicy.setHeightForWidth(plainTextEditPT->sizePolicy().hasHeightForWidth());
        plainTextEditPT->setSizePolicy(sizePolicy);
        plainTextEditPT->setFont(font);

        gridLayout_4->addWidget(plainTextEditPT, 1, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

	for(int i=0;i<26;i++){
	  keyLabel[i] = new QLabel(Cryptogram);
	  keyLabel[i]->setObjectName(QString::fromUtf8("keyLabel%1").arg(i));
	  keyLabel[i]->setFont(font);
	  keyLabel[i]->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	  
	  gridLayout->addWidget(keyLabel[i], i/8, (2*i)%16);
	  
	  keyEdit[i] = new QLineEdit(Cryptogram);
	  keyEdit[i]->setObjectName(QString::fromUtf8("keyEdit%1").arg(i));
	  keyEdit[i]->setMaxLength(1);
	  
	  gridLayout->addWidget(keyEdit[i], i/8, (2*i+1)%16);
	}

        gridLayout_4->addLayout(gridLayout, 2, 0, 1, 3);

        label_ptcode = new QLabel(Cryptogram);
        label_ptcode->setObjectName(QString::fromUtf8("label_ptcode"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_ptcode->sizePolicy().hasHeightForWidth());
        label_ptcode->setSizePolicy(sizePolicy1);
        label_ptcode->setFont(font);
        label_ptcode->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_ptcode, 3, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButtonFreq = new QPushButton(Cryptogram);
        pushButtonFreq->setObjectName(QString::fromUtf8("pushButtonFreq"));

        verticalLayout->addWidget(pushButtonFreq);

        pushButtonClearLetters = new QPushButton(Cryptogram);
        pushButtonClearLetters->setObjectName(QString::fromUtf8("pushButtonClearLetters"));

        verticalLayout->addWidget(pushButtonClearLetters);

        pushButtonClearToLower = new QPushButton(Cryptogram);
        pushButtonClearToLower->setObjectName(QString::fromUtf8("pushButtonClearToLower"));

        verticalLayout->addWidget(pushButtonClearToLower);


        gridLayout_4->addLayout(verticalLayout, 4, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButtonKeyCT = new QPushButton(Cryptogram);
        pushButtonKeyCT->setObjectName(QString::fromUtf8("pushButtonKeyCT"));

        gridLayout_2->addWidget(pushButtonKeyCT, 0, 0, 1, 1);

        pushButtonKeyPT = new QPushButton(Cryptogram);
        pushButtonKeyPT->setObjectName(QString::fromUtf8("pushButtonKeyPT"));

        gridLayout_2->addWidget(pushButtonKeyPT, 1, 0, 1, 1);

        lineEdit_28 = new QLineEdit(Cryptogram);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));

        gridLayout_2->addWidget(lineEdit_28, 1, 1, 1, 1);

        lineEdit_27 = new QLineEdit(Cryptogram);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));

        gridLayout_2->addWidget(lineEdit_27, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 4, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButtonVigenere = new QPushButton(Cryptogram);
        pushButtonVigenere->setObjectName(QString::fromUtf8("pushButtonVigenere"));

        gridLayout_3->addWidget(pushButtonVigenere, 0, 0, 1, 1);

        lineEdit_29 = new QLineEdit(Cryptogram);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));

        gridLayout_3->addWidget(lineEdit_29, 0, 1, 1, 2);

        checkBoxAutoKey = new QCheckBox(Cryptogram);
        checkBoxAutoKey->setObjectName(QString::fromUtf8("checkBoxAutoKey"));

        gridLayout_3->addWidget(checkBoxAutoKey, 1, 0, 1, 1);

        checkBoxBeaufort = new QCheckBox(Cryptogram);
        checkBoxBeaufort->setObjectName(QString::fromUtf8("checkBoxBeaufort"));

        gridLayout_3->addWidget(checkBoxBeaufort, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 4, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelCaesar = new QLabel(Cryptogram);
        labelCaesar->setObjectName(QString::fromUtf8("labelCaesar"));
        labelCaesar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelCaesar);

        spinBox = new QSpinBox(Cryptogram);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox->setMinimum(-1);
        spinBox->setMaximum(26);

        horizontalLayout->addWidget(spinBox);

        pushButtonGuess = new QPushButton(Cryptogram);
        pushButtonGuess->setObjectName(QString::fromUtf8("pushButtonGuess"));

        horizontalLayout->addWidget(pushButtonGuess);


        gridLayout_4->addLayout(horizontalLayout, 5, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
	for(int i=0;i<26;i++){
	  keyLabel[i]->setBuddy(keyEdit[i]);
	}
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(plainTextEditCT, plainTextEditPT);
        QWidget::setTabOrder(plainTextEditPT, keyEdit[0]);
	for(int i=0;i<25;i++){
	  QWidget::setTabOrder(keyEdit[i], keyEdit[i+1]);
	}
        QWidget::setTabOrder(keyEdit[25], pushButtonFreq);
        QWidget::setTabOrder(pushButtonFreq, pushButtonClearLetters);
        QWidget::setTabOrder(pushButtonClearLetters, pushButtonClearToLower);
        QWidget::setTabOrder(pushButtonClearToLower, pushButtonKeyCT);
        QWidget::setTabOrder(pushButtonKeyCT, lineEdit_27);
        QWidget::setTabOrder(lineEdit_27, pushButtonKeyPT);
        QWidget::setTabOrder(pushButtonKeyPT, lineEdit_28);
        QWidget::setTabOrder(lineEdit_28, spinBox);
        QWidget::setTabOrder(spinBox, pushButtonGuess);
        QWidget::setTabOrder(pushButtonGuess, pushButtonVigenere);
        QWidget::setTabOrder(pushButtonVigenere, lineEdit_29);
        QWidget::setTabOrder(lineEdit_29, checkBoxAutoKey);
        QWidget::setTabOrder(checkBoxAutoKey, checkBoxBeaufort);

        retranslateUi(Cryptogram);

        QMetaObject::connectSlotsByName(Cryptogram);
    } // setupUi

    void retranslateUi(QDialog *Cryptogram)
    {
        Cryptogram->setWindowTitle(QApplication::translate("Cryptogram", "Cryptogram", 0, QApplication::UnicodeUTF8));
	for(int i=0;i<26;i++){
	  keyLabel[i]->setText(QApplication::translate("Cryptogram", "A (00)", 0, QApplication::UnicodeUTF8));
	}
        label_ptcode->setText(QApplication::translate("Cryptogram", "PLAIN: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n"
" CODE: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z", 0, QApplication::UnicodeUTF8));
        pushButtonFreq->setText(QApplication::translate("Cryptogram", "Compute Frequencies", 0, QApplication::UnicodeUTF8));
        pushButtonClearLetters->setText(QApplication::translate("Cryptogram", "Clear Letters", 0, QApplication::UnicodeUTF8));
        pushButtonClearToLower->setText(QApplication::translate("Cryptogram", "Clear To Lowercase", 0, QApplication::UnicodeUTF8));
        pushButtonKeyCT->setText(QApplication::translate("Cryptogram", "Key (CT):", 0, QApplication::UnicodeUTF8));
        pushButtonKeyPT->setText(QApplication::translate("Cryptogram", "Key (PT):", 0, QApplication::UnicodeUTF8));
        pushButtonVigenere->setText(QApplication::translate("Cryptogram", "Vigenere Key:", 0, QApplication::UnicodeUTF8));
        checkBoxAutoKey->setText(QApplication::translate("Cryptogram", "Auto Key", 0, QApplication::UnicodeUTF8));
        checkBoxBeaufort->setText(QApplication::translate("Cryptogram", "Beaufort", 0, QApplication::UnicodeUTF8));
        labelCaesar->setText(QApplication::translate("Cryptogram", "Caesar:", 0, QApplication::UnicodeUTF8));
        pushButtonGuess->setText(QApplication::translate("Cryptogram", "Guess", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Cryptogram: public Ui_Cryptogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPTOGRAM_H
