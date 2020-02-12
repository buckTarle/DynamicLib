#include "MyDynamicLib.h"


// ////////////////////////////////////////////////////////////////////////////
//
//  M Y   D Y N A M I C   L I B
//

MyDynamicLib::MyDynamicLib()
{
    m_myValue_read   = 0;
    m_myValue_write  = 0;

    m_isInit         = false;

    m_mySignalEmiter = new MySignalEmiter;

}

MySignalEmiter* MyDynamicLib::getSignalEmiter()
{
    return m_mySignalEmiter;
}

int MyDynamicLib::getMyValue()
{
    return m_myValue_read;
}

void MyDynamicLib::setMyValue(int val)
{
    m_myValue_write = val;

    if( m_myValue_read != m_myValue_write )
    {
        m_myValue_read = m_myValue_write;
        emit m_mySignalEmiter->emitMyValueChanged();
    }
}

void MyDynamicLib::init()
{
    // Move to thread
    // Create timer to call refreshData ?
    m_isInit = true;
    emit m_mySignalEmiter->emitInitChanged( );
}

void MyDynamicLib::refreshData()
{
    // Refresh value if needed
    if( m_myValue_read != m_myValue_write )
    {
        m_myValue_read = m_myValue_write;
        emit m_mySignalEmiter->emitMyValueChanged( );
    }

    // Signal that Refresh is done
    emit m_mySignalEmiter->emitDataRefreshed( );

}



// ////////////////////////////////////////////////////////////////////////////
//
//  E X P O R T   F U N C T I O N S
//

MyDynamicLibHandler getHandle()
{
    return new MyDynamicLib;
}

int getMyValue(MyDynamicLibHandler handle)
{
    if( handle == nullptr )
    {
        return -1;
    }

    return handle->getMyValue();
}

void setMyValue(MyDynamicLibHandler handle, int n)
{
    if( handle == nullptr )
    {
        return;
    }

    handle->setMyValue( n );
}

void init(MyDynamicLibHandler handle)
{
    if( handle == nullptr )
    {
        return;
    }

    handle->init();
}

void refreshData(MyDynamicLibHandler handle)
{
    if( handle == nullptr )
    {
        return;
    }

    handle->refreshData();
}

MySignalEmiter* getSignalEmiter(MyDynamicLibHandler handle)
{
    if( handle == nullptr )
    {
        return nullptr;
    }

    return handle->getSignalEmiter();
}
