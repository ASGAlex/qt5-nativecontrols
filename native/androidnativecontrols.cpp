#include "native/androidnativecontrols.h"

AndroidNativeControls* AndroidNativeControls::instance = NULL;

AndroidNativeControls::AndroidNativeControls(QObject *parent) : QObject(parent)
{
    registerNativeMethods();
}

AndroidNativeControls::~AndroidNativeControls()
{
}

void AndroidNativeControls::getDateFromJava(JNIEnv *env, jobject thiz, int year, int month, int day)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)

    AndroidNativeControls::instance->dateSelected(year, month+1, day);
}

void AndroidNativeControls::registerNativeMethods()
{
    JNINativeMethod methods[] {{"sendDateToQt", "(III)V", reinterpret_cast<void *>(getDateFromJava)}};

    QAndroidJniObject javaClass("org/asgalex/nativecontrols/datepicker/DatePickerFragment");
    QAndroidJniEnvironment env;

    jobject obj = javaClass.object<jobject>();
    jclass objectClass = env->GetObjectClass(obj);

    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
}

void AndroidNativeControls::showDatepicker(const int &initYear, const int &initMonth, const int &initDay) const
{
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    QAndroidJniObject fragmentManager = activity.callObjectMethod("getFragmentManager","()Landroid/app/FragmentManager;");
    QAndroidJniObject::callStaticMethod<void>("org/asgalex/nativecontrols/datepicker/DatePickerFragment",
                                       "showMe",
                                       "(Landroid/app/FragmentManager;III)V",
                                       fragmentManager.object<jobject>(), initYear, initMonth-1, initDay);
}

AndroidNativeControls *AndroidNativeControls::getInstance()
{
    AndroidNativeControls::instance = new AndroidNativeControls();
    return AndroidNativeControls::instance;
}



