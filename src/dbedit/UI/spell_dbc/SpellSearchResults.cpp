#include "SpellSearchResults.h"
#include "advstd.h"
#include "Errors.h"
#include "FuzzyFind.h"
#include "QtHelpers.h"
#include "SearchableDropdown.h"
#include "SpellAccessor.h"
#include "SpellSearchResult.h"
#include "Util.h"
#include <map>
#include <vector>

// we can be destructive here, no downside, caller uses a temporary array
void SpellSearchResults::DoSearch(QString const& str)
{
    this->clear();

    QByteArray raw = str.toUtf8();

    std::vector<char const*> needles;
    std::vector<LabeledSearchTag> labels;
    SearchableDropdownBase::Tokenize(raw, needles, labels);
    
    auto matches = Trinity::Containers::FuzzyFindInMulti(SpellAccessor::AllSpells(), needles, ValueContainsStringI<uint32>, labels, KeyMatchesLabel<SpellEntry const*, std::string>);
    if (matches.empty())
    {
        this->clear();
        AddMessage("No matching spells found.");
        return;
    }

    AddMessage("== EXACT MATCHES ==");

    size_t max = needles.size() + labels.size();

    uint8 i = 0;
    auto it = matches.begin(), end = matches.end();
    for (; i < MAX_RESULTS && it != end; ++it, ++i)
    {
        if (max && it->first < max)
        {
            if (!i)
                AddMessage("No exact matches.");
            AddMessage("== PARTIAL MATCHES ==");
            max = 0;
        }
        this->addItem(new SpellSearchResult(it->second->first, it->second->second));
    }

    if (size_t dist = std::distance(it, end))
        AddMessage(Trinity::QStringFormat("%zu more skipped...", dist));
}

void SpellSearchResults::AddMessage(QString const& msg)
{
    QListWidgetItem* item = new QListWidgetItem(msg);
    item->setFlags(Qt::NoItemFlags);
    this->addItem(item);
}
