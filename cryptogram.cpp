#include <QChar>
#include <QDialog>
#include <QMap>
#include <QString>
#include "cryptogram.h"

Cryptogram::Cryptogram(){
  Alph=QString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  int i=0;
  for(i=0;i<26;i++){
    key[Alph.at(i)]='_';
  }
  ui.setupUi(this);
  ui.plainTextEditPT->setOverwriteMode(true);
  inChangePlaintext=false;
  connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeCaesar(int)));
  connect(ui.pushButtonKeyPT,SIGNAL(clicked()),this,SLOT(changeKeyphrasePT()));
  connect(ui.pushButtonKeyCT,SIGNAL(clicked()),this,SLOT(changeKeyphraseCT()));
  connect(ui.plainTextEditCT,SIGNAL(textChanged()),this,SLOT(changeCiphertext()));
  connect(ui.pushButtonClearLetters,SIGNAL(clicked()),this,SLOT(clear()));
  connect(ui.pushButtonClearToLower,SIGNAL(clicked()),this,SLOT(clearToLower()));
  connect(ui.pushButtonFreq,SIGNAL(clicked()),this,SLOT(computeFreq()));
  connect(ui.pushButtonVigenere,SIGNAL(clicked()),this,SLOT(computeVigenere()));
  connect(ui.pushButtonGuess,SIGNAL(clicked()),this,SLOT(guessCaesar()));
  connect(ui.plainTextEditPT,SIGNAL(cursorPositionChanged()),this,SLOT(changePlaintext()));
  computeFreq();
  for(i=0;i<25;i++){
    connect(ui.keyEdit[i],SIGNAL(textEdited(QString)),this,SLOT(changeKey(QString)));
  }
  for(i=0;i<25;i++){
    key[Alph[i]]='_';
  }
}
  
void Cryptogram::changeKey(QString s)
{
  QMap<QChar,QChar> tempkey;
  QString templetter;
  int temp=0;
  for(int i=0;i<26;i++){
    templetter=ui.keyEdit[i]->text();
    tempkey[Alph.at(i)]=templetter.at(0);
  }
  temp=0;
  for(int i=0;i<26;i++){
    if(key[Alph.at(i)]!=tempkey[Alph.at(i)]){
      temp=1;
    }
  }
  if(temp==1){
    for(int i=0;i<26;i++){
      if((tempkey[Alph.at(i)].isNull()))
	key[Alph.at(i)]='_';
      else
	key[Alph.at(i)]=tempkey[Alph.at(i)];      
    }
    updatedKey();
  }
}

void Cryptogram::changeCiphertext()
{
  updatedKey();
}

void Cryptogram::changeCaesar(int value)
{
  int caesarValue=value;
  if(caesarValue==-1){
    caesarValue=25;
    ui.spinBox->setValue(25);
  }
  if(caesarValue==26){
    caesarValue=0;
    ui.spinBox->setValue(0);
  }
  for(int i=0;i<26;i++){
    key[Alph.at((i+caesarValue)%26)]=Alph.at(i);
  }
  updatedKey();
}

void Cryptogram::changeKeyphraseCT()
{  
  QString keyphrase;
  int temp;
  keyphrase=ui.lineEdit_27->text();
  keyphrase.append(Alph);
  keyphrase=keyphrase.toUpper();
  for(int i=0;i<keyphrase.length();i++){
    while(keyphrase.indexOf(keyphrase.at(i),i+1)!=-1){
      temp=keyphrase.indexOf(keyphrase.at(i),i+1);
      keyphrase.remove(temp,1);
    }
  }
  for(int i=0;i<26;i++){
    key[keyphrase.at(i)]=Alph.at(i);
  }
  updatedKey();
}

void Cryptogram::changeKeyphrasePT()
{
  QString keyphrase;
  keyphrase=ui.lineEdit_28->text();
  keyphrase.append(Alph);
  keyphrase=keyphrase.toUpper();
  keyphrase=removeDupes(keyphrase);
  for(int i=0;i<26;i++){
    key[Alph.at(i)]=keyphrase.at(i);
  }
  updatedKey();
}

void Cryptogram::updatedKey()
{
  QString LabelText("PLAIN: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n  CODE: " );
  QString Plaintext("");
  QString Ciphertext;
  QString::const_iterator stringIter;
  
  Ciphertext=ui.plainTextEditCT->toPlainText();
  for(int i=0;i<26;i++){
    ikey[Alph.at(i)]=' ';
  }
  for(int i=0;i<26;i++){
    ikey[key[Alph.at(i)]]=Alph.at(i);
  }
  for(int i=0;i<26;i++){
    if(key[Alph.at(i)]=='_'||key[Alph.at(i)]==' ')
      ui.keyEdit[i]->setText("");
    else
      ui.keyEdit[i]->setText(key[Alph.at(i)]);
  }
  for(int i=0;i<26;i++){
    LabelText.append(ikey[Alph.at(i)]);
    LabelText.append(" ");
  }
  ui.label_ptcode->setText(LabelText);
  Ciphertext=Ciphertext.toUpper();
  for(stringIter=Ciphertext.begin();stringIter<Ciphertext.end();stringIter++){
    if(stringIter->isLetter())
      Plaintext.append(key[*stringIter]);
    else
      Plaintext.append(*stringIter);
  }
  ui.plainTextEditPT->setPlainText(Plaintext);  
  oldPlaintext=Plaintext;
}

