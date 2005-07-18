TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

win32:LIBS	+= qt-mt332.lib qtmain.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib winspool.lib delayimp.lib opengl32.lib glu32.lib glew32.lib
DEFINES	+= QT_NO_DEBUG _WINDOWS UNICODE WIN32 QT_DLL QT_THREAD_SUPPORT _TORUS01 _EXTENDED_MARCH1
win32:DEFINES	+= QT_NO_DEBUG _WINDOWS UNICODE WIN32 QT_DLL QT_THREAD_SUPPORT _TORUS01 _EXTENDED_MARCH1
win32:INCLUDEPATH	+= "$(QTDIR)\include" . "C:\Qt\3.3.2\mkspecs\win32-msvc.net" D:\sf\apps\test\segmentation3d D:\sf

HEADERS	+= simpleglwidget.h
SOURCES	+= D:/sf/wrap/gui/trackmode.cpp \
	D:/sf/wrap/gui/trackball.cpp \
	D:/sf/wrap/ply/plylib.cpp \
	simpleglwidget.cpp \
	main.cpp
FORMS	= segmentform.ui \
	d:\sf\apps\test\segmentation3d\segmentform.ui











































































































































































































































































unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}


