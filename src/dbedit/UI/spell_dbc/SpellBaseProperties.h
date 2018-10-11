#ifndef TRINITY_DBEDIT_SPELLBASEPROPERTIES_H
#define TRINITY_DBEDIT_SPELLBASEPROPERTIES_H

#include <QGroupBox>
#include "SearchableDropdownDecl.h"

class QLabel;
struct SpellEntry;

class SpellBaseProperties : public QGroupBox
{
    public:
        SpellBaseProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);

    private:
        QLabel*                 _spellId;
        QLabel*                 _spellName;
        QLabel*                 _spellRank;
        SpellFamilyDropdown*    _spellFamily;
};

#endif
