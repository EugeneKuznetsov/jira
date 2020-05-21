#include "issuesecurityschemesendpoint.h"

IssueSecuritySchemesEndpoint::IssueSecuritySchemesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueSecuritySchemesEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
