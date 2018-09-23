#include "SpellSourceSelector.h"
#include "Errors.h"
#include "Log.h"
#include "QtHelpers.h"
#include "SpellAccessor.h"
#include <QPushButton>

void SpellSourceSelector::Setup()
{
    FIND_Q_CHILD_DELAYED(_buttonLocal);
    FIND_Q_CHILD_DELAYED(_buttonDB);
    FIND_Q_CHILD_DELAYED(_buttonDBC);
}

void SpellSourceSelector::UpdateForSpell(uint32 spellId)
{
    _entryLocal = SpellAccessor::GetLocalSpellEntry(spellId);
    _entryDB = SpellAccessor::GetDBSpellEntry(spellId);
    _entryDBC = SpellAccessor::GetDBCSpellEntry(spellId);

    switch (_currentSource)
    {
        case SOURCE_NONE:
            _currentSource = SOURCE_LOCAL;
            // nobreak;
        case SOURCE_LOCAL:
            if (_entryLocal)
                break;
            _currentSource = SOURCE_DB;
            // nobreak;
        case SOURCE_DB:
            if (_entryDB)
                break;
            _currentSource = SOURCE_DBC;
            // nobreak;
        case SOURCE_DBC:
            if (_entryDBC)
                break;
            if (_entryDB)
            {
                _currentSource = SOURCE_DB;
                break;
            }
            if (_entryLocal)
            {
                _currentSource = SOURCE_LOCAL;
                break;
            }
            _currentSource = SOURCE_NONE;
            TC_LOG_ERROR("dbedit", "Spell %u selected, but has no data anywhere - huh?\n", spellId);

    }

    _buttonLocal->setEnabled(!!_entryLocal);
    _buttonDB->setEnabled(!!_entryDB);
    _buttonDBC->setEnabled(!!_entryDBC);
    _buttonLocal->setDown(_currentSource == SOURCE_LOCAL);
    _buttonDB->setDown(_currentSource == SOURCE_DB);
    _buttonDBC->setDown(_currentSource == SOURCE_DBC);

    Q_EMIT EntryChanged();
}

bool SpellSourceSelector::IsEditable() const
{
    return (_currentSource == SOURCE_LOCAL);
}

SpellEntry const* SpellSourceSelector::GetCurrentSpellEntry() const
{
    switch (_currentSource)
    {
        case SOURCE_LOCAL:
            return ASSERT_NOTNULL(_entryLocal);
        case SOURCE_DB:
            return ASSERT_NOTNULL(_entryDB);
        case SOURCE_DBC:
            return ASSERT_NOTNULL(_entryDBC);
        default:
            return nullptr;
    }
}