QString Cryptogram::removeDupes(QString s)
{
  QString t(s);
  int temp;
  for(int i=0;i<t.length();i++){
    while(t.indexOf(t.at(i),i+1)!=-1){
      temp=t.indexOf(t.at(i),i+1);
      t.remove(temp,1);
    }
  }
  return t;
}

void Cryptogram::clear(){
  for(int i=0;i<26;i++){
    key[Alph.at(i)]=' ';
  }
  updatedKey();
}

void Cryptogram::clearToLower(){
  QString Lower(Alph.toLower());
  for(int i=0;i<26;i++){
    key[Alph.at(i)]=Lower.at(i);
  }
  updatedKey();
  
}

void Cryptogram::computeFreq(){
  QString Ciphertext;
  QString LabelText[26];
  int index;
  Ciphertext=ui.plainTextEditCT->toPlainText();
  Ciphertext=Ciphertext.toUpper();
  for(int i=0;i<26;i++)
    freq[i]=0;
  for(QString::const_iterator i=Ciphertext.begin();i!=Ciphertext.end();++i){
    if(i->isLetter()){
      index=(i->toAscii())-'A';
      freq[index]++;
    }
  }
  for(int i=0;i<26;i++){
    LabelText[i].setNum(freq[i]);
    LabelText[i].append(")");
    LabelText[i].prepend("(");
    LabelText[i].prepend(Alph.at(i));
  }
  for(int i=0;i<26;i++){
    ui.keyLabel[i]->setText(LabelText[i]);
  }
}

void Cryptogram::computeVigenere()
{
  bool autoKey,beaufort;
  QString vKey,Ciphertext,Plaintext("");  
  int c,k,r;
  autoKey=ui.checkBoxAutoKey->isChecked();
  beaufort=ui.checkBoxBeaufort->isChecked();
  Ciphertext=ui.plainTextEditCT->toPlainText();
  vKey=ui.lineEdit_29->text();
  if(autoKey){
    for(int i=0;i<Ciphertext.length();i++){
      if((!Ciphertext.at(i).isLetter()) || Ciphertext.at(i).isSpace()){
	Ciphertext.remove(i,1);
	i--;
      }
    }
  }
  vKey=vKey.toUpper();
  Ciphertext=Ciphertext.toUpper();
  if(!autoKey){
    while(vKey.length()<Ciphertext.length()){
      vKey.append(vKey);
    }
  }
  for(int i=0;i<Ciphertext.length();i++){
    if(Ciphertext.at(i).isLetter()){
      c=Ciphertext.at(i).toAscii()-'A';
      k=vKey.at(i).toAscii()-'A';
      if(beaufort)
	r=c+k+26;
      else
	r=c-k+26;
      r%=26;
      Plaintext.append(Alph.at(r));
      if(autoKey){vKey.append(Alph.at(r));}    
    }
    else
      Plaintext.append(Ciphertext.at(i));
  }
  ui.plainTextEditPT->setPlainText(Plaintext);
}

void Cryptogram::guessCaesar()
{
  computeFreq();
  double conv[26],f,e;
  // Expected valued taken from Military Cryptanalytics, which cites Hitt.
  int expected[26]={778,141,296,402,1277,197,174,595,667,51,74,372,288,686,807,233,8,651,622,855,308,112,176,27,196,17};
  int max;  
  for(int i=0;i<26;i++){
    conv[i]=0.0;
    for(int j=0;j<26;j++){
      f=freq[(i+j)%26];
      e=expected[j];
      conv[i]+=e*f;
    }
  }
  max=0;
  for(int i=1;i<26;i++){
    if(conv[i]>conv[max])
      max=i;
  }
  ui.spinBox->setValue((max+1)%26); //Jog the box so that the
				    //plaintext will update even if
				    //the spinbox value does not
				    //change.
  ui.spinBox->setValue(max);
}

void Cryptogram::changePlaintext()
{
  if(inChangePlaintext){
    return;
  }
  inChangePlaintext=true;
  QString pt,ct,newpt;
  QTextCursor loc;
  int pos;
  bool dec=false;
  pt=ui.plainTextEditPT->toPlainText();
  ct=ui.plainTextEditCT->toPlainText();
  loc=ui.plainTextEditPT->textCursor();
  pos=loc.position();
  pos--;
  if(pos<0){pos=0;dec=true;}
  if(ct.at(pos).isLetter()){
    ui.keyEdit[ct.at(pos).toUpper().toAscii()-'A']->setText(pt.at(pos));
    key[ct.at(pos).toUpper()]=pt.at(pos);
    updatedKey();
  }
  if (dec)
    loc.setPosition(pos);
  else
    loc.setPosition(pos+1);  
  ui.plainTextEditPT->setTextCursor(loc);
  inChangePlaintext=false;
}
