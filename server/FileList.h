#pragma once

#include "FileStorage.h"

#include <QAbstractListModel>
#include <QTimer>

class FileList : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(FileStorage *storage READ storage WRITE set_storage)
    Q_PROPERTY(quint32 current_index READ current_index WRITE set_current_index NOTIFY
                   on_current_index_changed)
public:
    FileList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    FileStorage *storage();
    void set_storage(FileStorage *s);

    Q_INVOKABLE quint32 file_progress(int index);

    Q_INVOKABLE void update_index();

    quint32 current_index();
    void set_current_index(quint32 index);

    Q_INVOKABLE void update_progress();

signals:

    void on_current_index_changed();
    void fileProgress(quint32 index);

private slots:
    void on_timer();

private:
    FileStorage *m_storage = nullptr;
    QVector<FileEntry> *m_files;
    quint32 m_current_index;
    QTimer m_timer;
};
