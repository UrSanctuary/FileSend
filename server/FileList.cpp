#include "FileList.h"

#include <QRandomGenerator>

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

FileList::FileList()
{
    QRandomGenerator rg;
    for (int i = 1; i <= 150; ++i)
    {
        auto s = QString("file %1").arg(i);
        m_files.push_back({s, rg.generate() % 101});
    }
}

int FileList::rowCount(const QModelIndex &) const
{
    return m_files.size();
}

int FileList::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant FileList::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return {};
    }
    if (index.row() >= m_files.size())
    {
        return {};
    }
    return m_files[index.row()].name();
}

quint32 FileList::file_progress(int index)
{
    if (index >= m_files.size())
    {
        return 0;
    }
    return m_files[index].progress();
}
