//
//   Copyright (C) 2003-2009 by Warren Woodford
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#include <qapplication.h>
#include <qfont.h>
#include <qstring.h>
#include <qlocale.h>
#include <qtranslator.h>
#include <qmessagebox.h>
#include <unistd.h>
#include <qfile.h>

#include "mmain.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setWindowIcon(QIcon("/usr/share/icons/mconfig.png"));

  QTranslator qtTran;
  qtTran.load(QString("qt_") + QLocale::system().name());
  a.installTranslator(&qtTran);

  QTranslator appTran;
  appTran.load(QString("minstall_") + QLocale::system().name(), "/usr/share/mepis-install/locale");
  a.installTranslator(&appTran);

  if (getuid() == 0) {
    MMain mmain;
    mmain.show();
    return a.exec();
  } else {
    QApplication::beep();
    QMessageBox::critical(0, QString::null,
      QApplication::tr("You must run this app as root."));
    return 1;
  }
}


