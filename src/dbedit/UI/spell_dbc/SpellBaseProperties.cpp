#include "SpellBaseProperties.h"
#include "DBCStructure.h"
#include "EnumUtils.h"
#include "Errors.h"
#include "QtHelpers.h"
#include "SearchableDropdown.h"
#include "StringFormat.h"
#include <QLabel>

void SpellBaseProperties::Setup()
{
    FIND_Q_CHILD_DELAYED(_spellId);
    FIND_Q_CHILD_DELAYED(_spellName);
    FIND_Q_CHILD_DELAYED(_spellRank);
    FIND_Q_CHILD_DELAYED(_spellFamily);

    /*for (SpellFamilyNames family : EnumUtils<SpellFamilyNames>::Iterate())
        _spellFamily->addItem(Trinity::QStringFormat("%u - %s", uint32(family), EnumUtils<SpellFamilyNames>::ToDescription(family)), uint32(family));*/
}

void SpellBaseProperties::SetEntry(SpellEntry const* entry)
{
    _spellId->setText(Trinity::QStringFormat("#%05u", entry->Id));
    _spellName->setText(entry->SpellName[0]);
    _spellRank->setText(entry->Rank[0]);
    _spellFamily->SetCurrentValue(SpellFamilyNames(entry->SpellFamilyName));
    /*int index = _spellFamily->findData(entry->SpellFamilyName);
    ASSERT(index >= 0);
    _spellFamily->setCurrentIndex(index);
    _spellFamily->setEnabled(false);*/
}
