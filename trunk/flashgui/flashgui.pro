######################################################################
# Automatically generated by qmake (2.00a) lun 4. sep 12:15:29 2006
######################################################################

TEMPLATE = app
TARGET = FlashGUI
TARGET +=
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += Dialog.h
SOURCES += Dialog.cpp main.cpp

# Options
macx {
	QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
	TARGET = ../bin/FlashPhotography
	CONFIG+=x86 ppc
	ICON = ../bin/monkey.icns
} 


# Translations
TRANSLATIONS = dialog_es_ES.ts \
	dialog_fr.ts \
	dialog_de.ts
