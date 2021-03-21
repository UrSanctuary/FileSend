#include "FileStorage.h"

ClientEntry::ClientEntry(const QString &name, bool is_online)
    : m_name(name)
    , m_is_online(is_online)
{
}

const QString &ClientEntry::name() const
{
    return m_name;
}

QVector<FileEntry> &ClientEntry::files()
{
    return m_files;
}

bool ClientEntry::is_online() const
{
    return m_is_online;
}

FileEntry::FileEntry(const QString &name, quint32 progress)
    : m_name(name)
    , m_progress(progress)
{
}

const QString &FileEntry::name() const
{
    return m_name;
}

quint32 FileEntry::progress() const
{
    return m_progress;
}

void FileEntry::update_progress()
{
    m_progress = (m_progress + 1) >= 100 ? 100 : m_progress + 1;
}

FileStorage::FileStorage()
{
}

QVector<ClientEntry> &FileStorage::clients()
{
    return m_clients;
}

quint32 FileStorage::current_client_index()
{
    return m_current_client_index;
}

void FileStorage::set_current_client_index(quint32 index)
{
    m_current_client_index = index;
}

QVector<FileEntry> &FileStorage::current_files()
{
    return m_clients[m_current_client_index].files();
}

bool FileStorage::is_client_online(quint32 index) const
{
    return index < static_cast<quint32>(m_clients.size()) && m_clients.at(index).is_online();
}
