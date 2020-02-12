#ifndef STATICDYNAMICLOADER_H
#define STATICDYNAMICLOADER_H

#include <QObject>
#include <QLibrary>
#include <QDebug>

#include "MySignalEmiter.h"
#include "MyDynamicLib.h"

#include "StaticDynamicLoader_global.h"

#define  DYNAMIC_LIB_NAME  "MyDynamicLib.dll"


class STATICDYNAMICLOADER_EXPORT StaticDynamicLoader : public QObject
{
    Q_OBJECT

    Q_PROPERTY( int  value   READ getValue    WRITE setValue  NOTIFY valueChanged    )
    Q_PROPERTY( bool loaded  READ isLoaded                    NOTIFY loadedChanged   )


public:
    StaticDynamicLoader();

    Q_INVOKABLE
    bool    load          (void             );
    Q_INVOKABLE
    void    unload        ( void            );

    bool    isLoaded      ( void            );

    int     getValue      ( void            );
    void    setValue      ( int  val        );

public slots :

    void    init          ( void            );
    void    refreshData   ( void            );

signals:

    void    valueChanged  ( void            );
    void    loadedChanged ( void            );
    void    initChanged   ( void            );
    void    dataRefreshed ( void            );


private:

    // Declare all functionPointer Type
    typedef int                 ( *t_getValue        )( MyDynamicLibHandler        );
    typedef void                ( *t_setValue        )( MyDynamicLibHandler , int  );
    typedef void                ( *t_init            )( MyDynamicLibHandler        );
    typedef void                ( *t_refreshData     )( MyDynamicLibHandler        );
    typedef MySignalEmiter*     ( *t_getSignalEmiter )( MyDynamicLibHandler        );
    typedef MyDynamicLibHandler ( *t_getHandle       )( void                       );

    // Create a pointer for each function we want to resolve from DLL
    t_getValue              f_getValue        ;
    t_setValue              f_setValue        ;
    t_init                  f_init            ;
    t_refreshData           f_refreshData     ;
    t_getSignalEmiter       f_getSignalEmiter ;
    t_getHandle             f_getHandle       ;

    //
    MySignalEmiter*         m_signalEmiter  ;
    MyDynamicLibHandler     m_handle        ;
    bool                    m_loaded        ;
    QLibrary*               m_lib           ;

};

#endif // STATICDYNAMICLOADER_H
