#ifndef NATIVEDATEPICKER_H
#define NATIVEDATEPICKER_H

#include <QQuickItem>
#include <QtQml>
#include <QObject>
#include <QString>
#include <QDate>

#if defined(Q_OS_ANDROID)
#include "native/androidnativecontrols.h"
#endif


class DatePicker : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(DatePicker)

    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)

public:
    DatePicker(QQuickItem *parent = 0);
    ~DatePicker();

    Q_INVOKABLE void showDatepicker() const;
    QDate date() const;

signals:
    void dateChanged(QDate newDate);

public slots:
    void setDate(QDate newDate);
    void setDate(int year, int month, int day);

private:
#if defined(Q_OS_ANDROID)
    AndroidNativeControls *nativeControls;
#endif

    QDate m_date;
};

#endif // NATIVEDATEPICKER_H

