#ifndef TRINITY_DBEDIT_SPELLBASEPROPERTIES_H
#define TRINITY_DBEDIT_SPELLBASEPROPERTIES_H

#include <QGroupBox>

struct SpellEntry;

class SpellBaseProperties : public QGroupBox
{
    public:
        SpellBaseProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);
};

#endif
