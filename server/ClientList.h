#pragma once

#include <QAbstractListModel>

class ClientList : public QAbstractListModel
{
    Q_OBJECT
public:
    ClientList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList m_clients;
};
