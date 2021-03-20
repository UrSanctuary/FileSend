import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

import ClientList 1.0
import FileList 1.0

ApplicationWindow {
    visible: true
    title: qsTr("FileStorage")
    width: Screen.width * 1 / 2
    height: Screen.height * 1 / 2

    ClientList {
        id: client_list
    }

    FileList {
        id: file_list
    }

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: qsTr("Create fake client")
                onClicked: {

                }
            }
        }
    }

    RowLayout
    {
        anchors.fill: parent
        ListView {
            id: client_list_view
            model: client_list
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width / 5

            ScrollBar.vertical: ScrollBar {}

            delegate: Item {
                implicitHeight: 16
                width: parent !== null ? parent.width : 0
                Rectangle {
                    color: {
                        if (client_list_view.currentIndex === index)
                        {
                            return "lightblue"
                        }
                        return index % 2 === 0 ? "ghostwhite" : "lightcyan"
                    }
                    anchors.fill: parent
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: display
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        client_list_view.currentIndex = index
                    }
                }
            }
            focus: true
            onCurrentIndexChanged: { console.log('client item ' + currentIndex + ' selected') }
        }

        ToolSeparator {
            Layout.fillHeight: true
        }

        ListView {
            id: file_list_view
            model: file_list
            Layout.fillHeight: true
            Layout.fillWidth: true

            ScrollBar.vertical: ScrollBar {}

            delegate: Item {
                implicitHeight: 20
                width: parent !== null ? parent.width : 0
                Rectangle {
                    color: {
                        if (file_list_view.currentIndex === index)
                        {
                            return "lightblue"
                        }
                        return index % 2 === 0 ? "ghostwhite" : "lightcyan"
                    }
                    height: parent.height
                    width: parent.width
                    Rectangle {
                        color: "aquamarine"
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.height * 0.7
                        width: parent.width * file_list.file_progress(index) / 100
                    }
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: display
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        file_list_view.currentIndex = index
                    }
                }
            }
            focus: true
            onCurrentIndexChanged: { console.log('file item ' + currentIndex + ' selected') }
        }
    }
}
