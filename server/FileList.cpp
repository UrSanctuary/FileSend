#include "FileList.h"

FileList::FileList()
{
    for (int i = 1; i <= 50; ++i)
    {
        auto s = QString("file %1").arg(i);
        m_files.push_back(s);
    }
}

int FileList::rowCount(const QModelIndex &parent) const
{
    return m_files.size();
}

int FileList::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant FileList::data(const QModelIndex &index, int role) const
{
    if (index.row() < m_files.size())
    {
        return m_files.at(index.row());
    }
    return {};
}
