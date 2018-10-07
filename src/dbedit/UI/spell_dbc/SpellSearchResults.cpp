#include "SpellSearchResults.h"
#include "advstd.h"
#include "Containers.h"
#include "Errors.h"
#include "QtHelpers.h"
#include "SpellAccessor.h"
#include "SpellSearchResult.h"
#include "Util.h"
#include <map>
#include <vector>

// we can be destructive here, no downside, caller uses a temporary array
void SpellSearchResults::DoSearch(char* str)
{
    ASSERT(str && *str);

    this->clear();

    std::vector<char const*> needles;
    while (*str)
    {
        needles.push_back(str);
        while (*str && *str != ' ') ++str;
        while (*str && *str == ' ') *(str++) = '\0';
    }

    auto matches = Trinity::Containers::FuzzyFindIn(SpellAccessor::AllSpells(), needles, ValueContainsStringI<uint32>);
    if (matches.empty())
    {
        DoError("No matching spells found.");
        return;
    }

    uint8 i = 0;
    auto it = matches.begin(), end = matches.end();
    for (; i < MAX_RESULTS && it != end; ++it, ++i)
        this->addItem(new SpellSearchResult(it->second->first, it->second->second));

    if (size_t dist = std::distance(it, end))
    {
        QListWidgetItem* item = new QListWidgetItem(Trinity::QStringFormat("%zu more matches skipped...", dist));
        item->setFlags(Qt::NoItemFlags);
        this->addItem(item);
    }
}

void SpellSearchResults::DoError(char const* msg)
{
    this->clear();
    QListWidgetItem* item = new QListWidgetItem(msg);
    item->setFlags(Qt::NoItemFlags);
    this->addItem(item);
}
