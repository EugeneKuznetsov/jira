#include "statuscategoryendpoint.h"

StatusCategoryEndpoint::StatusCategoryEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : StatusCategoryEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
