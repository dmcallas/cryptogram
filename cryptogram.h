#ifndef CRYPTOGRAM_H
#define CRYPTOGRAM_H

#include <QChar>
#include <QDialog>
#include <QMap>
#include <QPointer>
#include <QString>
#include <QVector>

#include "cryptogramui.h"

class Cryptogram : public QDialog
{
  Q_OBJECT
    
 public:
  Cryptogram();
  
 private slots:
  void changeKey(QString s);
  void changeCiphertext();
  void changeCaesar(int value);
  void changeKeyphraseCT();
  void changeKeyphrasePT();
  void clear();
  void clearToLower();
  void computeFreq();
  void computeVigenere();
  void guessCaesar();
  void changePlaintext();
 private:
  QVector< QPointer<QLabel> > LabelVect;
  QVector< QPointer<QLineEdit> > EditVect;
  QString Alph;
  QString oldPlaintext;
  bool inChangePlaintext;
  void updatedKey();
  QString removeDupes(QString s);
  Ui::Cryptogram ui;
  QMap<QChar,QChar> key;
  QMap<QChar,QChar> ikey;
  int freq[26];
};

#endif
