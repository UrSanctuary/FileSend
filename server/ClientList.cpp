#include "ClientList.h"

ClientList::ClientList()
{
}

int ClientList::rowCount(const QModelIndex &) const
{
    if (!m_storage)
    {
        return 0;
    }

    return m_storage->clients().size();
}

int ClientList::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant ClientList::data(const QModelIndex &index, int) const
{
    if (!m_storage)
    {
        return {};
    }
    if (index.row() < m_storage->clients().size())
    {
        return m_storage->clients().at(index.row()).name();
    }
    return {};
}

FileStorage *ClientList::storage()
{
    return m_storage;
}
void ClientList::set_storage(FileStorage *s)
{
    m_storage = s;
}

void ClientList::create_fake_client()
{
    if (!m_storage)
    {
        return;
    }
    auto &clients = m_storage->clients();
    beginInsertRows(QModelIndex(), clients.size(), clients.size());
    clients.push_back(m_connection.create_client());
    endInsertRows();
}
