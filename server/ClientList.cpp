#include "ClientList.h"

ClientList::ClientList()
{
    for (int i = 1; i <= 50; ++i)
    {
        auto s = QString("client %1").arg(i);
        m_clients.push_back(s);
    }
}

int ClientList::rowCount(const QModelIndex &parent) const
{
    return m_clients.size();
}

int ClientList::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ClientList::data(const QModelIndex &index, int role) const
{
    if (index.row() < m_clients.size())
    {
        return m_clients.at(index.row());
    }
    return {};
}
