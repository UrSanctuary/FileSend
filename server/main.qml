import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import FileStorage 1.0
import ClientList 1.0
import FileList 1.0

ApplicationWindow {
    visible: true
    title: qsTr("FileStorage")
    width: Screen.width / 2
    height: Screen.height / 2
    id: main_window

    FileStorage {
        id: file_storage
    }

    ClientList {
        id: client_list
        storage: file_storage
    }

    FileList {
        id: file_list
        storage: file_storage
    }

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: qsTr("Create fake client")
                onClicked: {
                    client_list.create_fake_client()
                }
            }
        }
    }

    SplitView
    {
        anchors.fill: parent
        ListView {
            id: client_list_view
            model: client_list
            Layout.fillHeight: true
            SplitView.preferredWidth: parent.width / 5
            SplitView.minimumWidth: 100
            currentIndex: -1

            ScrollBar.vertical: ScrollBar {}

            delegate: Item {
                implicitHeight: 16
                width: parent !== null ? parent.width : 0
                Rectangle {
                    color: {
                        if (client_list_view.currentIndex === index)
                        {
                            return "deepskyblue"
                        }
                        return index % 2 === 0 ? "whitesmoke" : "white"
                    }
                    anchors.fill: parent
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: display
                }

                Rectangle {
                    width: parent !== null ? parent.height * 0.8 : 0
                    height: width
                    radius: width * 0.5
                    x: parent.width - width - 10
                    anchors.verticalCenter: parent.verticalCenter
                    color: file_storage.is_client_online(index) ? "lightgreen" : "red"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        client_list_view.currentIndex = index
                    }
                }
            }
            focus: true
            onCurrentIndexChanged: {
                file_storage.current_client_index = currentIndex
                file_list.update_index()
            }
        }

        ListView {
            id: file_list_view
            model: file_list
            SplitView.fillHeight: true
            SplitView.fillWidth: true
            SplitView.minimumWidth: 200

            ScrollBar.vertical: ScrollBar {}

            delegate: Item {
                implicitHeight: 20
                width: parent !== null ? parent.width : 0
                Rectangle {
                    color: {
                        if (file_list_view.currentIndex === index)
                        {
                            return "deepskyblue"
                        }
                        return index % 2 === 0 ? "whitesmoke" : "white"
                    }
                    height: parent.height
                    width: parent.width
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: display
                }


                Canvas {
                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width - 110
                    height: parent.height
                    width: 100
                    ProgressBar {
                        id: file_progress
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.height
                        width: 100
                        from: 0
                        to: 100
                        value: file_list.file_progress(index)
                        Connections {
                            target: file_list
                            function onFileProgress(i) {
                                if (i === index)
                                {
                                    file_progress.value = file_list.file_progress(i)
                                    update()
                                }
                            }
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        file_list_view.currentIndex = index
                    }
                }
            }
            focus: true
            onCurrentIndexChanged: {
                file_list.current_index = file_list_view.currentIndex
                file_list.update_progress()
            }
        }
    }
}
