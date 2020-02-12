import QtQuick 2.12
import QtQuick.Window 2.12

import DllLoader 1.0
import QtQuick.Controls 2.3

Window {
    visible : true

    width   : 640
    height  : 480
    title   : "Dll Dynamic Loading test"

    DllLoader
    {
        id : dllLoader
    }

    Text {
        id     : loadedLabel
        x      : 41
        y      : 48
        width  : 80
        height : 15
        text   : "Dll loaded : "
    }

    Rectangle {
        id     : loadedIndicator
        x      : 108
        y      : 48
        width  : 13
        height : 15
        color  : dllLoader.loaded ? "green" : "red"
    }

    Button {
        id   : loadButton
        x    : 170
        y    : 32
        text : qsTr("LOAD LIB ")

        enabled : !dllLoader.loaded

        onClicked : dllLoader.load( )
    }

    Button {
        id   : unloadButton
        x    : 309
        y    : 32
        text : qsTr("UNLOAD LIB")

        enabled : dllLoader.loaded

        onClicked: dllLoader.unload()

    }

    Button {
        id        : timerButton
        x         : 31
        y         : 143
        width     : 137
        height    : 48
        text      : checked ? "TIMER ON" : "TIMER OFF"
        checkable : true
        enabled   : dllLoader.loaded

        Timer
        {
            id       : timer
            running  : timerButton.checked
            interval : 100
            repeat   : true

            onTriggered : dllLoader.value ++
        }
    }

    Label {
        id   : valueLabel
        x    : 195
        y    : 159
        text : "My value = "
    }

    Text {
        id      : valueField
        x       : 275
        y       : 161
        width   : 44
        height  : 15
        enabled : dllLoader.loaded
        text    : dllLoader.value
    }

    Button {
        id      : increment
        x       : 31
        y       : 197
        width   : 137
        height  : 48
        enabled : dllLoader.loaded
        text    : "Increment Value"

        onClicked : dllLoader.value = dllLoader.value+1
    }



}
