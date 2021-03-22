#pragma once

#include <QObject>

class FileEntry
{
public:
    FileEntry(const QString &name, quint32 progress);

    const QString &name() const;
    quint32 progress() const;
    void update_progress();

private:
    QString m_name;
    quint32 m_progress;
};

class ClientEntry
{
public:
    ClientEntry(const QString &name, bool is_online = false);
    const QString &name() const;
    QVector<FileEntry> &files();
    bool is_online() const;

private:
    QString m_name;
    QVector<FileEntry> m_files;
    bool m_is_online;
};

class FileStorage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 current_client_index READ current_client_index WRITE set_current_client_index
                   NOTIFY on_current_client_index_changed)
public:
    FileStorage();

    QVector<ClientEntry> &clients();

    quint32 current_client_index();
    void set_current_client_index(quint32 index);

    QVector<FileEntry> &current_files();

    Q_INVOKABLE bool is_client_online(quint32 index) const;

signals:
    void on_current_client_index_changed();

private:
    QVector<ClientEntry> m_clients;
    quint32 m_current_client_index;
};
