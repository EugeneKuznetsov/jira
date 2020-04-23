#pragma once

#ifdef EXPORT_IMPORT_MAGIC
    #define SHARED_SYMBOL   Q_DECL_EXPORT
#else
    #define SHARED_SYMBOL   Q_DECL_IMPORT
#endif
