#ifndef MYSIGNALEMITER_GLOBAL_H
#define MYSIGNALEMITER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYSIGNALEMITER_LIBRARY)
#  define MYSIGNALEMITER_EXPORT Q_DECL_EXPORT
#else
#  define MYSIGNALEMITER_EXPORT Q_DECL_IMPORT
#endif

#endif // MYSIGNALEMITER_GLOBAL_H
