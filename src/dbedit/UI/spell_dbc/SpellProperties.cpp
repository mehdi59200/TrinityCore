#include "SpellProperties.h"
#include "DBCStructure.h"
#include "Log.h"
#include "QtHelpers.h"
#include "SearchableDropdown.h"
#include <QSpinBox>
#include <QStackedWidget>

void SpellProperties::Setup()
{
    FIND_Q_CHILD_DELAYED(_powerType);
    FIND_Q_CHILD_DELAYED(_powerTypeSub);
    FIND_Q_CHILD_DELAYED(_manaCost);
    FIND_Q_CHILD_DELAYED(_manaCostPctPrefix);
    FIND_Q_CHILD_DELAYED(_manaCostPercentage);
    FIND_Q_CHILD_DELAYED(_manaCostPctSuffix);
    FIND_Q_CHILD_DELAYED(_runeCost);

    _manaCost->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    _manaCostPercentage->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

void SpellProperties::PowerTypeChanged()
{
    switch (_powerType->GetCurrentValue())
    {
        case POWER_RUNE:
            _powerTypeSub->setCurrentIndex(PAGE_RUNE);
            break;
        case POWER_RUNIC_POWER:
            _manaCostPctPrefix->hide();
            _manaCostPercentage->hide();
            _manaCostPctSuffix->hide();
            _powerTypeSub->setCurrentIndex(PAGE_REGULAR);
            break;
        default:
            _manaCostPctPrefix->show();
            _manaCostPercentage->show();
            _manaCostPctSuffix->show();
            _powerTypeSub->setCurrentIndex(PAGE_REGULAR);
    }
}

void SpellProperties::SetEntry(SpellEntry const* entry)
{
    _powerType->SetCurrentValue(Powers(entry->powerType));
    _manaCost->setValue(entry->manaCost);
    _manaCostPercentage->setValue(entry->ManaCostPercentage);
    _runeCost->SetCurrentKey(entry->runeCostID);
    _manaCostPerLevel = entry->manaCostPerlevel;
    PowerTypeChanged();
    CONNECT(_powerType, ValueChanged, this, PowerTypeChanged);
    CONNECT(_powerType, ValueChanged, this, ValueChanged);
    connect(_manaCost, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpellProperties::ValueChanged);
    connect(_manaCostPercentage, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpellProperties::ValueChanged);
    CONNECT(_runeCost, ValueChanged, this, ValueChanged);


    printf("Power type %u\n", entry->powerType);
    printf("Mana cost %u\n", entry->manaCost);
    printf("Mana cost / level %u\n", entry->manaCostPerlevel);
    printf("Mana cost %% %u\n", entry->ManaCostPercentage);
    printf("Rune cost ID %u\n", entry->runeCostID);
}

void SpellProperties::BuildEntry(SpellEntry& entry) const
{
    entry.powerType = _powerType->GetCurrentValue();
    entry.manaCost = _manaCost->value();
    entry.ManaCostPercentage = _manaCostPercentage->value();
    entry.runeCostID = _runeCost->GetCurrentKey();
    entry.manaCostPerlevel = _manaCostPerLevel;
}
