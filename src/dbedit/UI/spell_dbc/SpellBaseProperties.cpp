#include "SpellBaseProperties.h"
#include "DBCStructure.h"
#include "EnumUtils.h"
#include "QtHelpers.h"
#include "StringFormat.h"
#include <QLabel>

void SpellBaseProperties::Setup()
{
    FIND_Q_CHILD_DELAYED(_spellId);
    FIND_Q_CHILD_DELAYED(_spellName);
    FIND_Q_CHILD_DELAYED(_spellRank);
    FIND_Q_CHILD_DELAYED(_spellFamily);
}

void SpellBaseProperties::SetEntry(SpellEntry const* entry)
{
    _spellId->setText(Trinity::QStringFormat("#%05u", entry->Id));
    _spellName->setText(entry->SpellName[0]);
    _spellRank->setText(entry->Rank[0]);
    if (uint32 family = entry->SpellFamilyName)
        _spellFamily->setText(EnumUtils<SpellFamilyNames>::ToName(SpellFamilyNames(family)));
    else
        _spellFamily->setText("");
}
