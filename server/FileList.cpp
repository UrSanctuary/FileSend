#include "FileList.h"

#include <QRandomGenerator>

FileList::FileList()
    : m_files(nullptr)
{
    connect(&m_timer, &QTimer::timeout, this, &FileList::on_timer);
    m_timer.start(100);
}

int FileList::rowCount(const QModelIndex &) const
{
    if (!m_files)
    {
        return 0;
    }
    return m_files->size();
}

int FileList::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant FileList::data(const QModelIndex &index, int role) const
{
    if (!m_files || role != Qt::DisplayRole)
    {
        return {};
    }
    if (index.row() >= m_files->size())
    {
        return {};
    }
    return (*m_files)[index.row()].name();
}

quint32 FileList::file_progress(int index)
{
    if (!m_files || index >= m_files->size() || index < 0)
    {
        return 0;
    }
    return (*m_files)[index].progress();
}

FileStorage *FileList::storage()
{
    return m_storage;
}

void FileList::set_storage(FileStorage *s)
{
    m_storage = s;
}

void FileList::update_index()
{
    beginResetModel();
    m_files = &m_storage->current_files();
    endResetModel();
}

quint32 FileList::current_index()
{
    return m_current_index;
}
void FileList::set_current_index(quint32 index)
{
    m_current_index = index;
}

void FileList::update_progress()
{
}

void FileList::on_timer()
{
    if (!m_storage ||
        m_storage->current_client_index() >= static_cast<quint32>(m_storage->clients().size()) ||
        m_current_index >= static_cast<quint32>(m_storage->current_files().size()))
    {
        return;
    }
    m_storage->current_files()[m_current_index].update_progress();
    emit fileProgress(m_current_index);
}
