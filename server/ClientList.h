#pragma once

#include "FileStorage.h"

#include <QAbstractListModel>

class ClientList : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(FileStorage *storage READ storage WRITE set_storage)
public:
    ClientList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    FileStorage *storage();
    void set_storage(FileStorage *s);

    Q_INVOKABLE void create_fake_client();

private:
    FileStorage *m_storage = nullptr;
};
