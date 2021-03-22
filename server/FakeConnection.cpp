#include "FakeConnection.h"

#include <QRandomGenerator>

namespace
{
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

uint32_t generate_file_count()
{
    return s_rg.generate() % 91 + 10;
}

bool generate_online_status()
{
    return s_rg.generate() % 2 == 0;
}

uint32_t generate_file_progress()
{
    return s_rg.generate() % 101;
}

} // namespace

ClientEntry FakeConnection::create_client()
{
    ClientEntry entry(generate_random_name(6), generate_online_status());

    const uint32_t files_count = generate_file_count();
    for (uint32_t i = 0; i < files_count; ++i)
    {
        entry.files().push_back({generate_random_name(8), generate_file_progress()});
    }
    return entry;
}
