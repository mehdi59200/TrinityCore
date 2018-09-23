#ifndef TRINITY_DBEDIT_SPELLEFFECTPROPERTIES_H
#define TRINITY_DBEDIT_SPELLEFFECTPROPERTIES_H

#include "Define.h"
#include <QWidget>

struct SpellEntry;
enum SpellEffIndex : uint8;

class SpellEffectProperties : public QWidget
{
    public:
        SpellEffectProperties(QWidget* parent = nullptr) : QWidget(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*, SpellEffIndex index);
};

#endif
