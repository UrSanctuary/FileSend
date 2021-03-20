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
                    width: parent.width
                    Rectangle {
                        color: index % 2 === 0 ? "lightgrey" : "white"
                        anchors.fill: parent
                    }
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        text: display
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log('index = ' + index)
                            client_list_view.currentIndex = index
                        }
                    }
            }
            focus: true
            onCurrentIndexChanged: { console.log('item ' + currentIndex + ' selected') }
        }

        ToolSeparator {
            Layout.fillHeight: true
        }

        ListView {
            id: file_list_view
            model: file_list
            Layout.fillWidth: true
            Layout.fillHeight: true

            delegate: Rectangle {
                implicitHeight: 16
                z: 1
                color: index % 2 === 0 ? "lightgrey" : "white"
                width: parent.width
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: display
                }
            }

            ScrollBar.vertical: ScrollBar {}
        }
    }
}
