#include "ClientList.h"

#include <QRandomGenerator>

QRandomGenerator s_rg(time(0));

QString generate_random_name(uint32_t len)
{
    QString name;
    static const unsigned char l = 'a';
    static const unsigned char h = 'z';

    for (uint32_t i = 0; i < len; ++i)
    {
        name.push_back(s_rg.generate() % (h - l + 1) + l);
    }
    return name;
}

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
    //    beginResetModel();
    beginInsertRows(QModelIndex(), clients.size(), clients.size());
    clients.push_back({generate_random_name(6), s_rg.generate() % 2 == 0});

    const uint32_t files_count = s_rg.generate() % 91 + 10;
    auto &client = clients.back();
    for (uint32_t i = 0; i < files_count; ++i)
    {
        client.files().push_back({generate_random_name(8), s_rg.generate() % 101});
    }
    endInsertRows();
    //    endResetModel();
}
