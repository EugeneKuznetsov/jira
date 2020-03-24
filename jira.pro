TEMPLATE = subdirs

SUBDIRS = plugin cpptests qmltests

cpptests.depends = plugin
qmltests.depends = plugin
