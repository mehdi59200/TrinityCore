#ifndef TRINITY_DBEDIT_SPELLPROPERTIES_H
#define TRINITY_DBEDIT_SPELLPROPERTIES_H

#include "SearchableDropdownDecl.h"
#include <QGroupBox>

class QLabel;
class QSpinBox;
class QStackedWidget;
struct SpellEntry;

class SpellProperties : public QGroupBox
{
    Q_OBJECT

    public:
        SpellProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);
        void BuildEntry(SpellEntry&) const;

    Q_SIGNALS:
        void ValueChanged();

    private Q_SLOTS:
        void PowerTypeChanged();

    private:
        PowerTypeDropdown*  _powerType;
        QStackedWidget*     _powerTypeSub;
        enum PowerTypePages { PAGE_REGULAR = 0, PAGE_RUNE = 1 };
        QSpinBox*           _manaCost;
        QLabel*             _manaCostPctPrefix;
        QSpinBox*           _manaCostPercentage;
        QLabel*             _manaCostPctSuffix;
        RuneCostDropdown*   _runeCost;

        uint32 _manaCostPerLevel;
};

#endif
