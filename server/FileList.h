#pragma once

#include <QAbstractListModel>

class FileEntry
{
public:
    FileEntry(const QString &name, quint32 progress);

    const QString &name() const;
    quint32 progress() const;

private:
    QString m_name;
    quint32 m_progress;
};

class FileList : public QAbstractListModel
{
    Q_OBJECT
public:
    FileList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE quint32 file_progress(int index);

private:
    QVector<FileEntry> m_files;
};
