#ifndef ANDROIDEVENTRECEIVER_H
#define ANDROIDEVENTRECEIVER_H

#include <QObject>
#include <QDebug>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QAndroidJniEnvironment>

class AndroidNativeControls : public QObject
{
    Q_OBJECT
public:
    explicit AndroidNativeControls(QObject *parent = 0);
    ~AndroidNativeControls();

    static void getDateFromJava(JNIEnv *env, jobject thiz, int year, int month, int day);
    void registerNativeMethods();

    void showDatepicker(const int &initYear, const int &initMonth, const int &initDay) const;
    static AndroidNativeControls *getInstance();

signals:
    void dateSelected(int year, int month, int date);

public slots:

private:
    static AndroidNativeControls *instance;
};

#endif // ANDROIDEVENTRECEIVER_H
