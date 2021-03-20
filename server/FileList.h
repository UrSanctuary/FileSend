#pragma once

#include <QAbstractListModel>

class FileList : public QAbstractListModel
{
    Q_OBJECT
public:
    FileList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList m_files;
};
