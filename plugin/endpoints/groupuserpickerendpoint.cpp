#include "groupuserpickerendpoint.h"

GroupUserPickerEndpoint::GroupUserPickerEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : GroupUserPickerEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
