#include "cryptogram.h"
#include <QObject>

int main(int argc, char **argv)
{
  QApplication app(argc,argv);
  Cryptogram c;
  c.show();
  return app.exec();
}
