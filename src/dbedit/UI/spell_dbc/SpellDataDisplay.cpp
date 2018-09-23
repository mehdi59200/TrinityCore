#include "SpellDataDisplay.h"
#include "DBCStructure.h"
#include "Errors.h"
#include "Log.h"
#include "QtHelpers.h"
#include "SharedDefines.h"
#include "SpellAccessor.h"
#include "SpellAttributes.h"
#include "SpellAuraProperties.h"
#include "SpellBaseProperties.h"
#include "SpellCasterProperties.h"
#include "SpellEffectProperties.h"
#include "SpellProperties.h"
#include "SpellSourceSelector.h"
#include "SpellTargetProperties.h"

void SpellDataDisplay::Setup()
{
    FIND_Q_CHILD_DELAYED(_sourceSelector);
    FIND_Q_CHILD_DELAYED(_baseProperties);
    FIND_Q_CHILD_DELAYED(_spellProperties);
    FIND_Q_CHILD_DELAYED(_auraProperties);
    FIND_Q_CHILD_DELAYED(_casterProperties);
    FIND_Q_CHILD_DELAYED(_targetProperties);
    FIND_Q_CHILD_DELAYED(_attributes);
    FIND_Q_CHILD_DELAYED(_effect0);
    FIND_Q_CHILD_DELAYED(_effect1);
    FIND_Q_CHILD_DELAYED(_effect2);

    _sourceSelector->Setup();
    _baseProperties->Setup();
    _spellProperties->Setup();
    _auraProperties->Setup();
    _casterProperties->Setup();
    _targetProperties->Setup();
    _attributes->Setup();
    _effect0->Setup();
    _effect1->Setup();
    _effect2->Setup();

    CONNECT(_sourceSelector, EntryChanged, this, Redraw);

    QSizePolicy sp = this->sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    this->setSizePolicy(sp);
}

void SpellDataDisplay::SetSpell(uint32 spellId)
{
    _sourceSelector->UpdateForSpell(spellId);
}

void SpellDataDisplay::Redraw()
{
    SpellEntry const* entry = _sourceSelector->GetCurrentSpellEntry();
    if (!entry)
    {
        this->hide();
        return;
    }
    TC_LOG_INFO("dbedit", "Selected spell: %u (%s)", entry->Id, SpellAccessor::GetSpellName(entry->Id).c_str());
    _baseProperties->SetEntry(entry);
    _spellProperties->SetEntry(entry);
    _auraProperties->SetEntry(entry);
    _casterProperties->SetEntry(entry);
    _targetProperties->SetEntry(entry);
    _attributes->SetEntry(entry);
    _effect0->SetEntry(entry, EFFECT_0);
    _effect1->SetEntry(entry, EFFECT_1);
    _effect2->SetEntry(entry, EFFECT_2);
}
