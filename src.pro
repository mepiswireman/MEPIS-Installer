TEMPLATE = app
TARGET = minstall
TRANSLATIONS += minstall_de.ts minstall_es.ts minstall_fr.ts \
           minstall_pt_BR.ts minstall_ca.ts minstall_nl.ts
FORMS += memain.ui meinstall.ui 
HEADERS += mmain.h minstall.h 
SOURCES += app.cpp mmain.cpp minstall.cpp 
LIBS += -lcrypt
CONFIG += release warn_on thread qt
