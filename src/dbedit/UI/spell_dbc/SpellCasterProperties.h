#ifndef TRINITY_DBEDIT_SPELLCASTERPROPERTIES_H
#define TRINITY_DBEDIT_SPELLCASTERPROPERTIES_H

#include <QGroupBox>

struct SpellEntry;

class SpellCasterProperties : public QGroupBox
{
    public:
        SpellCasterProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);
};

#endif
