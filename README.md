# qt5-nativecontrols
Native controls for mobile QT5+QML applications

Now supports only Android, contains only datepicker.

# Installation

Compile it as ordinary qt5 project in QtCreator.
To install, run ```make install```. On windows, QtCreator execute ```make install``` with INSTALL_PREFIX, witch brokes installation path. So, you should run ```make install``` manually from console.

Installation successed, if you see libNativeControls.so in new $QTDIR\5.4\android_armv7\qml\org\asgalex directory. Also, $QTDIR\5.4\android_armv7\src\android\java\src\org\asgalex directory with .java files should exists

#Usage

If you install library by ```make install```, you only need to write ```import org.asgalex 1.0``` in ypur QML file. The use NativeDatePicker object, for example:
```
  MouseArea {
    anchors.fill: parent
    onClicked: {
        datePicker.showDatepicker()
    }
}
NativeDatePicker {
    id: datePicker
    date: new Date()
}
```

If you dont want to install library into the $QTDIR, you could include it directly in your project:
