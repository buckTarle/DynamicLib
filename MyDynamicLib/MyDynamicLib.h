#ifndef MYDYNAMICLIB_H
#define MYDYNAMICLIB_H

#include <QObject>

#include "MyDynamicLib_global.h"
#include "MySignalEmiter.h"


// NOT WORKING HERE ( LINKER ERROR ? )
// MOVED TO ITS OWN STATIC LIB

//class MySignalEmiter : public QObject
//{
//    Q_OBJECT
//public:
//    void    emitMyValueChanged  ( void ){ myValueChanged(); }
//    void    emitInitChanged     ( void ){ initChanged   (); }
//    void    emitDataRefreshed   ( void ){ dataRefreshed (); }
//signals:
//    void    myValueChanged      ( void );
//    void    initChanged         ( void );
//    void    dataRefreshed       ( void );
//};


class MYDYNAMICLIB_EXPORT MyDynamicLib : public QObject
{
    Q_OBJECT
public:
    MyDynamicLib();

    MySignalEmiter* getSignalEmiter ( void );

    int             getMyValue      ( void    );
    void            setMyValue      ( int val );

public slots:
    void            init            ( void    );
    void            refreshData     ( void    );

private :
    int             m_myValue_write;
    int             m_myValue_read;

    bool            m_isInit;

    MySignalEmiter* m_mySignalEmiter;

};


extern "C" {


// Create handle to keep a pointer to an instance of the class MyDynamicLibHandler
typedef MyDynamicLib* MyDynamicLibHandler;

// Function that creates an instance of MyDynamicLibHandler .
MYDYNAMICLIB_EXPORT
MyDynamicLibHandler getHandle   ( void                              );


////////////////////////////////////////////////////////////////////////////////
// Classic C interface.
// These functions can be used with any compiler that knows how to call
// an exported C routine.

MYDYNAMICLIB_EXPORT
int                 getMyValue     ( MyDynamicLibHandler handle          );

MYDYNAMICLIB_EXPORT
void                setMyValue     ( MyDynamicLibHandler handle , int n  );

MYDYNAMICLIB_EXPORT
void                init           ( MyDynamicLibHandler handle          );

MYDYNAMICLIB_EXPORT
void                refreshData    ( MyDynamicLibHandler handle          );

MYDYNAMICLIB_EXPORT
MySignalEmiter*     getSignalEmiter( MyDynamicLibHandler handle          );



////////////////////////////////////////////////////////////////////////////////

} // End extern "C"

#endif // MYDYNAMICLIB_H
