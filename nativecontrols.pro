TEMPLATE = lib
TARGET = NativeControls
QT += qml quick androidextras
CONFIG += qt plugin release

TARGET = $$qtLibraryTarget($$TARGET)

DESTDIR = ./build
MOC_DIR = ./build
OBJECTS_DIR = ./build

uri = org.asgalex

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/native/android

# Input
SOURCES += \
    nativecontrols_plugin.cpp \
    controls/datepicker.cpp \
    native/androidnativecontrols.cpp

HEADERS += \
    nativecontrols_plugin.h \
    controls/datepicker.h \
    native/androidnativecontrols.h

DISTFILES = qmldir \
    native/android/src/org/asgalex/nativecontrols/datepicker/DatePickerFragment.java

qmldir.files = qmldir
qmldir.path = $$[QT_INSTALL_PREFIX]/qml/org/asgalex

libs_target.files = "lib"$$TARGET".so"
libs_target.path = $$[QT_INSTALL_PREFIX]/qml/org/asgalex

java_target.files = native/android/src
java_target.path = $$[QT_INSTALL_PREFIX]/src/android/java


INSTALLS = qmldir libs_target java_target

message($$[INSTALL_ROOT])
