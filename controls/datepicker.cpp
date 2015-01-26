#include "datepicker.h"

DatePicker::DatePicker(QQuickItem *parent):
    QQuickItem(parent)
{
#if defined(Q_OS_ANDROID)
    nativeControls = AndroidNativeControls::getInstance();
#endif
    connect(nativeControls,SIGNAL(dateSelected(int,int,int)),SLOT(setDate(int,int,int)));
}

DatePicker::~DatePicker()
{
}


QDate DatePicker::date() const
{
    return m_date;
}

void DatePicker::showDatepicker() const
{
    nativeControls->showDatepicker(m_date.year(), m_date.month(), m_date.day());
}

void DatePicker::setDate(QDate newDate)
{
    if (m_date == newDate)
        return;

    m_date = newDate;
    emit dateChanged(newDate);
}

void DatePicker::setDate(int year, int month, int day)
{
    QDate newDate(year, month, day);

    if (m_date == newDate)
        return;

    m_date = newDate;
    emit dateChanged(newDate);
}
