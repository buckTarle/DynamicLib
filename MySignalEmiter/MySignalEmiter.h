#ifndef MYSIGNALEMITER_H
#define MYSIGNALEMITER_H

#include <QObject>

#include "MySignalEmiter_global.h"

class MYSIGNALEMITER_EXPORT MySignalEmiter : public QObject
{
    Q_OBJECT
public:
    //MySignalEmiter();
    void    emitMyValueChanged  ( void ){ myValueChanged() ; }
    void    emitInitChanged     ( void ){ initChanged   () ; }
    void    emitDataRefreshed   ( void ){ dataRefreshed () ; }

signals:
    void    myValueChanged      ( void );
    void    initChanged         ( void );
    void    dataRefreshed       ( void );
};


#endif // MYSIGNALEMITER_H
