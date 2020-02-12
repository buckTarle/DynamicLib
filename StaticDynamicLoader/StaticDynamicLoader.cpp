#include "StaticDynamicLoader.h"

StaticDynamicLoader::StaticDynamicLoader()
{
    m_loaded  = false;
}

bool StaticDynamicLoader::load( void )
{
    // cannot load if already loaded
    if( m_loaded ) return false;


    // //////////////////////////////////////////////////////
    // LOAD LIBRARY BY ITS NAME

    m_lib          = new QLibrary( DYNAMIC_LIB_NAME );

    bool loadOK    = m_lib->load();

    if( !loadOK )
    {
        qCritical() << "fail to load " << DYNAMIC_LIB_NAME;
        return false;
    }

    // //////////////////////////////////////////////////////
    // RESOVLE FUNCTION FROM DLL

    f_getHandle         = (t_getHandle)       m_lib->resolve( "getHandle"       );
    f_getValue          = (t_getValue)        m_lib->resolve( "getMyValue"      );
    f_setValue          = (t_setValue)        m_lib->resolve( "setMyValue"      );
    f_init              = (t_init)            m_lib->resolve( "init"            );
    f_getSignalEmiter   = (t_getSignalEmiter) m_lib->resolve( "getSignalEmiter" );

    // //////////////////////////////////////////////////////
    // VERIFY FUNCTION POINTER

    if( f_getHandle       == nullptr ) { qCritical() << "fail to resole 'getHandle'"       ; return false; }
    if( f_getValue        == nullptr ) { qCritical() << "fail to resole 'getValue'"        ; return false; }
    if( f_setValue        == nullptr ) { qCritical() << "fail to resole 'setValue'"        ; return false; }
    if( f_init            == nullptr ) { qCritical() << "fail to resole 'init'"            ; return false; }
    if( f_getSignalEmiter == nullptr ) { qCritical() << "fail to resole 'getSignalEmiter'" ; return false; }

    // Create handle
    m_handle       = f_getHandle();

    // Retrive signal Emiter
    m_signalEmiter = f_getSignalEmiter( m_handle );


    // //////////////////////////////////////////////////////
    // CONNECT POINTER FROM SIGNAL_EMITER TO DYNAMIC_LOADER

    QObject::connect( m_signalEmiter                      ,
                      &MySignalEmiter::myValueChanged     ,
                      this                                ,
                      &StaticDynamicLoader::valueChanged  );

    QObject::connect( m_signalEmiter                      ,
                      &MySignalEmiter::initChanged        ,
                      this                                ,
                      &StaticDynamicLoader::initChanged   );

    QObject::connect( m_signalEmiter                      ,
                      &MySignalEmiter::dataRefreshed      ,
                      this                                ,
                      &StaticDynamicLoader::dataRefreshed );


    // //////////////////////////////////////////////////////
    // LOADING IS OK

    m_loaded = true;

    emit loadedChanged();

    return m_loaded;
}

void StaticDynamicLoader::unload()
{
    if( m_handle) delete m_handle;

    m_loaded = false;
    m_handle = nullptr;

    emit loadedChanged();
}

bool StaticDynamicLoader::isLoaded()
{
    return m_loaded;
}

int StaticDynamicLoader::getValue()
{
    if( !m_loaded || !m_handle )
    {
        return -1;
    }

    return f_getValue( m_handle );

}

void StaticDynamicLoader::setValue(int val)
{
    if( !m_loaded || !m_handle )
    {
        return;
    }

    f_setValue( m_handle , val );

}

void StaticDynamicLoader::init()
{
    if( !m_loaded || !m_handle )
    {
        return;
    }

    f_init( m_handle );
}

void StaticDynamicLoader::refreshData()
{
    if( !m_loaded || !m_handle )
    {
        return;
    }

    f_refreshData( m_handle );
}
