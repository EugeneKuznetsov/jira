#include "groupsendpoint.h"

GroupsEndpoint::GroupsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : GroupsEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
