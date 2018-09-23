#ifndef TRINITY_DBEDIT_SPELLAURAPROPERTIES_H
#define TRINITY_DBEDIT_SPELLAURAPROPERTIES_H

#include <QGroupBox>

struct SpellEntry;

class SpellAuraProperties : public QGroupBox
{
    public:
        SpellAuraProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);
};

#endif
