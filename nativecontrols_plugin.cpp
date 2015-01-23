#include "nativecontrols_plugin.h"
#include "controls/datepicker.h"

#include <qqml.h>

void NativeControlsPlugin::registerTypes(const char *uri)
{
    // @uri org.asgalex
    qmlRegisterType<DatePicker>(uri, 1, 0, "NativeDatePicker");
}


