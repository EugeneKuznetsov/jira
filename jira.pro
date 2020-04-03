TEMPLATE = subdirs

SUBDIRS = plugin examples tests

examples.depends = plugin
tests.depends = plugin
